/*
#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<stdlib.h>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long LL;

LL extgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){x=1,y=0;return a;}
	LL d=extgcd(b,a%b,x,y);
	LL t=x;x=y;y=t-a/b*y;
	return d;
}
LL modeq(LL a,LL b,LL n){
	LL d,x,y;
	d=extgcd(a,n,x,y);
	if(b%d)return -1;
	return (b/d*x%n + n)%(n/d);
}
int main()
{
	LL n,d,x,y,ans;
	int tt;
	scanf("%d",&tt);
	while(tt--){
		scanf("%lld%lld%lld%lld",&n,&d,&x,&y);
		x=(y-x+n)%n;
		LL ans=modeq(d,x,n);
		if(ans==-1){
			printf("Impossible\n");
		}else{
			printf("%lld\n",ans);
		}

	}
	return 0;
}
