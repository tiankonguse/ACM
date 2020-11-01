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

const int maxn = 1100;

vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;

void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if(!sccno[v])
        {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if(lowlink[u] == pre[u])
    {
        scc_cnt++;
        for(;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}

void find_scc(int n)
{
    dfs_clock = scc_cnt = 0;
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    for(int i = 0; i < n; i++)
        if(!pre[i]) dfs(i);
}

int val[maxn], idx[maxn], hav[maxn];
vector<int> G2[maxn];

void dfs2(int u, int add)
{
    val[u] += add;
    for(int i = 0; i < G2[u].size(); i ++)
    {
        int v = G2[u][i];
        dfs2(v, add);
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &val[i]);
            G[i].clear(); G2[i].clear();
            idx[i] = n + 1;
        }
        G2[n].clear();
        for(int i = 0; i < m; i ++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u --, v --;
            G[v].push_back(u);
        }
        find_scc(n);
        CLR(hav, 0);
        for(int i = 0; i < n; i ++)
        {
            hav[sccno[i]] += val[i];
            idx[sccno[i]] = min(idx[sccno[i]], i);
            for(int j = 0; j < G[i].size(); j ++)
            {
                if(sccno[i] != sccno[G[i][j]])
                    G2[sccno[i]].push_back(sccno[G[i][j]]);
            }
        }
        CLR(val, 0); int ans = n + 1, tot = 0;
        for(int i = 1; i <= scc_cnt; i ++)
        {
            dfs2(i, hav[i]);
        }
        for(int i = 1; i <= scc_cnt; i ++)
        {
            if(val[i] > tot)
            {
                tot = val[i]; ans = idx[i];
            }
            else if(val[i] == tot)
            {
                ans = min(ans, idx[i]);
            }
        }
        printf("%d\n", ans + 1);
    }
}
