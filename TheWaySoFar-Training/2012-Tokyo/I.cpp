#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
int a[100000];
LL sum[100000];
int n,m;
int bo1[50001],bo2[50001],f[50001];

int check(int ans){
	memset(bo1,0,sizeof(bo1));
	memset(bo2,0,sizeof(bo2));
	memset(f,0,sizeof(f));
	f[0]=1;
	int p1=0,p2=0,ans1=0;
	for (int i=1; i<=n; ++i){
		while (p1<i && sum[i]+(LL)i*ans>=sum[p1]+(LL)p1*ans+m+ans){
			bo1[p1]=1;
			if (bo1[p1] && !bo2[p1] && f[p1]) ++ans1;
			++p1;
		}
		while (p2<i && sum[i]+i>sum[p2]+p2+1+m) {
			bo2[p2]=1;
			if (bo1[p2] && f[p2]) --ans1;
			++p2;
		}
		if (ans1) f[i]=1;
	}
	for (int i=0; i<=n; ++i)
		if (f[i] && (sum[n]-sum[i]+n-i-1)<=m) return 1;
	return 0;
}

int main(){
	while (scanf("%d%d",&m,&n), n>0 || m>0){
		for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
		memset(sum,0,sizeof(sum));
		for (int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
		int head=0,tail=m;
		while (head<tail-1){
			int mid=(head+tail)>>1;
			if (check(mid)) tail=mid;
			else head=mid;
			//printf("%d %d\n",head,tail);
		}
		printf("%d\n",tail);
	}
}
