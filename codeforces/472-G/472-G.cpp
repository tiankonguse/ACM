#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<ctime>
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

typedef unsigned uint;

const int N = 400100;


char str1[N];
char str2[N];

int p1,p2,len;
int q;

unsigned char A[N];
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

//第一个串直接转化为整数，8位已转换。
void bulidFirst(char *p) {
    memset(A,0,sizeof(A));
    for(int b=0,i=0; *p; ++p) {
        if(*p == '1') {
            A[i] |= (1<<b);
        }
        ++b;
        if(b == 8) {
            b = 0;
            i++;
        }
    }
}

//对于第二个串，由于比较位置不确定，由于8位已转换，所以需要储存8个串，偏移分别是0到7
void bulidsecond(char *p) {
    int j=0;
    int tail[8],index[8];
    for(; j<8; ++j) {
        memset(B[j],0,sizeof(B[j]));
        tail[j] = j;
        index[j] = 0;
    }
    bool o;
    for(int i=0; *p; ++p) {
        o = *p == '1';
        for(j=0; j<8; j++) {
            if(o) {
                B[j][index[j]] |= (1<< tail[j]);
            }
            tail[j]++;
            if(tail[j] == 8) {
                tail[j] = 0;
                index[j]++;
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
//第一个串的起始位置可能不在8位的的开端，多出的那几位单独处理
    int tail1 = p1 % 8;
    if(tail1) {
        tail1 = 8 - tail1;
    }


    while(tail1-- && p1 < end) {
        if(str1[p1++] != str2[p2++]) {
            ans++;
        }
        len--;
    }
    if(p1 >= end) {
        return ans;
    }

    //计算有几个uint整数
    int size = sizeof(uint) * 8;
    int num = len/size;


    //计算第一个数的偏移
    int index1 = p1 / 8;
    uint* a = (uint*)(A+index1);

    //计算第二个数的偏移
    int head = p2%8;
    if(head) {
        head = 8 - head;
    }
    int index2 = (p2 + 7)/8;
    uint* b = (uint*)(B[head] + index2);

//每次计算uint位（32）
    while(num--) {
        ans += _countbits(*a^*b);
        p1 += size;
        p2 += size;
        a++;
        b++;
    }
    //第一个串的最后可能还有不足32位的
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

int mygets(char* p, int maxLen=1000) {
    int len = rand()%maxLen;
    for(int i=0; i<len; i++) {
        p[i] = rand()%2 + '0';
    }
    p[len] = '\0';
    return len;
}

void readInt(int& i, int maxLen=1000) {
    if(maxLen == 0) {
        i=0;
    } else {
        i = rand()%maxLen;
    }

}

int main() {
    srand(time(NULL));
    int _p1,_p2,_len;
    int k = 5000;
    int test = 0;
    while(k--) {
        //printf("next test\n");
        int lenStr1 = mygets(str1,200010);
        bulidFirst(str1);
        //printf("%s\n",str1);

        int lenStr2 = mygets(str2,200010);
        bulidsecond(str2);
        //printf("%s\n",str2);

        readInt(q,400000);
        //printf("%d\n",q);
        while(q--) {
            test++;

            //printf("begin born p1,p2,len\n");
            readInt(p1, lenStr1);
            readInt(p2, lenStr2);
            readInt(len, min(lenStr1-p1, lenStr2-p2));
            //printf("begin while");
            _p1 = p1;
            _p2 = p2;
            _len = len;;
            if(test % 10000 == 0) {
                printf("next %d W test\n",test/10000);
                printf("p1=%d p2=%d len=%d str1=%d str2=%d\n",p1,p2,len,lenStr1,lenStr2);
            }
            //printf("p1=%d p2=%d len=%d str1=%d str2=%d\n",p1,p2,len,lenStr1,lenStr2);
            int ans1 = force();
            //printf("force = %d\n",ans1);
            int ans2 = solver();
            //printf("solver = %d\n",ans2);
            if(ans1 != ans2) {
                printf("ERROR --------------------\n");
                printf("%s\n",str1);
                printf("%s\n",str2);
                printf("%d %d %d\n",_p1,_p2,_len);
                printf("force = %d\n",ans1);
                printf("solver = %d\n",ans2);
                return 1;
                break;
            }
            //printf("end while\n");

        }
    }


    return 0;
}
