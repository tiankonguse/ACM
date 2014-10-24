#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define N 80005
#define M 2000005
int n , m , pre[N] , mcnt , ca , a[N];
struct edge
{
    int x , next;
}e[N << 1];
int size[N] , heavy[N] , tid[N] , Top[N] , ncnt , dep[N] , Fa[N];
long long Q = 1e9 + 7 , X = 1 , R = 1e9 + 9;
int rand1()
{
    X *= Q , X %= R;
    return (int) X;
}
struct Treap
{
    int nodecnt , priority[M] , child[M][2];
    int key[M] , Size[M] , cnt[M];
    int del[M] , rs;
    void clear()
    {
        nodecnt = 1;
        priority[0] = -1 << 30;
        child[0][0] = child[0][1] = 0;
        cnt[0] = 0 , Size[0] = 0;
        rs = 0;
    }
    void update(int x)
    {
        Size[x] = Size[child[x][0]] + Size[child[x][1]] + cnt[x];
    }
    int newnode(int val)
    {
        int x;
        if (rs)
            x = del[rs --];
        else
            x = nodecnt ++;
        key[x] = val , cnt[x] = 1 , child[x][0] = child[x][1] = 0;
        priority[x] = rand1();
        return x;
    }
    void rotate (int& x , int t)
    {
        int y = child[x][t];
        child[x][t] = child[y][t ^ 1];
        child[y][t ^ 1] = x;
        update(x) , update(y);
        x = y;
    }
    void insert(int& x , int k)
    {
        if (x)
        {
            if (key[x] == k)
                ++ cnt[x];
            else
            {
                int t = key[x] < k;
                insert(child[x][t] , k);
                if (priority[child[x][t]] > priority[x])
                    rotate(x , t);
            }
        }
        else
            x = newnode(k);
        update(x);
    }

    void erase(int& x , int k)
    {
        if (key[x] == k)
        {
            if (cnt[x] > 1)
                -- cnt[x];
            else
            {
                if (!child[x][0] && !child[x][1])
                {
                    del[++ rs] = x;
                    -- cnt[x] , x = 0;
                    return;
                }
                int t = priority[child[x][0]] < priority[child[x][1]];
                rotate(x , t) , erase(x , k);
            }
        }
        else
            erase(child[x][key[x] < k] , k);
        update(x);
    }
    int Rank(int& x , int k)
    {
        if(!x) return 0;
        if (k > key[x])
            return Rank(child[x][1] , k);
        int Rk = Size[child[x][1]] + cnt[x];
        if (k < key[x])
            Rk += Rank(child[x][0] , k);
        return Rk;
    }
};
Treap T;
int t[N << 1];
int id(int l , int r) {return l + r | l != r;}
#define ID id(l , r)
#define Left l , mid
#define Right mid + 1 , r
#define MID int mid = l + r >> 1
void insert(int l , int r , int x , int w)
{
    T.insert(t[ID] , w);
    if (l == r) return; MID;
    x <= mid ? insert(Left , x , w) : insert(Right , x , w);
}
void erase(int l , int r , int x , int w)
{
    T.erase(t[ID] , w);
    if (l == r) return; MID;
    x <= mid ? erase(Left , x , w) : erase(Right , x , w);
}
void Rank(int l , int r , int top , int bot , int w , int& res)
{
    if (top <= l && r <= bot) {
        res += T.Rank(t[ID] , w);
        return;
    } MID;
    if (top <= mid) Rank(Left , top , bot , w , res);
    if (bot > mid) Rank(Right , top , bot , w , res);
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
    insert(1 , n , ncnt , a[x]);
    if (heavy[x]) ConnectHE(heavy[x] , anc);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (e[i].x != Fa[x] && e[i].x != heavy[x])
            ConnectHE(e[i].x , e[i].x);
}
void Rank(int x , int y , int w , int& res)
{
    while (Top[x] != Top[y])
    {
        if (dep[Top[x]] < dep[Top[y]])
            swap(x , y);
        Rank(1 , n , tid[Top[x]] , tid[x] , w , res);
        x = Fa[Top[x]];
    }
    if (dep[x] > dep[y]) swap(x , y);
    Rank(1 , n , tid[x] , tid[y] , w , res);
}

void work()
{
    int i , x , y , l , r , mid , res;
    memset(pre , -1 , sizeof(pre)) , mcnt = ncnt = 0;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    memset(t , 0 , sizeof(t)) , T.clear();
    FindHE(1 , 0 , 0);
    ConnectHE(1 , 1);

    while (m --)
    {
        scanf("%d%d%d",&i,&x,&y);
        if (!i)
            erase(1 , n , tid[x] , a[x]) , a[x] = y , insert(1 , n , tid[x] , a[x]);
        else
        {
            l = -1 , r = 100000000;
            while (l < r)
            {
                mid = l + r + 1 >> 1 , res = 0;
                Rank(x , y , mid , res);
                if (res >= i)
                    l = mid;
                else
                    r = mid - 1;
            }
            if (l == -1)
                puts("invalid request!");
            else
                printf("%d\n" , l);
        }
    }
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("1.in" , "w" , stdout);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
