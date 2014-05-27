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

int mod = 2 * 1e5, haf = 1e5;

int main()
{
    freopen("in.txt", "w", stdout);
    srand(unsigned(time(NULL)));
    int T = 10;
    while(T --)
    {
        int n = rand() % 20 + 1, m = rand() % 20 + 1;
        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++) printf("%d ", rand() % 1000 - 500 + 1);
            puts("");
        }
    }
    T = 3;
    while(T --)
    {
        int n = rand() % 200 + 1, m = rand() % 200 + 1;
        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++) printf("%d ", rand() % 1000 - 500 + 1);
            puts("");
        }
    }
    puts("200 200");
    int cnt = 1;
    for(int i = 0; i < 200; i ++)
    {
        for(int j = 0; j < 200; j ++)
            printf("%d ", cnt ++);
        puts("");
    }

    T = 1;
    while(T --)
    {
        int n = rand() % 500 + 1, m = rand() % 500 + 1;
        printf("%d %d\n", n, m);
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++) printf("%d ", rand() % mod - haf + 1);
            puts("");
        }
    }
    puts("1000 1000");
    for(int i = 0; i < 1000; i ++)
    {
        for(int j = 0; j < 1000; j ++) printf("1 ");
        puts("");
    }

    puts("1000 1000");cnt = 1;
    for(int i = 0; i < 1000; i ++)
    {
        for(int j = 0; j < 1000; j ++) printf("%d ", cnt ++);
        puts("");
    }
}
