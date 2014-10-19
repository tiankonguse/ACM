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
#else
typedef long long LL;
#endif
const int N = 300;
typedef unsigned char uchar;

int a,b,c, zero, one;

map<string,bool>bit;


struct T {
    vector<uchar>str;
    int n;
    int ans;
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
    }
    void print() {
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

bool haveString(const T& t) {
    char str[50];
    memset(str, 0, sizeof(str));
    toString(t, str);
    for(int i=0; i<38; i++) {
        str[i] |= (1<<7);
    }
    if(bit.find(str) == bit.end()) {
        bit[str] = 1;
        return false;
    } else {
        return true;
    }
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
    bit.clear();
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
//        printf("--\n");
//        now.print();

        tmpn = now.n;
        memset(have, false, sizeof(have));
        for(int i=0; i<now.n; i++) {
            have[now.str[i]] = 1;
        }

        now.ans++;

        for(int i=0; i<tmpn; i++) {
            for(int j=i+1; j<tmpn; j++) {
                tmpNAND = NAND(now.str[i], now.str[j]);

                if(have[tmpNAND]) {
                    continue;
                }
                have[tmpNAND] = true;

                newT = now;
                newT.add(tmpNAND);
//                newT.print();

                if(haveString(newT)) {
//                    printf("haveString ");
//                    newT.print();
                    continue;
                }

                if(tmpNAND == d) {
                    return now.ans;
                }
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
    for(uchar i=0; i<6; i++) {
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
