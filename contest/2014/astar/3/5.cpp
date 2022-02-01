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

LL kgcd(LL a,LL b) {
    if(!a || !b)return a?a:b;
    if(!(a&1) && !(b&1))return kgcd(a>>1,b>>1)<<1;
    if(!(b&1))return kgcd(a,b>>1);
    if(!(a&1))return kgcd(a>>1,b);
    return kgcd(b,a%b);
}


struct T {
    LL up,down;
    void init(LL u, LL d) {
        LL tmp = kgcd(u,d);
        up = u/tmp, down = d/tmp;
    }
} dp[30],ans[3];
int kmp_next[30];
int str_next[30];
char str[30];

void get_kmp_next(int*next, char *pat) {
    memset(next,-1,sizeof(next));
    for(int i=1,k; pat[i]; ++i) {
        for(k=next[i-1]; k>=0 && pat[i]!=pat[k+1]; k=next[k]);
        if(pat[k+1] == pat[i])next[i]=k+1;
    }
}

void get_src_next(int*next, char *pat) {
    memset(next,-1,sizeof(next));
    for(int i=1,k; pat[i]; ++i) {
        for(k=kmp_next[i-1]; k>=0 &&  pat[i] == pat[k+1]; k=kmp_next[k]);
        if(pat[k+1] != pat[i])next[i] = k+1;
    }
}

void getAns(T& ans) {
    int n = strlen(str);

    get_kmp_next(kmp_next, str);
    get_src_next(str_next, str);
    dp[0].init(1,2);
    for(int i=1;str[i];i++){
		dp[]
    }



}



int main() {
    int t,T;


    scanf("%d",&T);
    for(t=1; t<=T; t++) {
        scanf("%s",str);
        getAns(ans[0]);

        printf("Case #%d:\n",t);
    }
    return 0;
}
