#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 200005
typedef long long LL;
struct stree
{
    LL w , f;
    int x;
}t[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = (l + r) >> 1
#define ID id(l , r)
#define Left l , mid
#define Right mid + 1 , r

int n , pre[N] , mcnt , ncnt , K , a[N];
struct edge
{
    int x , next;
}e[N];
int L[N] , R[N] , sq[N] , f[N];
LL d[N];

void pushup(int l , int r)
{
    MID;int p = ID , LL = id(Left) , RR = id(Right);
    t[p].w = t[LL].w , t[p].x = t[LL].x;
    if (t[RR].w > t[p].w)
        t[p].w = t[RR].w , t[p].x = t[RR].x;
}
void pushdown(int l , int r)
{
    MID;int p = ID , LL = id(Left) , RR = id(Right);
    if (t[p].f != 0)
    {
        t[LL].w += t[p].f , t[LL].f += t[p].f;
        t[RR].w += t[p].f , t[RR].f += t[p].f;
        t[p].f = 0;
    }
}
void update(int l , int r , int top , int bot , LL w)
{
    if (top <= l && r <= bot)
    {
        t[ID].f += w , t[ID].w += w; return;
    } MID; pushdown(l , r);
    if (top <= mid) update(Left , top , bot , w);
    if (bot > mid) update(Right , top , bot , w);
    pushup(l , r);
}
LL query(int l , int r , int x)
{
    if (x <= l && r <= x)
    {
        return t[ID].w;
    } MID; pushdown(l , r);
    if (x <= mid) return query(Left , x);
    if (x > mid) return query(Right , x);
    pushup(l , r);
}

void Build(int l , int r)
{
    int p = ID;
    if (l == r)
    {
        t[p].w = d[sq[l]] , t[p].x = l; return;
    } MID;
    Build(Left) ; Build(Right) ; pushup(l , r);
}

void dfs(int x)
{
    L[x] = ++ ncnt , sq[ncnt] = x;
    d[x] += a[x];
    for (int i = pre[x] ; ~i ; i = e[i].next)
        d[e[i].x] += d[x] , dfs(e[i].x) ;
    R[x] = ncnt;
}

void work()
{
    int i , x , y ;
    LL ans = 0;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    mcnt = 0 , memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y) , f[y] = x;
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
    }
    dfs(1);
    Build(1 , n);
    while (K --)
    {
        ans += t[id(1 , n)].w;
        x = sq[t[id(1 , n)].x];
        while (x)
        {
            if (!query(1 , n , L[x])) break;
            update(1 , n , L[x] , R[x] , -a[x]);
            x = f[x];
        }
    }
    printf("%lld\n" , ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}
