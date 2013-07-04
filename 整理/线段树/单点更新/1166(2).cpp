#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
//1.bulid();
//2.query(a,b)
//3.update(a,b)

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
int sum[maxn<<2];
int n;
//根据题意做相关修改，询问时的操作 
int operate(int a,int b){
	return a+b;
}
void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}

void bulid(int l=1,int r=n,int rt=1){
	if(l==r){
		// 据题意做相关修改
		scanf("%d",&sum[rt]);return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}

void update(int p,int add,int l=1,int r=n,int rt=1){
	if(l==r){
		// 据题意做相关修改
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


int main(){
	
	int t;

	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		printf("Case %d:\n",cas);
		scanf("%d",&n);
		bulid();
		char op[10];		
		while(scanf("%s",op),op[0]^'E'){
			int a,b;
			scanf("%d%d",&a,&b);
			if(op[0]=='Q')printf("%d\n",query(a,b));
			else if(op[0]=='S')update(a,-b);
			else update(a,b);
		}
	}

	return 0;
}
