#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 405
int n , m , pre[N] , mcnt;
int S , T;
struct edge {
    int x , next;
}e[N * N];
int d[N];
vector<int> res[N];
void work()
{
    int i , j , x , y;
    scanf("%d%d%d%d",&n,&m,&S,&T);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    memset(d , -1 , sizeof(d));
    queue<int> Q;
    Q.push(S) , d[S] = 0;
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        for (i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (!~d[y]) {
                d[y] = d[x] + 1;
                Q.push(y);
            }
        }
    }
    printf("%d\n" , d[T]);
    for (x = 1 ; x <= n ; ++ x)
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x; if (x < y) continue;
            j = min(d[T] , max(d[x] , d[y]));
            res[j].push_back(i >> 1);
        }
    for (i = 1 ; i <= d[T] ; ++ i) {
        printf("%d" , res[i].size());
        sort(res[i].begin() , res[i].end());
        for (j = 0 ; j < res[i].size() ; ++ j)
            printf(" %d" , res[i][j] + 1);
        puts("");
    }
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


