#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
#define N 200005
int n , a[N] , m , pre[N];
struct query
{
    int l , r , ans;
}q[N];
pair<int , int> t[N << 1] , tmp;
vector< pair<int , int> > w[N];
vector< int > pos[N];
int id(int l , int r) {return (l + r) | (l != r);}
#define MID int mid = (l + r) >> 1
#define Left l , mid
#define Right mid + 1 , r
void Build(int l , int r)
{
    int p = id(l , r);
    if (l == r)
        t[p] = w[l][0];
    else
    {
        MID; Build(Left) , Build(Right);
        t[p] = min(t[id(Left)] , t[id(Right)]);
        p = p + 1;
    }
}
pair<int , int> Query(int l , int r , int top , int bot)
{
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p];
    else
    {
        MID; pair<int , int> ans(1 << 30 , 0);
        if (top <= mid)
            ans = min(Query(Left , top , bot) , ans);
        if (bot > mid)
            ans = min(Query(Right , top , bot) , ans);
        return ans;
    }
}
void Update(int l , int r , int x)
{
    int p = id(l , r);
    if (l == r)
        t[p] = w[l][++ pre[l]];
    else
    {
        MID;
        if (x <= mid)
            Update(Left , x);
        else
            Update(Right , x);
        t[p] = min(t[id(Left)] , t[id(Right)]);
    }
}

void work()
{
    int i , j , l , r , h;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , pos[a[i]].push_back(i);
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d",&q[i].l , &q[i].r);
        w[q[i].l].push_back(make_pair(q[i].r , i));
    }
    for (i = 1 ; i <= n ; ++ i)
    {
        sort(w[i].begin() , w[i].end());
        w[i].push_back(make_pair(1 << 30 , 0));
    }
    Build(1 , n);
    for (j = 0 ; j <= 200001 ; ++ j)
        if (pos[j].size())
        {
            if (pos[j][0] != 1)
            {
                l = 1 , r = h = pos[j][0] - 1;
                tmp = Query(1 , n , l , r);
                while (tmp.first <= h)
                    q[tmp.second].ans = j , Update(1 , n , q[tmp.second].l) , tmp = Query(1 , n , l , r);
            }
            for (i = 1 ; i < pos[j].size() ; ++ i)
                if (pos[j][i - 1] + 1 != pos[j][i])
                {
                    l = pos[j][i - 1] + 1 , r = h = pos[j][i] - 1;
                    tmp = Query(1 , n , l , r);
                    while (tmp.first <= h)
                        q[tmp.second].ans = j , Update(1 , n , q[tmp.second].l) , tmp = Query(1 , n , l , r);
                }
            if (pos[j][i - 1] != n)
            {
                l = pos[j][i - 1] + 1 , r = h = n;
                tmp = Query(1 , n , l , r);
                while (tmp.first <= h)
                    q[tmp.second].ans = j , Update(1 , n , q[tmp.second].l) , tmp = Query(1 , n , l , r);
            }
        }
        else
        {
            l = 1 , r = h = n;
            tmp = Query(1 , n , l , r);
            while (tmp.first <= h)
                q[tmp.second].ans = j , Update(1 , n , q[tmp.second].l) , tmp = Query(1 , n , l , r);
            break;
        }
    for (i = 1 ; i <= m ; ++ i)
        printf("%d\n" , q[i].ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}
