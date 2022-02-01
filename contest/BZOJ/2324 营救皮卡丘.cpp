#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#define N 2005
typedef long long LL;
int s , t , ans , maxflow;
int pre[N] , mcnt;
struct arc
{
  int x , f , c , next;
}e[N * 100];

void addarc(int x ,int y ,int z ,int c)
{
  e[mcnt] = (arc){y , z , c , pre[x]} , pre[x] = mcnt ++;
  e[mcnt] = (arc){x , 0 , -c , pre[y]} , pre[y] = mcnt ++;
  // printf("%d %d %d %d\n",x,y,z,c);
}

int d[N] , p[N];
bool f[N];
deque<int> q;

bool Bellman_Ford()
{
  int i , x , y , z;
  memset(f , 0 , sizeof(f));
  for (i = 1; i <= t ; ++ i) d[i] = 1 << 30;
  d[s] = 0 , f[s] = 1 , q.push_back(s);
  while (!q.empty())
  {
    x = q.front() , q.pop_front() , f[x] = 0;
    for (i = pre[x] ; ~i ; i = e[i].next)
    {
      y = e[i].x , z = e[i].c;
      if (e[i].f && d[y] > d[x] + z)
      {
        d[y] = d[x] + z , p[y] = i;
        if (!f[y])
        {
          if (q.empty() || d[y] < d[q.front()])
            q.push_front(y);
          else q.push_back(y);
          f[y] = 1;
        }
      }
    }
  }
  return d[t] != 1 << 30;
}

int Mincostflow()
{
  maxflow = 0 , ans = 0;
  int x;
  while (Bellman_Ford())
  {
    int flow = 1 << 30;
    for (x = t ; x != s ; x = e[p[x] ^ 1].x)
      flow = min(flow , e[p[x]].f);
    maxflow += flow , ans += d[t] * flow;
    for (x = t ; x != s ; x = e[p[x] ^ 1].x)
      e[p[x]].f -= flow , e[p[x] ^ 1].f += flow;
  }
  return ans;
}

int n , m , K;
int sp[151][151][151] , g[151][151];
void work()
{
    int i , j , k , x , y , z;
    scanf("%d%d%d",&n,&m,&K);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= n ; ++ j)
            g[i][j] = 1 << 29;
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%d%d%d",&x,&y,&z);
        g[x][y] = g[y][x] = min(g[x][y] , z);
    }
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= n ; ++ j)
            sp[0][i][j] = 1 << 29;
    sp[0][0][0] = 0;
    for (k = 1 ; k <= n ; ++ k)
    {
        for (i = 0 ; i <= n ; ++ i)
            for (j = 0 ; j <= n ; ++ j)
                sp[k][i][j] = sp[k - 1][i][j];
        sp[k][k][k] = 0;
        for (i = 0 ; i < k ; ++ i)
            sp[k][i][k] = sp[k][k][i] = min(sp[k][k][i] , g[i][k]);
        for (i = 0 ; i < k ; ++ i)
            for (j = 0 ; j < k ; ++ j)
                sp[k][i][k] = sp[k][k][i] = min(sp[k][k][i] , sp[k][i][j] + sp[k][j][k]);
        for (i = 0 ; i < k ; ++ i)
            for (j = 0 ; j < k ; ++ j)
                sp[k][i][j] = min(sp[k][i][j] , sp[k][i][k] + sp[k][k][j]);
    }
    int ss = (n + 1) << 1 , tt = ss + 1;
    s = (n + 2) << 1 , t = s + 1;
    addarc(0 << 1 , t , K , 0);
    addarc(s , 0 << 1 | 1 , K , 0);
    for (i = 1 ; i <= n ; ++ i)
    {
        addarc(i << 1 , t , 1 , 0);
        addarc(s , i << 1 | 1 , 1 , 0);
    }
    for (i = 0 ; i <= n ; ++ i)
        for (j = i + 1 ; j <= n ; ++ j)
        {
            if (sp[j][i][j] >= 1 << 29) continue;
            addarc(i << 1 | 1 , j << 1 , 1 << 30 , sp[j][i][j]);
        }
    cout << Mincostflow() << endl;
}

int main()
{
    work();
    return 0;
}
