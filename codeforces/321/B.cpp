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
const int N = 100100;

typedef struct Node {
    LL m;
    LL s;
    bool operator<(const Node &t2)const {
        return this->m < t2.m;
    }
} Node;
Node friends[N];

int main() {

    int n;
    LL d;
    scanf("%d%lld",&n,&d);
    for(int i=0; i<n; i++) {
        scanf("%lld%lld", &friends[i].m, &friends[i].s);
    }
    sort(friends, friends + n);

    int left;
    int right;
    LL ans;
    LL now;

    left = 0;
    right = 1;
    ans = friends[left].s;
    now = friends[left].s;
    //printf("m=%lld s=%lld\n",  friends[0].m, friends[0].s);

    for(; right < n; right++) {
        //printf("m=%lld s=%lld\n",  friends[right].m, friends[right].s);
        while(friends[left].m + d <=  friends[right].m ) {
            now = now - friends[left].s;
            left = left + 1;
        }
        now = now + friends[right].s;

        if(now > ans) {
            ans = now;
        }
    }

    printf("%lld\n",ans);


    return 0;
}
