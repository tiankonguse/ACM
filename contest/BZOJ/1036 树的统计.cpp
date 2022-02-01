#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 30005
int n , m , pre[N] , mcnt , a[N];
struct edge
{
    int x , next;
}e[N << 1];
int size[N] , heavy[N] , tid[N] , Top[N] , ncnt , dep[N] , Fa[N];
int t[N << 1] , s[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define Left l , mid
#define Right mid + 1 , r
#define MID int mid = l + r >> 1
void update(int l , int r , int x , int w)
{
    int p = id(l , r);
    if (l == r)
        t[p] = s[p] = w;
    else
    {
        MID;
        if (x <= mid)
            update(Left , x , w);
        else
            update(Right , x , w);
        t[p] = max(t[id(Left)] , t[id(Right)]);
        s[p] = s[id(Left)] + s[id(Right)];
    }
}
int query(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID; int ans = -1 << 30;
    if (top <= mid)
        ans = max(ans , query(Left , top , bot));
    if (bot >  mid)
        ans = max(ans , query(Right , top , bot));
    return ans;
}
int Query(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        return s[p];
    MID; int ans = 0;
    if (top <= mid)
        ans += Query(Left , top , bot);
    if (bot >  mid)
        ans += Query(Right , top , bot);
    return ans;
}


void FindHE(int x , int fa , int Dep)
{
    heavy[x] = 0 , size[x] = 1 , dep[x] = Dep , Fa[x] = fa;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
        {
            int y = e[i].x;
            FindHE(y , x , Dep + 1);
            size[x] += size[y];
            if (!heavy[x] || size[y] > size[heavy[x]])
                heavy[x] = y;
        }
}
void ConnectHE(int x , int anc)
{
    tid[x] = ++ ncnt , Top[x] = anc;
    update(1 , n , ncnt , a[x]);
    if (heavy[x])
        ConnectHE(heavy[x] , anc);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != Fa[x] && e[i].x != heavy[x])
            ConnectHE(e[i].x , e[i].x);
}
int query(int x , int y)
{
    int ans = -1 << 30;
    while (Top[x] != Top[y])
    {
        if (dep[Top[x]] < dep[Top[y]])
            swap(x , y);
        ans = max(ans , query(1 , n , tid[Top[x]] , tid[x]));
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x , y);
    ans = max(ans , query(1 , n , tid[x] , tid[y]));
    return ans;
}
int Query(int x , int y)
{
    int ans = 0;
    while (Top[x] != Top[y])
    {
        if (dep[Top[x]] < dep[Top[y]])
            swap(x , y);
        ans += Query(1 , n , tid[Top[x]] , tid[x]);
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x , y);
    ans += Query(1 , n , tid[x] , tid[y]);
    return ans;
}
void work()
{
    int i , x , y , z;
    char str[10];
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre)) , mcnt = ncnt = 0;
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    memset(t , 0 , sizeof(t));
    memset(s , 0 , sizeof(s));
    FindHE(1 , 0 , 0);
    ConnectHE(1 , 1);
    scanf("%d",&m);
    while (m --)
    {
        scanf("%s", str);
        scanf("%d%d",&x,&y);
        if (*str == 'C')
            update(1 , n , tid[x] , y);
        else if (*(str + 1) == 'M')
            printf("%d\n" , query(x , y));
        else
            printf("%d\n" , Query(x , y));
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}

