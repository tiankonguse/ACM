#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
#define N 500005
#define M 1024
int n , m , ca;
int small[M][M];
int f[N];
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = (LL)l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
int t[N << 1];

void add(int l , int r , int x)
{
    int p = id(l , r);
    if (l == r)
    {
        t[p] = l;
        return;
    } MID;
    if (x <= mid)
        add(Left , x);
    else
        add(Right , x);
    t[p] = min(t[id(Left)] , t[id(Right)]);
}
int query(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p]; MID;
    if (bot <= mid)
        return query(Left , top , bot);
    else if (top > mid)
        return query(Right , top , bot);
    else
        return min(query(Left , top , bot) , query(Right , top , bot));
}
void work()
{
    int i , j , x , y = 0;
    char str[5];
    memset(small , 0 , sizeof(small));
    memset(t , 0x7F , sizeof(t));
    memset(f , 0 , sizeof(f));
    if (ca ++) puts("");
    printf("Case %d:\n" , ca);
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%s" , str);
        if (*str == 'A')
        {
            scanf("%d",&x);
            if (x < M)
            {
                for (j = 0 ; j < x ; ++ j)
                    if (small[x][j])
                        break;
                if (j < x)
                    printf("%d\n" , small[x][j]);
                else
                    puts("-1");
            }
            else
            {
                int l = 0 , r = x - 1;
                pair<int , int> res(1 << 30 , 1 << 30);
                while (l <= 500000)
                {
                    j = query(1 , 500000 , max(1 , l) , min(500000 , r));
                    if (j != 0x7F7F7F7F)
                        res = min(res , make_pair(j % x , -f[j]));
                    l += x , r += x;
                }
                if (res.first == 1 << 30)
                    puts("-1");
                else
                    printf("%d\n" , -res.second);
            }
        }
        else
        {
            scanf("%d",&x);
            f[x] = ++ y;
            for (j = 1 ; j < M ; ++ j)
                small[j][x % j] = y;
            add(1 , 500000 , x);
        }
    }
}

int main()
{
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
