#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
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

const int maxn = 120;

struct Matr
{
    bool m[maxn][maxn];
    void init(int n)
    {
        CLR(m, 0);
        for(int i = 0; i < n; i ++)
            m[i][i] = 1;
    }
};

int n;

Matr Mul(Matr a, Matr b)
{
    Matr ret;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            ret.m[i][j] = 0;
            for(int k = 0; k < n; k ++)
            {
                if(a.m[i][k] && b.m[k][j])
                {
                    ret.m[i][j] = 1;
                    break;
                }
            }
        }
    }
    return ret;
}

Matr Fast_pow(Matr a, int m)
{
    Matr ret; ret.init(n);
    while(m)
    {
        if(m & 1) ret = Mul(ret, a);
        a = Mul(a, a);
        m >>= 1;
    }
    return ret;
}

int cnt[maxn];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int m, t, cas = 1; Matr a;
    while(scanf("%d%d%d", &n, &m, &t) != EOF)
    {
        CLR(a.m, 0);CLR(cnt, 0);
        for(int i = 0; i < m; i ++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u --, v --;
            a.m[v][u] = a.m[u][v] = 1;
            cnt[u] ++; cnt[v] ++;
        }
        a = Fast_pow(a, t);
        if(cas != 1) puts("");
        printf("Case %d:\n", cas ++);
        for(int i = 0; i < n; i ++)
        {
            int tmp;
            scanf("%d", &tmp); tmp --;
            if(cnt[tmp])for(int j = 0; j < n; j ++)
                printf("%d", a.m[tmp][j]);
            else
            {
                for(int j = 0; j < tmp; j ++) printf("0");
                printf("1");
                for(int j = tmp + 1; j < n; j ++) printf("0");
            }
            puts("");
        }
    }
}
