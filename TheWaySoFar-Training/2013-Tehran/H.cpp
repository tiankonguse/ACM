#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
typedef long long LL;

#define N 505
int n , m , K , L , U;
int pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N * N * 10];

void addarc(int x , int y , int z) {
    e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
}

stack<int> Q;
int d[N] , cnt[N];
bool f[N];

bool Bellman_Ford() {
    while (!Q.empty()) Q.pop();
    int i , x , y , z;
    for (i = 1 ; i <= n ; ++ i)
        d[i] = 0 , f[i] = 1 , Q.push(i) , cnt[i] = 0;
    while (!Q.empty()) {
        x = Q.top() , Q.pop() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = e[i].w;
            if (d[x] + z < d[y]) {
                d[y] = d[x] + z;
                if (!f[y]) {
                    f[y] = 1;
                    if (++ cnt[y] > n)
                        return 1;
                    Q.push(y);
                }
            }
        }
    }
    return 0;
}

void work() {
    int i , j , x , y;
    scanf("%d%d%d%d",&m,&K,&L,&U);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        // L <= dy - dx <= U
        addarc(x , y , U);
        addarc(y , x , -L);
    }
    for (i = 1 ; i <= K ; ++ i) {
        scanf("%d%d",&x,&y);
        // L <= dy - dx <= U
        addarc(x , y , 0);
        addarc(y , x , 0);
    }
    if (Bellman_Ford()) {
        puts("Impossible");
        return;
    }
    int mx = -1 << 30 , mn = 1 << 30;
    for (i = 1 ; i <= n ; ++ i)
        mx = max(mx , d[i]) , mn = min(mn , d[i]);
    printf("%d\n" , mx - mn);
}

int main(){
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
