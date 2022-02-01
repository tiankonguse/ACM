#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 18;
int n , m , dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , -1 , 0 , 1};
char s[N][N];
pair<int , int> S[N] , T[N];
int d[N][N][N][N];
int f[N][1 << 15];

void BFS(int x , int y , int D[N][N]) {
    queue< pair<int , int> > Q;
    Q.push(make_pair(x , y)) , D[x][y] = 0;
    while (!Q.empty()) {
        x = Q.front().first , y = Q.front().second , Q.pop();
        for (int i = 0 ; i < 4 ; ++ i) {
            int X = x + dx[i] , Y = y + dy[i];
            if (s[X][Y] != '.') continue;
            if (D[X][Y] == 0x3f3f3f3f) {
                D[X][Y] = D[x][y] + 1;
                Q.push(make_pair(X , Y));
            }
        }
    }
}

void work() {
    int i , j , x;
    memset(s , 0 , sizeof(s));
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d%d%d" , &S[i].first , &S[i].second , &T[i].first , &T[i].second);
    memset(d , 63 , sizeof(d));
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            if (s[i][j] == '.')
                BFS(i , j , d[i][j]);
    memset(f , 63 , sizeof(f));
    for (i = 0 ; i < m ; ++ i)
        f[i][1 << i] = 0;
    for (i = 0 ; i < 1 << m ; ++ i)
        for (j = 0 ; j < m ; ++ j)
            if (f[j][i] != 0x3f3f3f3f)
                for (x = 0 ; x < m ; ++ x)
                    if (~i >> x & 1)
                        f[x][i ^ (1 << x)] = min(f[x][i ^ (1 << x)] , f[j][i] + d[T[j].first][T[j].second][S[x].first][S[x].second]);
    int ans = 1 << 30;
    for (i = 0 ; i < m ; ++ i)
        ans = min(ans , f[i][(1 << m) - 1]);
    if (ans >= 0x3f3f3f3f) ans = -1;
    printf("%d\n" , ans);
}


int main()
{
    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
