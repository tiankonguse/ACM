#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxr = 55;
int const maxn = 2525;
int const maxm = 2222222;
char mp[maxr][maxr];
struct edges
{
    int u, next;
} e[maxm];
int p[maxn], idx;
void init()
{
    idx = 0;
    memset(p, 0xff, sizeof p);
}
void addedge(int u, int v)
{
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}
int h[maxr][maxr], v[maxr][maxr];

int n, m;
int matx[maxn], maty[maxn];
bool fy[maxn];

int path(int u)
{
    int v;
    for (int i = p[u]; ~i; i = e[i].next)
    {
        v = e[i].u;
        if (!fy[v])
        {
            fy[v] = true;
            if (maty[v] < 0 || path(maty[v]))
            {
                matx[u] = v;
                maty[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary()
{
    int ret = 0;
    memset(matx, 0xff, sizeof matx);
    memset(maty, 0xff, sizeof maty);
    for (int i = 1; i <= n; ++i)
    {
        if (matx[i] < 0)
        {
            memset(fy, 0, sizeof fy);
            ret += path(i);
        }
    }
    return ret;
}
int main()
{
    int r, c;
    for (; ~scanf("%d%d", &r, &c); )
    {
        for (int i = 0; i < r; ++i) scanf(" %s", mp[i]);
        int hid = 0, vid = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (mp[i][j] == '*')
                {
                    h[i][j] = ++hid;
                    while (j + 1 < c && mp[i][j + 1] == '*')
                    {
                        h[i][++j] = hid;
                    }
                }
            }
        }
        for (int i = 0; i < c; ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                if (mp[j][i] == '*')
                {
                    v[j][i] = ++vid;
                    while (j + 1 < r && mp[j + 1][i] == '*')
                    {
                        v[++j][i] = vid;
                    }
                }
            }
        }
        init();
        n = hid, m = vid;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (mp[i][j] == '*')
                {
                    addedge(h[i][j], v[i][j]);
                }
            }
        }
        printf("%d\n", hungary());
    }
    return 0;
}
