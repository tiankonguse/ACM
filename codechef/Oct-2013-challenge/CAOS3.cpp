#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 25
int n , m;
char s[N][N];
bool g[N][N];
int f[N][N][N][N];
int dfs(int lx , int ly , int rx , int ry)
{
    if (lx > rx || ly > ry) return 0;
    if (~f[lx][ly][rx][ry]) return f[lx][ly][rx][ry];
    set<int> hash;
    for (int i = lx ; i <= rx ; ++ i)
        for (int j = ly ; j <= ry ; ++ j)
            if (g[i][j])
                hash.insert(dfs(lx , ly , i - 1 , j - 1) ^ dfs(lx , j + 1 , i - 1 , ry) ^
                            dfs(i + 1 , ly , rx , j - 1) ^ dfs(i + 1 , j + 1 , rx , ry));
    f[lx][ly][rx][ry] = 0;
    while (hash.count(f[lx][ly][rx][ry]))
        ++ f[lx][ly][rx][ry];
    return f[lx][ly][rx][ry];
}

void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    memset(g , 0 ,sizeof(g));
    for (i = 3 ; i <= n - 2 ; ++ i)
        for (j = 3 ; j <= m - 2 ; ++ j)
        {
            if (s[i][j] == '#' || s[i - 1][j] == '#' || s[i - 2][j] == '#' || s[i + 1][j] == '#' || s[i + 2][j] == '#') continue;
            if (s[i][j - 2] == '#' || s[i][j - 1] == '#' || s[i][j] == '#' || s[i][j + 2] == '#' || s[i][j + 1] == '#') continue;
            g[i][j] = 1;
        }
    memset(f , -1 , sizeof(f));
    puts(dfs(1 , 1 , n , m) ? "Asuna" : "Kirito");
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //freopen("~output.txt" , "w" , stdout);
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
