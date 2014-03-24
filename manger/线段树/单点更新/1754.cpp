#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 220000;
int sum[maxn<<2];
int n;

int operate(int a,int b){
	return max(a,b);
}

void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}

void bulid(int l=1,int r=n,int rt=1){
	if(l==r){
		scanf("%d",&sum[rt]);return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}

void update(int p,int add,int l=1,int r=n,int rt=1){
	if(l==r){
		sum[rt]=add;return ;
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
	int ans=0;
	if(L<=m)ans=operate(ans,query(L,R,lson));
	if(R> m)ans=operate(ans,query(L,R,rson));
	return ans;
}


int main(){
	
	int m;
	while(~scanf("%d%d",&n,&m)){
		bulid();
		char op[2];		
		while(m--){
			int a,b;
			scanf("%s%d%d",op,&a,&b);
			if(op[0]=='Q')printf("%d\n",query(a,b));
			else update(a,b);
		}
	}

	return 0;
}
