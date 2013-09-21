#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
//1.bulid();
//2.query(a,b)
//3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 100055;
int sign[maxn<<2];
int sum[maxn<<2];
int n;
//根据题意做相关修改，询问时的操作 
int operate(int a,int b){
	return a+b;
}
void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void PushDown(int rt,int m) {
	if (sign[rt]) {
		sign[rt<<1] = sign[rt<<1|1] = sign[rt];
		sum[rt<<1] = (m - (m >> 1)) * sign[rt];
		sum[rt<<1|1] = (m >> 1) * sign[rt];
		sign[rt] = 0;
	}
}
void bulid(int l=1,int r=n,int rt=1){
	sign[rt] = 0;
	if(l==r){// 据题意做相关修改
		sum[rt]=1;return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}
void update(int L,int R,int add,int l=1,int r=n,int rt=1){
	if(L<=l && r<=R){// 据题意做相关修改
		sign[rt]=add;
			sum[rt]=(r-l+1)*add;return ;
	}
	PushDown(rt,r-l+1);
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , add , lson);
	if (R > m) update(L , R , add , rson);
	PushUp(rt);
}


int main()
{
	int t,m,x,y,z;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		bulid();
		while(m--){
			scanf("%d%d%d",&x,&y,&z);
			update(x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",i , sum[1]);
	}
	
	return 0;
}
