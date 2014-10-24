#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#define N 50005
typedef long long LL;
int n , m;
int pre[N] , mcnt;
struct edge
{
    int x;
    LL w;
    int next;
}e[N << 2];
LL d[N] , c[N << 1];
int cnt;
bool f[N];
void addarc(int x ,int y ,LL w)
{
    e[mcnt] = (edge){y , w , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (edge){x , w , pre[y]} , pre[y] = mcnt ++;
}

void dfs(int x , int fa)
{
    f[x] = 1;
    //cout << x << ' ' << fa << endl;
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
        if (!f[y])
            d[y] = d[x] ^ e[i].w , dfs(y , x);
        else if (y != fa && x < y)
            c[++ cnt] = d[x] ^ d[y] ^ e[i].w;
    }
}

void work()
{
    int i , j , x , y ; LL z , w;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d%lld",&x,&y,&z);
        addarc(x , y , z);
    }
    dfs(1 , 0);
    z = d[n];
    for (j = 63 ; j >= 0 ; -- j)
    {
        for (i = 1 ; i <= cnt ; ++ i)
            if (c[i] >> j & 1)
                break;
        if (!(z >> j & 1))
            z ^= c[i];
        w = c[i];
        for (i = 1 ; i <= cnt ; ++ i)
            if (c[i] >> j & 1)
                c[i] ^= w;
    }
    cout << z << endl;
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}
