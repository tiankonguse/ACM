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
const int maxn = 200010;
int sum[maxn<<2];
int result[maxn];
int n;
pair<int,int> order[maxn];

int operate(int a,int b){
	return a+b;
}


void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}

void bulid(int l=1,int r=n,int rt=1){
	if(l==r){
		sum[rt]=1;return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}

void update(int p,int add,int l=1,int r=n,int rt=1){
	if(l==r){
		sum[rt]=0;
		result[l]=add;
		return ;
	}
	int m=(l+r)>>1;
	if(p<sum[rt<<1])update(p,add,lson);
	else update(p-sum[rt<<1],add,rson);
	PushUp(rt);
}

int main(){
	
	int tmp[maxn];
	while(~scanf("%d",&n)){
		bulid();

		for(int i=0;i<n;i++){
			scanf("%d%d",&order[i].first,&order[i].second);
		}
		for(int i=n-1;i>=0;i--){
			update(order[i].first,order[i].second);
		}
		for(int i=1;i<=n;i++){
			printf("%d%c",result[i],(i^n)?' ':'\n');
		}
		
	}

	return 0;
}
