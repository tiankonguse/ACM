
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
#include <cassert>
using namespace std;
typedef long long LL;

#define N 2005
int n , m , K , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N * N / 2];
int s , t;
int d1[N] , d2[N] , ans[N];
bool f[N];
queue<int> Q;
pair<int , int> E[N * N / 2];
void Bellman_Ford(int S , int* D) {
    int i , x , y , z;
    for (i = 1 ; i <= n ; ++ i)
        D[i] = 1 << 30 , f[i] = 0;
    Q.push(S) , D[S] = 0 , f[S] = 1;
    while (!Q.empty()) {
        x = Q.front() , Q.pop() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = e[i].w;
            if (D[x] + z < D[y]) {
                D[y] = D[x] + z;
                if (!f[y]) {
                    f[y] = 1;
                    Q.push(y);
                }
            }
        }
    }
}

void work() {
    int i , x , y , z;
    scanf("%d%d%d%d",&n,&s,&t,&m);
    memset(pre , -1,  sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    Bellman_Ford(s , d1);
    Bellman_Ford(t , d2);
    int mindis = d1[t];
    for (x = 1 ; x <= n ; ++ x) {
        if (d1[x] + d2[x] != mindis)
            continue;
        E[K ++] = make_pair(d1[x] , -n - n);
        E[K ++] = make_pair(d1[x] , n + n);
        E[K ++] = make_pair(d1[x] , x);
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = e[i].w;
            if (d1[y] + d2[y] != mindis)
                continue;
            if (d1[x] + z + d2[y] != mindis)
                continue;
            E[K ++] = make_pair(d1[x] + 1 , -n - n);
            E[K ++] = make_pair(d1[y] - 1 , n + n);
        }
    }
    sort(E , E + K);
    int sum = 0;
    for (i = 0 ; i < K ; ++ i) {
        if (E[i].second == n + n)
            -- sum;
        else if (E[i].second == -n - n)
            ++ sum;
        else
            ans[E[i].second] = sum;
    }
    for (i = 1 ; i <= n ; ++ i)
        printf("%d%c" , ans[i] , " \n"[i == n]);
}


int main(){
    work();
    return 0;
}
