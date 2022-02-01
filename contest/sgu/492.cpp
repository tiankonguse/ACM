#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 605
LL K;
LL f[20][3];
int digit[20];

LL dfs(int pos , int state , bool doing) {
    if (pos == -1)
        return state != 2;
    if (!doing && ~f[pos][state])
        return f[pos][state];
    LL res = 0;
    int end = doing ? digit[pos] : 9;
    for (int i = 0 ; i <= end ; ++ i) {
        int next_state;
        if (state == 0) {
            if (i == 1)
                next_state = 1;
            else
                next_state = 0;
        }
        if (state == 1) {
            if (i == 3)
                next_state = 2;
            else if (i == 1)
                next_state = 1;
            else
                next_state = 0;
        }
        if (state == 2) {
            next_state = 2;
        }
        res += dfs(pos - 1 , next_state , doing && i == end);
    }
    if (!doing)
        f[pos][state] = res;
    return res;
}
LL cal(LL x) {
    memset(f , -1 , sizeof(f));
    int pos = 0;
    while(x) {
        digit[pos ++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1 , 0 , 1);
}

void work()
{
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%lld" , &K);
        LL l = 0 , r = 1LL << 62 , m;
        while (l < r) {
            m = l + r >> 1;
            if (cal(m) < K + 1)
                l = m + 1;
            else
                r = m;
        }
        printf("%lld\n" , l);
    }
}

int main()
{
    work();
    return 0;
}
