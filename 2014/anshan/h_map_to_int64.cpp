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
#include <time.h>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
typedef unsigned __int64 ULL;
#else
typedef long long LL;
typedef unsigned long long ULL;
#endif
const int N = 300;
typedef unsigned char uchar;
const int bitLen=4;
ULL bit[bitLen];


int a,b,c, zero, one;


struct T {
    vector<uchar>str;
    int n;
    int ans;
    int start;
    bool operator<(const T t)const {
        return ans > t.ans;
    }
    void add(uchar a) {
        str.push_back(a);
        n++;
    }
    void init() {

        str.clear();
        n = 0;
        ans = 1;
        add(a);
        add(b);
        add(c);
        add(one);
        add(zero);
        start = 0;
    }
    void print() const{
        printf("ans=%d",ans);
        for(int i=0; i<n; i++) {
            printf(" %3d",str[i]);
        }
        printf("\n");
    }
} first;

priority_queue<T> que;

uchar toUchar(const char*  str) {
    uchar ans = 0;
    while(*str) {
        ans = (ans<<1) | (*str++ -'0');
    }
    return ans;
}

inline uchar NAND(uchar a, uchar b) {
    return ~(a&b);
}

void toString(const T&t, char* str) {
    int now;
    for(int i=0; i<t.n; i++) {
        now = t.str[i];
        str[now/7] |= 1<<(now % 7);
    }
}
void print(ULL bit){
    for(int i=0;i<64;i++){
        printf("%d",(bit>>i)&1);
    }
    printf("\n");
}

void print(ULL* bit) {
    for(int i=0; i<bitLen; i++) {
        print(bit[i]);
    }
    printf("\n");
}

void toBit(const T&t, ULL* bit) {
    int now;
    ULL one = 1;
    for(int i=0; i<t.n; i++) {
        now = t.str[i];
        bit[now>>6] |= (one<<(now & 63));
    }
}

void initBit(ULL* bit) {
    for(int i=0; i<bitLen; i++) {
        bit[i] = 0;
    }
}



void setBit(const T&t, ULL* bit) {
    ULL str[bitLen];
    initBit(str);
    toBit(t, str);
    for(int i=0; i<bitLen; i++) {
        bit[i] |= str[i];
    }
}


bool haveString(const T& t) {
    ULL str[bitLen];

    initBit(str);

    toBit(t, str);


    for(int i=0; i<bitLen; i++) {
        if((bit[i]  & str[i]) != str[i]) {
            bit[i] |= str[i];
            return false;
        }
    }

    print(bit);
    printf("\n");
    t.print();
    print(str);
    return true;
}

int getAns(uchar d) {
    bool have[N];
    memset(have, false, sizeof(have));
    for(int i=0; i<first.n; i++) {
        have[first.str[i]] = 1;
    }

    if(have[d]) {
        return 1;
    }

    initBit(bit);
    setBit(first, bit);


    while(!que.empty()) {
        que.pop();
    }
    que.push(first);
    haveString(first);

    T now, newT;
    int tmpn;
    int tmpNAND;

    while(!que.empty()) {
        now = que.top();
        que.pop();

        printf("--\n");
        now.print();

        tmpn = now.n;
        memset(have, false, sizeof(have));
        for(int i=0; i<now.n; i++) {
            have[now.str[i]] = 1;
        }

        now.ans++;

        if(now.ans > 4){
            break;
        }

        for(int i=0; i<tmpn; i++) {
            for(int j=0; j<i; j++) {
                tmpNAND = NAND(now.str[i], now.str[j]);

                if(have[tmpNAND]) {
                    continue;
                }
                have[tmpNAND] = true;

                newT = now;
                newT.add(tmpNAND);

//                newT.print();

                if(haveString(newT)) {
                    printf("haveString ");
                    newT.print();
                    return -1;
                    continue;
                }

                if(tmpNAND == d) {
                    return now.ans;
                }
                newT.start = tmpn;
                que.push(newT);

            }
        }
    }
    return -1;
}

char* setInput(char*input, int a) {
    for(int i=0; i<8; i++) {
        input[7-i] = '0' + ((a>>i)&1);
    }
    input[8] = 0;
    return input;
}

int main() {
    struct tm *ptm;
    time_t nowtime;

    char input[10];
    a =    toUchar("00001111");
    b =    toUchar("00110011");
    c =    toUchar("01010101");
    zero = toUchar("00000000");
    one =  toUchar("11111111");
    first.init();
    printf("00010011 => %d\n",toUchar("00010011"));

    //41 97 104 105 109 134 146 148 150 151 214
    //104
    //214
    int test[12] = {41,97,150,151,214,104};
    for(int i=0; i<11; i++) {
//        printf("%3d %s\n",test[i], setInput(input, test[i]));
    }
    printf("%3d=%d %s\n",19,getAns(19), setInput(input, 19));
    for(uchar i=0; i<6; i++) {
        break;
        nowtime = time(NULL);
        ptm=localtime(&nowtime);
        printf("begin at %02d:%02d:%02d\n", ptm->tm_hour ,ptm->tm_min ,ptm->tm_sec);

        printf("%3d=%d %s\n",test[i],getAns(test[i]), setInput(input, test[i]));

        nowtime = time(NULL);
        ptm=localtime(&nowtime);
        printf("end at %02d:%02d:%02d\n\n", ptm->tm_hour ,ptm->tm_min ,ptm->tm_sec);

    }
//00010011
    scanf("%s",input);
    while(~scanf("%s",input)) {
        printf("%d\n",getAns(toUchar(input)));
    }
    return 0;
}
