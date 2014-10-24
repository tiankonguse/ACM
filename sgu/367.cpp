#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<queue>
#include<vector>
using namespace std;

typedef long long LL;
#define N 1005
int n , m , P , T[N] , mcnt , pre[N];
struct edge {
    int x , next;
}e[N * 20];
int deg[N];
priority_queue< pair<int , int> > Q;

int main()
{
    int i , j , x , y , z;
    scanf("%d%d",&n,&P);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&T[i]);
    scanf("%d",&m);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        ++ deg[y];
    }
    for (i = 1 ; i <= n ; ++ i)
        if (!deg[i])
            Q.push(make_pair(-T[i] , i));
    LL cnt = 0 , ans = 0;
    vector<int> res;
    while (!Q.empty()) {
        x = Q.top().second , Q.pop();
        if (cnt + T[x] > P) break;
        res.push_back(x) , cnt += T[x] , ans += cnt;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x;
            if (! -- deg[y]) {
                Q.push(make_pair(-T[y] , y));
            }
        }
    }
    cout << res.size() << ' ' << ans << endl;
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
    return 0;
}
