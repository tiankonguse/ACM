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
typedef __int64 LL;
const int N =150000;
LL fac[N];

LL muti_mod(LL a,LL b,LL c){        
	a%=c;b%=c;
    LL ret=0;
    while (b){
        if (b&1){
            ret+=a;
            if (ret>=c) ret-=c;
        }
        a<<=1;
        if (a>=c) a-=c;
        b>>=1;
    }
    return ret;
}
LL pow_mod(LL a,LL b,LL c){     
	if (b==1) return a%c;
	LL ret=1,d=a;
	while(b){
		if(b&1)ret=muti_mod(ret,d,c);
		d=muti_mod(d,d,c);
		b>>=1;
	}
    return ret;
}


LL cmodp(int n,int m,int p){
	LL x,y,a;
	if(m>n)return 0;
	LL b=muti_mod(fac[n-m],fac[m],p);
	a=fac[n];
	return muti_mod(pow_mod(b,p-2,p),a,p);
	
}


LL lucas(LL n,LL m,LL p){
	LL ans=1;
	fac[0]=1;
	for(int i=1;i<=p;i++){
		fac[i]=muti_mod(fac[i-1],i,p);
	}
	while(m){
		ans=muti_mod( cmodp(n%p,m%p,p) , ans , p);
		n/=p;m/=p;
	}
	return ans;
}

int main()
{
	int t=1;
	LL n,k,p;
	while(~scanf("%I64d%I64d%I64d",&n,&k,&p)){
		printf("Case #%d: %I64d\n",t++,(lucas(n+1+k,k,p)+n-k)%p);
	}
	
	
	return 0;
}
