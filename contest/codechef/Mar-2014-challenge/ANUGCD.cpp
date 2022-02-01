#include <iostream>
#include <cstdio>
using namespace std;
#define N 100005
int n , q;
bool f[N];
int prime[N] , tot;
int fac[N][6] , cnt[N];
void init()
{
    int i , j ;n = 100000;
    for (i = 2 ; i * i <= n ; ++ i) if (!f[i])
        for (j = i * i ; j <= n ; j += i) f[j] = 1;
    for (i = 2 ; i <= n ; ++ i) if (!f[i]) prime[tot ++] = i;
    for (i = 0 ; i < tot ; ++ i)
        for (j = prime[i] ; j <= n ; j += prime[i])
            fac[j][cnt[j] ++] = i;
}
#define M 10000005
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
int nodecnt;
pair<int , int> val[M] , ans;
int ch[M][2];
int root[N];
inline int newnode() {
    return ++ nodecnt;
}
pair<int , int> merge(pair<int , int> A , pair<int , int> B) {
    pair<int , int> C;
    C = max(A , B) , C.second = 0;
    if (C.first == A.first) C.second += A.second;
    if (C.first == B.first) C.second += B.second;
    return C;
}
void insert(int& p , int l , int r , int x , int w)
{
    if (!p) p = newnode();
    if (l == r){
        val[p] = make_pair(w , 1);
        return;
    } MID;
    if (x <= mid)
        insert(ch[p][0] , Left , x , w);
    else
        insert(ch[p][1] , Right , x , w);
    val[p] = merge(val[ch[p][0]] , val[ch[p][1]]);
}
pair<int , int> query(int p , int l , int r , int top , int bot)
{
    if (!p) return make_pair(0 , 0);
    if (top <= l && r <= bot) return val[p]; MID;
    if (bot <= mid) return query(ch[p][0] , Left , top , bot);
    if (top > mid) return query(ch[p][1] , Right , top , bot);
    return merge(query(ch[p][0] , Left , top , bot) , query(ch[p][1] , Right , top , bot));
}

void work()
{
    int i , j , k , x , y , z;
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%d",&x);
        for (j = 0 ; j < cnt[x] ; ++ j)
            insert(root[fac[x][j]] , 1 , n , i , x);
    }
    while (q --)
    {
        scanf("%d%d%d",&x,&y,&z);
        ans = make_pair(0 , 0);
        for (j = 0 ; j < cnt[x] ; ++ j)
            ans = max(ans , query(root[fac[x][j]] , 1 , n , y , z));
        if (!ans.first)
            puts("-1 -1");
        else
            printf("%d %d\n" , ans.first , ans.second);
    }
}

int main()
{
    init();
    if (~scanf("%d%d",&n,&q))
        work();
    return 0;
}
