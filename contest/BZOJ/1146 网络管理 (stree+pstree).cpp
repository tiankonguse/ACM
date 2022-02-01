#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define N 80005
int n , m , a[N] , pre[N] , mcnt;
struct edge
{
    int x , next;
}e[N << 1];
int dep[N] , f[17][N] , L[N] , R[N] , ncnt;
void dfs(int x , int fa)
{
    f[0][x] = fa , dep[x] = dep[fa] + 1 , L[x] = ++ ncnt;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != fa)
            dfs(e[i].x , x);
    R[x] = ncnt;
}
int LCA(int x , int y)
{
    if (dep[x] < dep[y]) swap(x , y);
    for (int i = 16 ; i >= 0 ; -- i)
        if (dep[x] - dep[y] >> i & 1)
            x = f[i][x];
    if (x == y) return y;
    for (int i = 16 ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y])
            x = f[i][x] , y = f[i][y];
    return f[0][x];
}

int Down = -1 , Up = 1e8 , t[N << 1];
#define Node 12582912
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
int ch[Node][2] , sum[Node] , nodecnt;

int newnode()
{
    ++ nodecnt;
    ch[nodecnt][0] = ch[nodecnt][1] = sum[nodecnt] = 0;
    return nodecnt;
}

void add(int& p , int l , int r , int x , int w)
{
    if (!p) p = newnode();
    if (l == r)
        sum[p] += w;
    else
    {
        MID;
        if (x <= mid)
            add(ch[p][0] , Left , x , w);
        else
            add(ch[p][1] , Right , x , w);
        sum[p] = sum[ch[p][0]] + sum[ch[p][1]];
    }
}
int PP[100] , MM[100] , sp , sm;
int query(int l , int r , int K)
{
    if (l == r) return l; MID;
    int cnt = 0;
    for (int i = 0 ; i < sp ; ++ i) cnt += sum[ch[PP[i]][1]];
    for (int i = 0 ; i < sm ; ++ i) cnt -= sum[ch[MM[i]][1]];
    if (cnt >= K)
    {
        for (int i = 0 ; i < sp ; ++ i) PP[i] = ch[PP[i]][1];
        for (int i = 0 ; i < sm ; ++ i) MM[i] = ch[MM[i]][1];
        return query(Right , K);
    }
    else
    {
        for (int i = 0 ; i < sp ; ++ i) PP[i] = ch[PP[i]][0];
        for (int i = 0 ; i < sm ; ++ i) MM[i] = ch[MM[i]][0];
        return query(Left , K - cnt);
    }
}
void ADD(int l , int r , int top , int bot , int x , int w)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        add(t[p] , Down , Up , x , w);
    else
    {
        MID;
        if (top <= mid)
            ADD(Left , top , bot , x , w);
        if (bot > mid)
            ADD(Right , top , bot , x , w);
    }
}
void QUERY(int l , int r , int x , bool flag)
{
    int p = id(l , r);
    if (flag) PP[sp ++] = t[p]; else MM[sm ++] = t[p];
    if (l != r)
    {
        MID;
        if (x <= mid)
            QUERY(Left , x , flag);
        else
            QUERY(Right , x , flag);
    }
}
void work()
{
    int i , j , k , x , y , z;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    for (j = 1 ; 1 << j < n ; ++ j)
        for (i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    for (i = 1 ; i <= n ; ++ i)
        ADD(1 , n , L[i] , R[i] , a[i] , 1);
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d%d",&k,&x,&y);
        if (k)
        {
            sp = sm = 0 , z = LCA(x , y);
            QUERY(1 , n , L[x] , 1);
            QUERY(1 , n , L[y] , 1);
            QUERY(1 , n , L[z] , 0);
            if(f[0][z]) QUERY(1 , n , L[f[0][z]] , 0);
            k = query(Down , Up , k);
            if (~k) printf("%d\n" , k); else puts("invalid request!");
        }
        else
        {
            ADD(1 , n , L[x] , R[x] , a[x] , -1);
            a[x] = y;
            ADD(1 , n , L[x] , R[x] , a[x] , 1);
        }
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
