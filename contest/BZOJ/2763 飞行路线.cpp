#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
#define N 10005
int n , m , K , pre[N] , mcnt;
struct edge
{
    int x , w , next;
}e[N * 10];

int d[11][N] , S , T;
bool f[11][N];

struct node
{
    int k , x , w;
    bool operator < (const node& r) const{
        return w > r.w;}
};
priority_queue<node> Q;

void update(int j , int x , int w)
{
    if (w < d[j][x] && j <= K)
        d[j][x] = w , Q.push((node){j , x , w});
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int i , j , x , y , z , ans = 0x7f7f7f7f;
    scanf("%d%d%d%d%d",&n,&m,&K,&S,&T);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    memset(d , 0x7F , sizeof(d));
    Q.push((node){0 , S , 0}) , d[0][S] = 0;
    while (!Q.empty())
    {
        x = Q.top().x , j = Q.top().k , z = Q.top().w , Q.pop();
        if (z > d[j][x]) continue;
        //printf("%d %d %d\n" ,j , x , z);
        if (x == T) ans = min(ans , z);
        for (i = pre[x] ; ~i ; i = e[i].next)
            update(j , e[i].x , z + e[i].w) ,
            update(j + 1 , e[i].x , z) ;
    }
    printf("%d\n" , ans);
    return 0;
}
