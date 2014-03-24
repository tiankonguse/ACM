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
const int maxn = 5500;
int sum[maxn<<2];
int n;

int operate(int a,int b){
	return a+b;
}


void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}

void bulid(int l=1,int r=n,int rt=1){
	if(l==r){
		sum[rt]=0;return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}

void update(int p,int add=1,int l=1,int r=n,int rt=1){
	if(l==r){
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
	int ans=0;
	if(L<=m)ans=operate(ans,query(L,R,lson));
	if(R> m)ans=operate(ans,query(L,R,rson));
	return ans;
}


int main(){
	
	int tmp[maxn];
	while(~scanf("%d",&n)){
		bulid();
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp[i]);tmp[i]++;
			sum+=query(tmp[i],n);
			update(tmp[i]);
		}
		int ret=sum;
		for(int i=0;i<n;i++){
			sum+=n-(tmp[i]<<1)+1;
			ret=min(ret,sum);
		}
		printf("%d\n",ret);
		
	}

	return 0;
}
