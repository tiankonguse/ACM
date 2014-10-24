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

#define N 6005
int n , m , K , C;
int pre[N] , mcnt;
struct edge{
    int x , w , next;
}e[N];
map<string , int> hash;
char s[50];
int L[N];
int d[305][N];
int g[305][305];
queue<int> Q;
bool f[N];
void Bellman_Ford(int st , int* D)
{
    int i , x , y , z;
    for (i = 1 ; i <= n ; ++ i)
        D[i] = 1 << 29 , f[i] = 0;
    D[st] = 0 , f[st] = 1 , Q.push(st);
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

void work()
{
    int i , j , k , x , y , z;
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    hash.clear() , n = 0;
    scanf("%s" , s);
    hash[s] = ++ n;
    scanf("%s" , s);
    hash[s] = ++ n;
    while (m --) {
        scanf("%s" , s);
        if (!hash[s])
            hash[s] = ++ n;
        x = hash[s];
        scanf("%s" , s);
        if (!hash[s])
            hash[s] = ++ n;
        y = hash[s];
        scanf("%d",&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    Bellman_Ford(1 , d[K + 1]) , L[K + 1] = 1;
    Bellman_Ford(2 , d[K + 2]) , L[K + 2] = 2;
    for (i = 1 ; i <= K ; ++ i){
        scanf("%s" , s);
        L[i] = hash[s];
        Bellman_Ford(L[i] , d[i]);
    }
    for (i = 1 ; i <= K + 2 ; ++ i)
        for (j = 1 ; j <= K + 2 ; ++ j)
            if (d[i][L[j]] <= C * 10)
                g[i][j] = d[i][L[j]];
            else
                g[i][j] = 1 << 29;
    for (k = 1 ; k <= K + 2 ; ++ k)
        for (i = 1 ; i <= K + 2 ; ++ i)
            for (j = 1 ; j <= K + 2 ; ++ j)
                g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
    if (g[K + 1][K + 2] >= 1 << 29)
        printf("-1\n");
    else
        printf("%d\n" , g[K + 1][K + 2]);
}

int main()
{
    while (scanf("%d%d%d",&m,&K,&C) , K || m || C)
        work();
    return 0;
}
