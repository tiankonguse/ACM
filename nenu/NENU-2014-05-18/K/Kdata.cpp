#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
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

int main()
{
    freopen("in.txt", "w", stdout);
    srand(unsigned(time(NULL)));
    int  n, m, t;
    int T = 10;
    while(T --)
    {
        n = rand() % 30 + 1;
        m = rand() % 50;
        t = rand() % 100000;
        printf("%d %d %d\n", n, m, t);
        for(int i = 0; i < m - n; i ++)
        {
            int u = -1, v = -1;
            while(u == v)
            {
                u = rand() % (n - n/2) + 1; v = rand() % (n - n/2) + 1;
            }
            printf("%d %d\n", u, v);
        }
        for(int i = 0; i < min(m, n); i ++)
        {
            int u = -1, v = -1;
            while(u == v)
            {
                u = rand() % (n/2) + n - n/2 + 1; v = rand() % (n/2) + (n - n/2) + 1;
            }
            printf("%d %d\n", u, v);
        }
        for(int i = 0; i < n; i ++)
        {
            printf("%d ", rand() % n + 1);
        }
        puts("");
    }
    T = 2;
    while(T --)
    {
        n = 100;
        m = rand() % 200;
        t = rand() % 100000;
        printf("%d %d %d\n", n, m, t);
        for(int i = 0; i < m - n; i ++)
        {
            int u = -1, v = -1;
            while(u == v)
            {
                u = rand() % (n - n/2) + 1; v = rand() % (n - n/2) + 1;
            }
            printf("%d %d\n", u, v);
        }
        for(int i = 0; i < min(m, n); i ++)
        {
            int u = -1, v = -1;
            while(u == v)
            {
                u = rand() % (n/2) + n - n/2 + 1; v = rand() % (n/2) + (n - n/2) + 1;
            }
            printf("%d %d\n", u, v);
        }
        for(int i = 0; i < n; i ++)
        {
            printf("%d ", rand() % n + 1);
        }
        puts("");
    }
    n = 100;
    m = 2000;
    t = rand() % 100 + 99900;
    printf("%d %d %d\n", n, m, t);
    for(int i = 0; i < m - n; i ++)
    {
        int u = -1, v = -1;
        while(u == v)
        {
            u = rand() % (n - 20) + 1; v = rand() % (n - 20) + 1;
        }
        printf("%d %d\n", u, v);
    }
    for(int i = 0; i < min(m, n); i ++)
    {
        int u = -1, v = -1;
        while(u == v)
        {
            u = rand() % 20 + n - 20 + 1; v = rand() % 20 + (n - 20) + 1;
        }
        printf("%d %d\n", u, v);
    }
    for(int i = 0; i < n; i ++)
    {
        printf("%d ", rand() % n + 1);
    }
    puts("");
    n = 100;
    m = 0;
    t = rand() % 100 + 99900;
    printf("%d %d %d\n", n, m, t);
    for(int i = 0; i < m; i ++)
    {
        int u = -1, v = -1;
        while(u == v)
        {
            u = rand() % n + 1; v = rand() % n + 1;
        }
        printf("%d %d\n", u, v);
    }
    for(int i = 0; i < n; i ++)
    {
        printf("%d ", rand() % n + 1);
    }
    puts("");
}
