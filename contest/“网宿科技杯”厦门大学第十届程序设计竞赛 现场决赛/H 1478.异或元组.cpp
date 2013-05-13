/*************************************************************************
    > File Name: H 1478.异或元组.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 14:10:41
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

typedef long long LL;

LL getBit(LL a){
    LL k=0;
    while(a){
        a>>=1,k++;
    }
    return k-1;
}


int main() {
//    LL a = 2000000000;
//    printf("%lld %lld\n",a,(LL)(log10(a)/log10(2)));

    LL n,ans,bit,b,k,i;
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%lld",&n);
        bit = 1;
        k = getBit(n);
//        if(n==8){
//            k=3;
//        }
//        printf("%d--\n",k);
        bit <<= k;
        b = n - bit;
        ans = (1+b)*b/2;
//        printf("%lld %lld  %lld--",ans,b,k);
        bit = 1;
        for(i=0;i<k;i++){
            ans += (bit>>1) *(bit-1);
            bit <<=1;
        }

        printf("%lld\n",ans);
    }


    return 0;
}
