#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
typedef  unsigned __int64  ULL;
#else
typedef long long LL;
typedef unsigned long long ULL;
#endif


ULL mitHeakArray[3];
bool okMitHeak = false;
int initMitHeakArray() {
    if(okMitHeak) {
        return true;
    }
    ULL a = 011ULL, b = 033ULL, c = 07ULL;
    for(int i=0; i<11; i++) {
        a = (a << 6) | 011ULL;
        b = (b << 6) | 033ULL;
        c = (c << 6) | 07ULL;
    }
    mitHeakArray[0] = a;
    mitHeakArray[1] = b;
    mitHeakArray[2] = c;
    okMitHeak = true;
    return 0;

}
int bitCount ( ULL n ) {
    static int a = initMitHeakArray();
    ULL tmp = n - ((n >> 1) & mitHeakArray[1]) - ((n >> 2) & mitHeakArray[0]);
    return ( (tmp + (tmp >> 3) ) & mitHeakArray[2]) % 63;
}



int _countbits(ULL x) {
    int n=0;
    while(x && (++n , x&=x-1));
    return n;
}

const int OneNumMax = 1<<16;
ULL oneNum[OneNumMax];

int init() {
    for(int i = 1; i < OneNumMax; ++i) {
        oneNum[i] = oneNum[i >> 1] + (i & 1);
    }
    return 0;
}

int countbits(ULL x) {
    static int a = init();
    return oneNum[x & ((1ULL << 16) - 1)] + oneNum[(x >> 16) & ((1ULL << 16) - 1)] + oneNum[(x >> 32) & ((1ULL << 16) - 1)] + oneNum[(x >> 48) & ((1ULL << 16) - 1)];
}

int main() {
    ULL a;
    initMitHeakArray();
    int m = (64+2)/3;
    printf("width = %d\n",m);
    for(int j=0; j<3; j++) {
        for(int i=m-1; i>=0; i--) {
            printf("%d",i%10);
        }
        printf(" ");

    }
    printf("\n");
    printf("%22llo %22llo %22llo\n", mitHeakArray[0],mitHeakArray[1],mitHeakArray[2]);
    ULL ans[2];
    ULL cas = 0;
    ULL MOD = 10000;
    ULL limit = 10;
    while(1){
            cas++;
        a = rand();
        a = a*a;
        ans[0] = bitCount(a);
        ans[1] = _countbits(a);
        ans[2] = countbits(a);

        if(ans[0] != ans[1] || ans[0] != ans[2]){
            printf("%llu: bitCount = %d _countbits = %d table = %d\n", a, ans[0], ans[1], ans[2]);
            break;
        }
        if(cas % MOD == 0){
            printf("case : %llu * %llu\n", cas/MOD, MOD);
        }
        if(cas / MOD >= limit){
            printf("finish");
            break;
        }
    }
    return 0;
}
