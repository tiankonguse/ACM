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
int const maxn = 4040;
int const maxm = 2220000;
struct node
{
    int u, next;
    double c;
} e[maxm];
int n;
int p[maxn], idx;
void init()
{
    idx = 0;
    memset(p, 0xff, sizeof p);
}
void addedge(int u, int v, double c)
{
    e[idx].u = v;
    e[idx].c = c;
    e[idx].next = p[u];
    p[u] = idx++;
}
vector < pair<int, int> > v[111];
int vs[111];

inline int sqr(int x)
{
    return x * x;
}
inline double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((double)(sqr(x1 - x2) + sqr(y1 - y2)));
}
double dis[maxn];
bool mark[maxn];
queue <int> q;
void spfa(int s)
{
    int u, v; double w;
    while (!q.empty()) q.pop();
    memset(mark, 0, sizeof mark);
    for (int i = 0; i < maxn; ++i) dis[i] = 1e10;
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        mark[u] = false;
        for (int i = p[u]; ~i; i = e[i].next)
        {
            v = e[i].u;
            w = e[i].c;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (!mark[v])
                {
                    mark[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int _n, x, y, d;
    for (; ~scanf("%d", &_n); )
    {
        for (int i = 0; i < _n; ++i)
        {
            v[i].clear();
            scanf("%d", &vs[i]);
            for (int j = 0; j < vs[i]; ++j)
            {
                scanf("%d%d", &x, &y);
                v[i].push_back( make_pair(x, y) );
            }
        }
        init();
        for (int i = 1; i < _n; ++i)
        {
            for (int j = 0; j < vs[i - 1]; ++j)
            {
                for (int k = 0; k < vs[i]; ++k)
                {
                    addedge((i - 1) * 40 + j, i * 40 + k,
                            dist(v[i - 1][j].first, v[i - 1][j].second, v[i][k].first, v[i][k].second));
                }
            }
        }
        double ret = 1e10;
        for (int i = 0; i < vs[0]; ++i)
        {
            spfa(i);
            for (int j = 0; j < vs[_n - 1]; ++j)
            {
                ret = min(ret, (dis[(_n - 1) * 40 + j] + dist(v[0][i].first, v[0][i].second,
                                             v[_n - 1][j].first, v[_n - 1][j].second)));
            }
        }
        printf("%d\n", (int)(100.0 * ret));
    }
    return 0;
}
