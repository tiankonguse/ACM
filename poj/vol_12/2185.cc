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
int const maxn = 10010;
int const maxm = 80;
int fail[maxn];
int n, m;
char mp[maxn][maxm];

void buildFail_h(char *p)
{
    int j = fail[0] = -1;
    for (int i = 1; i < m; ++i)
    {
        while (j >= 0 && p[j + 1] != p[i]) j = fail[j];
        if (p[j + 1] != p[i]) fail[i] = j;
        else fail[i] = ++j;
    }
}
void buildFail_v(int id)
{
    int j = fail[0] = -1;
    for (int i = 1; i < n; ++i)
    {
        while (j >= 0 && (j + 1 >= n || mp[j + 1][id] != mp[i][id])) j = fail[j];
        if (j + 1 >= n || mp[j + 1][id] != mp[i][id]) fail[i] = j;
        else fail[i] = ++j;
    }
}
int hc[maxn], vc[maxn];

int main()
{
    for (; ~scanf("%d%d", &n, &m); )
    {
        for (int i = 0; i < n; ++i)
        {
            scanf(" %s", mp[i]);
        }
        memset(hc, 0, sizeof hc);
        memset(vc, 0, sizeof vc);

        for (int i = 0; i < n; ++i)
        {
            buildFail_h(mp[i]);
            for (int j = m - 1; ~j; j = fail[j])
            {
                hc[m - 1 - fail[j]]++;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            buildFail_v(i);
            for (int j = n - 1; ~j; j = fail[j])
            {
                vc[n - 1 - fail[j]]++;
            }
        }
        int h, v;
        for (int i = 1; i <= m; ++i)
        {
            if (hc[i] == n)
            {
                h = i;
                break;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (vc[i] == m)
            {
                v = i;
                break;
            }
        }
        printf("%d\n", h * v);
    }
    return 0;
}
