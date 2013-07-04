#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int N=5010;
const int Max=10000;

bool have[2][Max*2+1];
int map[2][Max+1];
int sum[(N=10)<<2][2];
int n;
struct TT{
	int l,r,sign,val;
    void set(int l,int r,int sign,int val){
		this->l=l;this->r=r;this->sign=sign;this->val=val;
	}
}xy[2][Max+1];

int cmp(const TT a,const TT b){
    return a.val-b.val;
}

//根据题意做相关修改，询问时的操作 
int operate(int a,int b){
return a+b;
}
void PushUp(int rt){
sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void bulid(int l=1,int r=n,int rt=1){
	sum[rt][0]=sum[rt][1]=0;
	if(l==r){// 据题意做相关修改
		return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
}
void update(int p,int add,int l=1,int r=n,int rt=1){
	if(l==r){// 据题意做相关修改
			sum[rt]+=add;return ;
	}
	int m=(l+r)>>1;
	if(p<=m)update(p,add,lson);
	else update(p,add,rson);
	PushUp(rt);
}

int query(int L,int R,int l=1,int r=n,int rt=1){
	if(L<=l && r<=R){
		return sum[rt];
	}
	int m=(l+r)>>1;
	int ret=0;
	if(L<=m)ret=operate(ret,query(L,R,lson));
	if(R> m)ret=operate(ret,query(L,R,rson));
	return ret;
}
void add(int m,int sign,int &num){
	
	m+=Max;
	
	if(!have[sign][m]){
		have[sign][m]=1;
		map[sign][++num]=m;
	}
}
 
void read(){
	
    int i,j;
    int num[2]={0,0};
    int x1,y1,x2,y2;
    
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
		
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        
        //0为x扫描线,1为y扫描线 
        add(x1,0,num[0]);
        add(x2,0,num[0]);
        add(y1,1,num[1]);
        add(y2,1,num[1]);
        
        //0为进入矩阵,1为走出矩阵 
        xy[0][2*i-1].set(y1,y2,0,x1);
        xy[0][2*i  ].set(y1,y2,1,x2);
        xy[1][2*i-1].set(x1,x2,0,y1);
        xy[1][2*i  ].set(x1,x2,1,y2);

    }
    
 

    int ans=0;
    
    for(int k=0;k<2;k++){
		build(1,num[k],1);
	    sort(xy[k]+1,xy[k]+1+2*n,cmp);    
	    sort(map[k]+1,map[k]+n+1);
	    for(i=1;i<=num[k];i++)
			have[k][map[k][i]]=i;  
					
	    for(j=0,i=1;i<=2*n;i++)
	    {
	        if(xy[k][i].sign==0)
	            insert(have[k][xy[k][i].l+Max],have[k][xy[k][i].r+Max],1,0);
	        else
	            delet(have[k][xy[k][i].l+Max],have[k][xy[k][i].r+Max],1);
	        ans+=abs(tree[1].size-j);
	        j=tree[1].size;
	    }
	}

    cout<<ans<<endl;
}

int main()
{
	read();
	return 0;
}
