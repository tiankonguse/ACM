#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005
int n , m , pre[N] , mcnt;
int ncnt , L[N] , R[N];
struct edge
{
    int x , next;
}e[N];

struct stree
{
    int w , f;
}t[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define ID id(l , r)
#define MID int mid = l + r >> 1;
#define Left l , mid
#define Right mid + 1 , r

void Build(int l , int r)
{
    t[ID].f = 0;
    if (l == r)
    {
        t[ID].w = 0;
        return;
    }MID;
    Build(Left) , Build(Right);
    t[ID].w = t[id(Left)].w + t[id(Right)].w;
}

void update(int l , int r , int top , int bot)
{
    if (top <= l && r <= bot)
    {
        t[ID].f ^= 1 , t[ID].w = (r - l + 1) - t[ID].w;
        return;
    }MID;
    int LL = id(Left) , RR = id(Right) , p = ID;
    if (t[p].f)
    {
        t[LL].f ^= 1 , t[RR].f ^= 1;
        t[LL].w = (mid - l + 1) - t[LL].w;
        t[RR].w = (r - mid) - t[RR].w;
        t[p].f ^= 1;
    }
    if (top <= mid) update(Left , top , bot);
    if (bot > mid) update(Right , top , bot);
    t[p].w = t[LL].w + t[RR].w;
}

int query(int l , int r , int top , int bot)
{
    if (top <= l && r <= bot)
    {
        return t[ID].w;
    }MID;
    int LL = id(Left) , RR = id(Right) , p = ID , ans = 0;
    if (t[p].f)
    {
        t[LL].f ^= 1 , t[RR].f ^= 1;
        t[LL].w = (mid - l + 1) - t[LL].w;
        t[RR].w = (r - mid) - t[RR].w;
        t[p].f ^= 1;
    }
    if (top <= mid) ans += query(Left , top , bot);
    if (bot > mid) ans += query(Right , top , bot);
    t[p].w = t[LL].w + t[RR].w;
    return ans;
}

void dfs(int x)
{
    L[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        dfs(e[i].x);
    R[x] = ncnt;
}

void work()
{
    int i , x , y; char s[5];
    memset(pre , -1 , sizeof(pre)) , mcnt = ncnt = 0;
    for (i = 2 ; i <= n ; ++ i)
        scanf("%d",&x) , e[mcnt] = (edge) {i , pre[x]} , pre[x] = mcnt ++;
    dfs(1);
    Build(1 , n);
    while (m --)
    {
        scanf("%s%d" , s , &x);
        if (*s == 'o')
            update(1 , n , L[x] , R[x]);
        else printf("%d\n" , query(1 , n , L[x] , R[x]));
    }
    puts("");
}

int main()
{

    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
