#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 2000005

int root[100005];
struct Treap
{
    int nodecnt , priority[N] , child[N][2];
    int key[N];
    int Size[N] , cnt[N];
    int rub[N] , rs;
    Treap(){
        clear();
    }
    void clear()
    {
        nodecnt = 1;
        priority[0] =  key[0] = -1 << 30;
        rs = Size[0] = 0;
    }
    int size(int x)
    {
        return Size[x];
    }
    void update(int x)
    {
        Size[x] = Size[child[x][0]] + Size[child[x][1]] + cnt[x];
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
        {
            if (rs)
                x = rub[rs --];
            else
                x = nodecnt ++;
            key[x] = k;
            cnt[x] = 1;
            priority[x] = rand();
            child[x][0] = child[x][1] = 0;
        }
        update(x);
    }
    void erase(int& x , int k)
    {
        if (!x) return;
        if (key[x] == k)
        {
            if (cnt[x] > 1)
                -- cnt[x];
            else
            {
                if (!child[x][0] && !child[x][1])
                {
                    rub[++ rs] = x;
                    x = 0;
                    return;
                }
                int t = priority[child[x][0]] < priority[child[x][1]];
                rotate(x , t);
                erase(x , k);
            }
        }
        else
            erase(child[x][key[x] < k] , k);
        update(x);
    }
    int Rank(int& x , int k)
    {
        if(!x) return 0;
        if (k < key[x])
            return Rank(child[x][0] , k);
        int Rk = Size[child[x][0]] + cnt[x];
        if (k > key[x])
            Rk += Rank(child[x][1] , k);
        return Rk;
    }
    int getKth(int& x , int k)
    {
        if (k <= Size[child[x][0]])
            return getKth(child[x][0] , k);
        k -= Size[child[x][0]] + cnt[x];
        if (k <= 0)  return key[x];
        return getKth(child[x][1] , k);
    }
    void Pre(int& x , int val , int& ans)
    {
        if (!x) return;
        if (val > key[x])
            ans = max(ans , key[x]) ,
            Pre(child[x][1] , val , ans);
        else
            Pre(child[x][0] , val , ans);
    }
    void Nxt(int& x , int val , int& ans)
    {
        if (!x) return;
        if (val < key[x])
            ans = min(ans , key[x]) ,
            Nxt(child[x][0] , val , ans);
        else
            Nxt(child[x][1] , val , ans);
    }
};

int a[50005];

int id(int l , int r) {return l + r | l != r;}
#define MID int mid = (l + r) >> 1
#define ID id(l , r)
#define Left l , mid
#define Right mid + 1 , r

int n , m ;
Treap T ;

void insert(int l , int r , int x , int w)
{
    int p = ID;
    T.insert(root[p] , w);
    if (l == r) return; MID;
    if (x <= mid) insert(Left , x , w);
    else insert(Right , x , w);
}
void erase(int l , int r , int x , int w)
{
    int p = ID;
    T.erase(root[p] , w);
    if (l == r) return; MID;
    if (x <= mid) erase(Left , x , w);
    else erase(Right , x , w);
}
void Pre(int l , int r , int top , int bot , int x , int& ans)
{
    int p = ID;
    if (top <= l && r <= bot)
    {
        T.Pre(root[p] , x , ans);
        return;
    }MID;
    if (top <= mid) Pre(Left , top , bot , x , ans);
    if (bot > mid) Pre(Right , top , bot , x , ans);
}
void Nxt(int l , int r , int top , int bot , int x , int& ans)
{
    int p = ID;
    if (top <= l && r <= bot)
    {
        T.Nxt(root[p] , x , ans);
        return;
    }MID;
    if (top <= mid) Nxt(Left , top , bot , x , ans);
    if (bot > mid) Nxt(Right , top , bot , x , ans);
}
void Rank(int l , int r , int top , int bot , int x , int& ans)
{
    int p = ID;
    if (top <= l && r <= bot)
    {
        ans += T.Rank(root[p] , x);
        return;
    }MID;
    if (top <= mid) Rank(Left , top , bot , x , ans);
    if (bot > mid) Rank(Right , top , bot , x , ans);
}

void work()
{
    int i , x , y , l , r , top , bot , mid;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , insert(1 , n , i , a[i]);
    while (m --)
    {
        scanf("%d%d%d",&i,&l,&r);
        if (i != 3) scanf("%d",&x);
        if (i == 1)
            y = 0 , Rank(1 , n , l , r , x - 1 , y) , printf("%d\n" , y + 1);
        if (i == 2)
        {
            top = 0 , bot = 1 << 30;
            while (top < bot)
            {
                mid = top + bot >> 1 , y = 0;
                Rank(1 , n , l , r , mid , y);
                if (y >= x)
                    bot = mid;
                else top = mid + 1;
            }
            printf("%d\n" , top);
        }
        if (i == 3)
        {
            erase(1 , n , l , a[l]);
            a[l] = r;
            insert(1 , n , l , a[l]);
        }
        if (i == 4)
            y = -1 << 30 , Pre(1 , n , l , r , x , y) , printf("%d\n" , y);
        if (i == 5)
            y = 1 << 30 , Nxt(1 , n , l , r , x , y) , printf("%d\n" , y);
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}
