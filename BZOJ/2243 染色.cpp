#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 100005
int n , m , pre[N] , mcnt , ca , a[N];
struct edge
{
    int x , next;
}e[N << 1];
int size[N] , heavy[N] , tid[N] , Top[N] , ncnt , dep[N] , Fa[N];

struct stree
{
    int l , r , c;
    stree () {l = r = c = 0;}
    stree (int _l , int _r , int _c) {l = _l , r = _r , c = _c;}
    stree rev() {
        return stree(r , l , c);
    }
}t[N << 1];
int f[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define Left l , mid
#define Right mid + 1 , r
#define MID int mid = l + r >> 1
stree operator + (stree A , stree B)
{
    if (!A.c) return B;
    if (!B.c) return A;
    return stree(A.l , B.r , A.c + B.c - (A.r == B.l));
}

stree query(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID; int LL = id(Left) , RR = id(Right);
    if (f[p])
    {
        f[LL] = f[RR] = f[p];
        t[LL].c = t[RR].c = 1;
        t[LL].l = t[LL].r = t[RR].l = t[RR].r = f[p];
        f[p] = 0;
    }
    if (bot <= mid)
        return query(Left , top , bot);
    if (top >  mid)
        return query(Right , top , bot);
    return query(Left , top , bot) + query(Right , top , bot);
}
void paint(int l , int r , int top , int bot , int w)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
    {
        f[p] = w;
        t[p].c = 1 , t[p].l = t[p].r = w;
        return;
    }
    MID; int LL = id(Left) , RR = id(Right);
    if (f[p])
    {
        f[LL] = f[RR] = f[p];
        t[LL].c = t[RR].c = 1;
        t[LL].l = t[LL].r = t[RR].l = t[RR].r = f[p];
        f[p] = 0;
    }
    if (top <= mid)
        paint(Left , top , bot , w);
    if (bot >  mid)
        paint(Right , top , bot , w);
    t[p] = t[LL] + t[RR];
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
    paint(1 , n , ncnt , ncnt , a[x]);
    if (heavy[x]) ConnectHE(heavy[x] , anc);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != Fa[x] && e[i].x != heavy[x])
            ConnectHE(e[i].x , e[i].x);
}
int query(int x , int y)
{
    stree cx , cy;
    //bool dir = 1;
    while (Top[x] != Top[y])
    {
        if (dep[Top[x]] > dep[Top[y]])
        {
            cx = cx + query(1 , n , tid[Top[x]] , tid[x]).rev();
            x = Fa[Top[x]];
        }
        else
        {
            cy = query(1 , n , tid[Top[y]] , tid[y]) + cy;
            y = Fa[Top[y]];
        }
    }
    if (dep[x] < dep[y])
        cx = cx + query(1 , n , tid[x] , tid[y]);
    else
        cy = query(1 , n , tid[y] , tid[x]).rev() + cy;
    return (cx + cy).c;
}
void paint(int x , int y , int w)
{
    while (Top[x] != Top[y])
    {
        if (dep[Top[x]] < dep[Top[y]])
            swap(x , y);
        paint(1 , n , tid[Top[x]] , tid[x] , w);
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x , y);
    paint(1 , n , tid[x] , tid[y] , w);
}

void work()
{
    int i , x , y , z;
    char str[10];
    memset(pre , -1 , sizeof(pre)) , mcnt = ncnt = 0;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , ++ a[i];
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    memset(t , 0 , sizeof(t));
    FindHE(1 , 0 , 0);
    ConnectHE(1 , 1);

    while (m --)
    {
        scanf("%s%d%d",str,&x,&y);
        if (*str == 'C')
            scanf("%d",&i) , paint(x , y , i + 1);
        else
            printf("%d\n" , query(x , y));
    }
}

int main()
{
    work();
    return 0;
}
