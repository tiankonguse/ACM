#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005
int n;
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
struct stree
{
    bool c[4] , f[2] , u[2];
}t[N << 1];
stree operator + (stree A , stree B)
{
    stree res;
    res.f[0] = B.f[0] , res.f[1] = B.f[1];
    res.c[0] = A.c[0] && A.f[0] && B.c[0] || A.c[1] && A.f[1] && B.c[2];
    res.c[1] = A.c[0] && A.f[0] && B.c[1] || A.c[1] && A.f[1] && B.c[3];
    res.c[2] = A.c[2] && A.f[0] && B.c[0] || A.c[3] && A.f[1] && B.c[2];
    res.c[3] = A.c[2] && A.f[0] && B.c[1] || A.c[3] && A.f[1] && B.c[3];
    res.u[0] = A.u[0] || A.c[0] && A.c[3] && A.f[0] && A.f[1] && B.u[0];
    res.u[1] = B.u[1] || B.c[0] && B.c[3] && A.f[0] && A.f[1] && A.u[1];
    return res;
}

void build(int l , int r)
{
    int p = id(l , r);
    if (l == r)
    {
        t[p].f[0] = t[p].f[1] = t[p].c[1] = t[p].c[2] = 0;
        t[p].c[0] = t[p].c[3] = 1;
        t[p].u[0] = t[p].u[1] = 0;
        return;
    } MID;
    build(Left) , build(Right);
    t[p] = t[id(Left)] + t[id(Right)];
}

void update(int l , int r , int x , int w)
{
    int p = id(l , r);
    if (l == r)
    {
        if (w < 4)
            t[p].f[w >> 1] = w & 1;
        else
            t[p].c[1] = t[p].c[2] = t[p].u[0] = t[p].u[1] = w & 1;
        return;
    } MID;
    if (x <= mid)
        update(Left , x , w);
    else
        update(Right , x , w);
    t[p] = t[id(Left)] + t[id(Right)];
}

stree query(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    MID;
    if (top > mid)
        return query(Right , top , bot);
    else if (bot <= mid)
        return query(Left , top , bot);
    else
        return query(Left , top , bot) + query(Right , top , bot);
}


void work()
{
    int i , j;
    char str[10];
    pair<int , int> X , Y;
    scanf("%d",&n);
    build(1 , n);
    while (scanf("%s" , str) , *str != 'E')
    {
        scanf("%d%d%d%d",&X.second , &X.first , &Y.second , &Y.first);
        if (X > Y) swap(X , Y); -- X.second , -- Y.second;
        if (*str == 'A')
        {
            stree seg = query(1 , n , X.first , Y.first);
            stree Lturn = query(1 , n , 1 , X.first);
            stree Rturn = query(1 , n , Y.first , n);
            bool ans = seg.c[X.second << 1 | Y.second];
            ans |= Lturn.u[1] && seg.c[!X.second << 1 | Y.second];
            ans |= Rturn.u[0] && seg.c[X.second << 1 | !Y.second];
            ans |= Lturn.u[1] && Rturn.u[0] && seg.c[!X.second << 1 | !Y.second];
            puts(ans ? "Y" : "N");
        }
        else
        {
            if (X.first == Y.first)
                update(1 , n , X.first , 4 + (*str == 'O'));
            else
                update(1 , n , X.first , X.second << 1 | (*str == 'O'));
        }
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
