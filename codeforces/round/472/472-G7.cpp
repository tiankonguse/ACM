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
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;

const int N = 400100;
const int OneNumMax = 1<<16;
char str1[N];
char str2[N];

int p1,p2,len,q;
int ans = 0;
uint* a;
uint* b;
uchar A[8][N];
uchar B[8][N];
int oneNum[OneNumMax];

void bulid(const char * const q, uchar A[32][N]) {
    int l = strlen(q);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; i + j < l; j++) {
            if(q[i+j] == '1') {
                A[i][j>>3] |= (1U << (j & 7));
            }
        }
    }
}

inline uint countbits(uint x) {
    return oneNum[x >> 16] + oneNum[x & ((1 << 16) - 1)];
}

int solver() {
    ans = 0;
    a = (uint*)(A[p1&7] + (p1>>3));
    b = (uint*)(B[p2&7] + (p2>>3));
    while(len >= 32) {
        ans += countbits(*a++ ^ *b++);
        len -= 32;
    }
    ans += countbits((*a ^ *b) & ((1U << len) - 1));
    return ans;
}

int main() {
    int q;
    for(int i = 1; i < OneNumMax; ++i) {
        oneNum[i] = oneNum[i >> 1] + (i & 1);
    }

    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));

    scanf("%s",str1);
    scanf("%s",str2);
    bulid(str1,A);
    bulid(str2,B);
    scanf("%d",&q);
    while(q--) {
        scanf("%d%d%d",&p1,&p2,&len);
        printf("%d\n",solver());
    }

    return 0;
}
