/*************************************************************************
    > File Name: Witua and Math.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/3 18:42:04
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

typedef long long LL;
const int S=20;

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

LL pow_mod(LL x,LL n,LL mod){
  if (n==1) return x%mod;
    int bit[64],k=0;
    while (n){
        bit[k++]=n&1;n>>=1;
    }
    LL ret=1;
    for (k=k-1;k>=0;k--){
        ret=muti_mod(ret,ret,mod);
        if (bit[k]==1) ret=muti_mod(ret,x,mod);
    }
    return ret;
}

//以a为基，n-1=x*2^t，
bool check(LL a,LL n,LL x,LL t){
    LL ret=pow_mod(a,x,n),last=ret;
    for (int i=1;i<=t;i++){
        ret=muti_mod(ret,ret,n);
        if (ret==1 && last!=1 && last!=n-1) return 1;
        last=ret;
    }
    if (ret!=1) return 1;
    return 0;
}
bool Miller_Rabin(LL n){
//    printf("%d>",n);
    LL x=n-1,t=0;
    while ((x&1)==0) x>>=1,t++;
    bool flag=1;
    if (t>=1 && (x&1)){
        for (int k=0;k<S;k++){//s=20
//            printf("-");
            LL a=rand()%(n-1)+1;
            if (check(a,n,x,t)) {flag=1;break;}
            flag=0;
        }
    }
    if (!flag || n==2) return 0;
  return 1;
  }

int main() {
    LL n,left;
    int t;
    srand((unsigned)time(NULL));
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        while(Miller_Rabin(n))n--;
        printf("%lld\n",n);
    }





    return 0;
}
