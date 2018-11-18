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

const int N = 400100;

char str1[N];
char str2[N];

int p1,p2,len;
int q;

unsigned char A[8][N];
unsigned char B[8][N];

uint countbits(uint x) {
    uint mask[]= {0x55555555,0x33333333, 0x0F0F0F0F,
                  0x00FF00FF, 0x0000FFFF
                 };
    for(uint i=0,j=1; i<5; i++,j<<=1) {
        x=(x & mask[i]) + ((x>>j) & mask[i]);
    }
    return x;
}
unsigned _countbits(unsigned x) {
    unsigned n=0;
    while(++n , x&=x-1);
    return n;
}


void printfCharBit(unsigned char *p) {
    printf(" ");
    for(int i=0; i<8; i++) {
        printf("%d",(*p>>i)&1);
    }
}

void printBit(unsigned char *p, int n) {
    printf("char binary: ");
    while(n--) {
        printfCharBit(p);
        p++;
    }
    printf("\n");
}

void printIntBit(uint* p) {
    printf("int binary:");
    for(int i=0; i<32; i++) {
        printf("%d",(*p>>i)&1);
        if(i%8==7) {
            printf(" ");
        }
    }
    printf("\n");
}

void bulid(char *q, unsigned char A[8][N]) {
    int l = strlen(q);
    for(int j=0; j<8 && q[j]; j++) {
        char * p = q+j;
        for(int i=0,b=0; *p; p++) {
            if(*p ^ '0') {
                A[j][i] |= (1<<b);
            }
            ++b;
            if(b==8){
                b=0;
                i++;
            }
        }
    }
}


int solver() {
    if(len == 0) {
        return 0;
    }
    int ans = 0;

    int end = p1 + len;
    if(debug) {
        printf("end=%d\n",end);
    }
    int num = len/32;
    uint* a = (uint*)(A[p1&7]+(p1>>3));

    if(debug) {
        printBit((unsigned char*)a, 4);
        printIntBit(a);
    }
    uint* b = (uint*)(B[p2&7] + (p2>>3));
    if(debug) {
        printBit((unsigned char*)b, 4);
        printIntBit(b);

        printf("A=%x B[%d]=%x\n",A,p2&7,B);
        printf("a=%x b=%x\n",a,b);
        printf("p1=%d p2=%d\n",p1,p2);
        printf("begin int ans=%d\n",ans);
    }


    while(num--) {
        ans += countbits(*a++^*b++);
        p1 += 32;
        p2 += 32;
    }
    if(debug) {
        printf("end int ans=%d\n",ans);
        printf("p1=%d p2=%d\n",p1,p2);
        printf("a=%x b=%x\n",a,b);
    }

    while(p1 < end) {
        if(str1[p1++] != str2[p2++]) {
            ans++;
        }
    }

    return ans;
}



int force() {
    int ans = 0;
    for(int i=0; i<len; i++) {
        if(str1[p1+i] ^ str2[p2+i]) {
            ans++;
        }
    }
    return ans;
}



/*
11001000001111111010100100100110101011101
10011111100100000000010100011011000000100
123
0 0 41
              11001000 00111111 10101001 00100110 101011101
              10011111 10010000 00000101 00011011 000000100

char binary:  00110111 01100000 00010101 10011011
int binary:   00110111 01100000 00010101 10011011
char binary:  10011111 01001000 00000001 01000011
int binary:   10011111 01001000 00000001 01000011



10111001110110000101100100010001111000110000110100011111010101010111
11110000010100111101010110011111100110001000101110101111101010101101
1
31 7 36


1011111011011111110000011101100101011010100100111001111000011
000001000110010100000011101101100110111110000101001001100111011111010101000001101110
24 36 36
force = 14
solver = 20
*/
int main() {
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));

    scanf("%s",str1);
    scanf("%s",str2);
    bulid(str1,A);
    bulid(str2,B);

    scanf("%d",&q);
    while(q--) {
        scanf("%d%d%d",&p1,&p2,&len);
        //printf("force=%d\n",force());
        //printf("solver=%d\n",solver());
        printf("%d\n",solver());
    }

    return 0;
}
