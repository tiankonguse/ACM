#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
#define N 30005
int n , m , pre[N] , mcnt , K;
struct edge
{
    int x , w , next;
}e[N << 2];
int A[N << 1] , B[N << 1] , C[N << 1];
int d[N] , tot , s[N];
bool f[N];

pair<int , pair<int , int>  > a[N];
pair<int , int> ans , hash[N];
void update(pair<int , int>& x , pair<int , int> y)
{
    if (y.first > x.first)
        x = y;
    else if (y.first == x.first)
        x.second += y.second;
}
vector<int> upd;
pair<int , int> Find(int x , int fa , int cnt)
{
    s[x] = 1; int m = 0;
    pair<int , int> res = make_pair(1 << 30 , -1);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x] && e[i].x != fa)
        {
            res = min(res , Find(e[i].x , x , cnt));
            m = max(s[e[i].x] , m);
            s[x] += s[e[i].x];
        }
    m = max(m , cnt - s[x]);
    return res = min(res , make_pair(m , x));
}
void Getdis(int x , int fa , int w , int dep)
{
    a[tot ++] = make_pair(x , make_pair(w , dep));
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x] && e[i].x != fa)
            Getdis(e[i].x , x , w + e[i].w , dep + 1);
}
void divide(int x , int cnt)
{
    int i , j;
    x = Find(x , 0 , cnt).second , f[x] = 1;
    hash[0] = make_pair(0 , 1) , upd.push_back(0);
    for (i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x])
        {
            tot = 0;
            Getdis(e[i].x , x , e[i].w , 1);
            s[e[i].x] = tot;
            for (j = 0 ; j < tot ; ++ j)
            {
                int w = K - a[j].second.second;
                if (w >= 0 && hash[w].first != -1 << 30)
                    update(ans , make_pair(a[j].second.first + hash[w].first , hash[w].second));
            }
            for (j = 0 ; j < tot ; ++ j)
                update(hash[a[j].second.second] , make_pair(a[j].second.first , 1)) , upd.push_back(a[j].second.second);
        }
    while (!upd.empty())
        hash[upd.back()] = make_pair(-1 << 30 , 0) , upd.pop_back();
    for (i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x])
            divide(e[i].x , s[e[i].x]);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);

    int i , x , y , z;

    scanf("%d%d%d",&n,&m,&K) , -- K;
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
    }
    memset(d , 0x7F , sizeof(d));
    queue<int> Q; Q.push(1) , d[1] = 0 , f[1] = 1;

    while (!Q.empty())
    {
        x = Q.front() , Q.pop() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next)
        {
            y = e[i].x , z = e[i].w;
            if (d[x] + z < d[y])
            {
                d[y] = d[x] + z;
                if (!f[y])
                    f[y] = 1 , Q.push(y);
            }
        }
    }
    priority_queue<int , vector<int> , greater<int> > QQ;
    QQ.push(1) , m = 0 , f[1] = 1;
    while (!QQ.empty())
    {
        x = QQ.top() , QQ.pop();
        for (i = pre[x] ; ~i ; i = e[i].next)
        {
            y = e[i].x , z = e[i].w;
            if (d[x] + z == d[y] && !f[y])
            {
                f[y] = 1;
                A[m] = x , B[m] = y , C[m ++] = z;
                QQ.push(y);
            }
        }
    }
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 0 ; i < m ; ++ i)
    {
        x = A[i] , y = B[i] , z = C[i];
        //printf("%d %d %d\n" , x , y , z);
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
    }
    memset(f , 0 , sizeof(f));
    for (i = 0 ; i <= n ; ++ i)
        hash[i] = make_pair(-1 << 30 , 0);
    ans = make_pair(-1 << 30 , 0);
    divide(1 , n);
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}
