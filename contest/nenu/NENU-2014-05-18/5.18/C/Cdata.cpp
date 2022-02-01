#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<ctime>
#include<stack>
#include<map>
#include<set>
#define eps 1e-7
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define CLR(a, b) memset(a, b, sizeof(a))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

int mod = (1<<16) - 1;

int main()
{
    freopen("in.txt", "w", stdout);
    srand(unsigned(time(NULL)));
    int T = 5,  n, m;
    while(T --)
    {
        n = rand() % 50 + 1;
        m = rand() % 100 + 1;
        printf("%d %d\n", n, m);
        for(int i = 1; i <= n; i ++)
        {
            int val = rand() % 1000;
            printf("%d ", val + 1);
        }
        puts("");
        for(int i = 0; i < m; i ++)
        {
            int u = -1, v = -1;
            while(u == v)
            {
                u = rand() % n + 1; v = rand() % n + 1;
            }
            printf("%d %d\n", u, v);
        }
        puts("");
    }
    T = 5;
    while(T --)
    {
        n = rand() % 1000 + 1;
        m = rand() % 20000 + 1;
        printf("%d %d\n", n, m);
        for(int i = 1; i <= n; i ++)
        {
            int val = rand() % mod;
            printf("%d ", val + 1);
        }
        puts("");
        for(int i = 0; i < m; i ++)
        {
            int u = -1, v = -1;
            while(u == v)
            {
                u = rand() % n + 1; v = rand() % n + 1;
            }
            printf("%d %d\n", u, v);
        }
        puts("");
    }
    n = 1000;
    m = 0;
    printf("%d %d\n", n, m);
    for(int i = 1; i <= n; i ++) printf("%d ", rand() % mod + 1);
    puts("");
}
