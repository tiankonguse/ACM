#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , m , pre[N] , mcnt;
struct edge
{
    int x , next;
}e[N << 1];
int ans , s[N] , ca;

void dfs(int x , int fa)
{
    s[x] = 1; int sum = (n - 1) * (n - 2) / 2;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
        {
            int y = e[i].x;
            dfs(y , x);
            s[x] += s[y];
            sum -= s[y] * (s[y] - 1) / 2;
        }
    sum -= (n - s[x]) * (n - s[x] - 1) / 2;
    ans = max(ans , sum);
}

void work()
{
    int i , x , y;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    ans = 0;
    dfs(1 , 0);
    printf("Case #%d: %d\n" , ++ ca , ans);
}

int main()
{

    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
