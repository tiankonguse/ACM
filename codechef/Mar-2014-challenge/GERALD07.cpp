#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 200005
#define NUM 256
int n , m , q , B;
struct query{
    int l , r , id;
    query(int _l , int _r , int _id) {
        l = _l , r = _r , id = _id;
    }
    bool operator < (const query& R) const{
        return r < R.r;
    }
};
int ans[N];
pair<int , int> e[N];
vector<query> Q[N / NUM + 1];

int f[N] , g[N] , t[N] , globe , cnt;
int getf(int x) {return f[x] == x ? x : f[x] = getf(f[x]);}
void merge(int x , int y) {
    int xx = getf(x) , yy = getf(y);
    if (xx != yy) {
        ++ cnt , f[xx] = yy;
    }
}
int getg(int x)
{
    if (t[x] != globe) {
        t[x] = globe;
        if (f[x] == x)
            g[x] = x;
        else
            g[x] = getg(getf(f[x]));
        return g[x];
    }
    return g[x] == x ? x : g[x] = getg(g[x]);
}

void MERGE(int x , int y) {
    int xx = getg(x) , yy = getg(y);
    if (xx != yy) {
        ++ cnt;
        g[xx] = yy;
    }
}

void answer(int id , query Q){
    int size = (id + 1) * NUM , tmp = cnt;
    globe = Q.id;
    for (int i = Q.l ; i < size && i <= Q.r ; ++ i)
        MERGE(e[i].first , e[i].second);
    ans[Q.id] = n - cnt;
    cnt = tmp;
}

void work()
{
    int i , k , x , y , r;
    scanf("%d%d%d",&n,&m,&q);
    B = (m + NUM - 1) / NUM;
    for (i = 0 ; i < B ; ++ i)
        Q[i].clear();
    memset(t , 0 , sizeof(int) * (n + 1));
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d",&e[i].first , &e[i].second);
    for (i = 1 ; i <= q ; ++ i)
    {
        scanf("%d%d",&x,&y);
        -- x , -- y;
        Q[x / NUM].push_back(query(x , y , i));
    }

    for (k = 0 ; k < B ; ++ k) {
        if (!Q[k].size()) continue;
        sort(Q[k].begin() , Q[k].end());
        for (i = 1 ; i <= n ; ++ i) f[i] = i;
        r = (k + 1) * NUM , cnt = 0;
        for (i = 0 ; i < Q[k].size() ; ++ i) {

            while (r <= Q[k][i].r) {
                merge(e[r].first , e[r].second);
                ++ r;
            }
            answer(k , Q[k][i]);
        }
    }
    for (i = 1 ; i <= q ; ++ i)
        printf("%d\n" , ans[i]);
}


int main()
{
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
