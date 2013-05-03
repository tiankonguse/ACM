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
struct e{
    int l,r,conut,size;
    void set(int l,int r,int c,int s){
		this->l=l;this->r=r;this->conut=c;this->size=s;
	}
}tree[N<<3];

void build(int l,int r,int p){
	tree[p].set(l,r,0,0);
    if(l<r-1)
    {
        int mid=(l+r)>>1;
        build(l,mid,2*p);
        build(mid,r,2*p+1);
    }
}
 
void insert(int l,int r,int p,int f){
    if(tree[p].l==l&&tree[p].r==r)
    {
        tree[p].conut++;
        if(tree[p].conut==1)
        {
                tree[p].size=map[f][r]-map[f][l];
        }
    }
    else
    {
        int mid=(tree[p].l+tree[p].r)>>1;
        if(r<=mid)
            insert(l,r,2*p,f);
        else
            if(l>=mid)
                insert(l,r,2*p+1,f);
            else
            {
                insert(l,mid,2*p,f);
                insert(mid,r,2*p+1,f);
            }
            if(tree[p].conut==0)
            {
                tree[p].size=tree[2*p].size+tree[2*p+1].size;
            }
    }
}
 
void delet(int l,int r,int p){
    if(tree[p].l==l&&tree[p].r==r)
    {
        tree[p].conut--;
        if(tree[p].conut==0)
            tree[p].size=tree[2*p].size+tree[2*p+1].size;
    }
    else
    {
        int mid=(tree[p].l+tree[p].r)>>1;
        if(r<=mid)
            delet(l,r,2*p);
        else
            if(l>=mid)
                delet(l,r,2*p+1);
            else
            {
                delet(l,mid,2*p);
                delet(mid,r,2*p+1);
            }
            if(tree[p].conut==0)
            {
                tree[p].size=tree[2*p].size+tree[2*p+1].size;
            }
    }
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
