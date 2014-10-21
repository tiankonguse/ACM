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
    int start;
    bool operator<(const T t)const {
        return ans > t.ans;
    }
    void add(uchar a) {
        str.push_back(a);
        n++;
    }
    void pop(){
        str.pop_back();
        n--;
    }
    void init() {
        str.clear();
        n = 0;
        start = 0;
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

const int MIN_LEV = 8;

int dfs(T& now, int lev, int d, int& ans) {
    if(ans != -1 && ans <= now.ans+lev) {
        now.pop();
        return -1;
    }
    if(now.ans+lev > 11) {
        now.pop();
        return -1;
    }
    bool have[N];
    memset(have, false, sizeof(have));
    for(int i=0; i<now.n; i++) {
        have[now.str[i]] = 1;
    }
    int tmpNAND;
    int tmpAns;
    for(int i=now.start; i<now.n; i++) {
        for(int j=0; j<i; j++) {
            tmpNAND = NAND(now.str[i], now.str[j]);
            if(tmpNAND == d) {
                now.pop();
                return now.ans  + lev;
            }

            if(have[tmpNAND]) {
                continue;
            }
            have[tmpNAND] = true;
            now.add(tmpNAND);
            now.start = i;
            tmpAns = dfs(now, lev+1,d, ans);
            if(tmpAns != -1) {
                if(ans == -1) {
                    ans = tmpAns;
                } else {
                    ans = min(ans,tmpAns);
                }
            }

        }
    }
    now.pop();
    return ans;
}

int getAns(uchar d) {
    bool have[N];
    int ans = -1,tmpAns;
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

        for(int i=now.start; i<tmpn; i++) {
            for(int j=0; j<i; j++) {
                tmpNAND = NAND(now.str[i], now.str[j]);

                if(have[tmpNAND]) {
                    continue;
                }
                have[tmpNAND] = true;

                newT = now;
                newT.add(tmpNAND);
                newT.start = i;
//                newT.print();

                if(haveString(newT)) {
//                    printf("haveString ");
//                    newT.print();
                    continue;
                }

                if(tmpNAND == d) {
                    return now.ans;
                }

                if(newT.ans > MIN_LEV) {
                    if(ans == newT.ans+1){
                        continue;
                    }
                    tmpAns = dfs(newT, 1, d, ans);
                    if(tmpAns != -1) {
                        if(ans == -1) {
                            ans = tmpAns;
                        } else {
                            ans = min(ans, tmpAns);
                        }
                    }

                } else {
                    que.push(newT);
                }
            }
        }
    }
    return ans;
}



char* setInput(char*input, int a) {
    for(int i=0; i<8; i++) {
        input[7-i] = '0' + ((a>>i)&1);
    }
    input[8] = 0;
    return input;
}

char* getTime( char* input) {
    struct tm *ptm;
    time_t nowtime;
    nowtime = time(NULL);
    ptm=localtime(&nowtime);
    sprintf(input, "%02d:%02d:%02d", ptm->tm_hour ,ptm->tm_min ,ptm->tm_sec);
    return input;
}

int main() {
    freopen("test5.out","w",stdout);
    char input[10];
    a =    toUchar("00001111");
    b =    toUchar("00110011");
    c =    toUchar("01010101");
    zero = toUchar("00000000");
    one =  toUchar("11111111");
    first.init();
    //104 01101000
//    printf("%s\n",setInput(input, 104));
    for(uchar i=0; i<255; i++) {
        printf("begin at %s\n", getTime(input));
        printf("%3d=%d %s\n",i,getAns(i), setInput(input, i));
        printf("end at %s\n", getTime(input));
        printf("\n");
    }
    printf("begin at %s\n", getTime(input));
    printf("%3d=%d %s\n",255,getAns(255), setInput(input, 255));
    printf("end at %s\n", getTime(input));
    printf("\n");
    return 0;
//00010011
    scanf("%s",input);
    while(~scanf("%s",input)) {
        printf("%d\n",getAns(toUchar(input)));
    }
    return 0;
}
