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
using namespace std;
typedef long long LL;
#define N 200005
int n ,  m , L , ca;
map<char , int> dict;
double p[100];
bool vis[505][105];
double dp[505][105];
struct ACautomaton
{
    int nodecnt;
    int u[N][62] , f[N];
    bool val[N];
    queue<int> q;
    int newnode() {
        val[nodecnt] = 0;
        memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
        return nodecnt ++;
    }
    void clear() {
        nodecnt = 0;
        newnode();
    }
    void insert(char *str) {
        int x = 0;
        for (int i = 0 ; str[i] ; ++ i) {
            int c = dict[str[i]];
            if (!u[x][c])
                u[x][c] = newnode();
            x = u[x][c];
        }
        val[x] = 1;
    }
//    int query(char *str) {
//        int x = 0;
//        for (int i = 0 ; str[i] ; ++ i) {
//            int c = str[i] - 'a';
//            x = u[x][c] , val[x].query();
//        }
//    }
    void getFail() {
        for (int i = 0 ; i < n ; ++ i)
            if (u[0][i])
                f[u[0][i]] = 0 , q.push(u[0][i]);
        while (!q.empty()) {
            int x = q.front() ; q.pop();
            for (int i = 0 ; i < n ; ++ i) {
                int y = u[x][i];
                if (!y) {u[x][i] = u[f[x]][i]; continue;}
                q.push(y); int j = f[x];
                while (j && !u[j][i]) j = f[j];
                f[y] = u[j][i] , val[y] |= val[f[y]];
            }
        }
    }
    double F(int x , int len)
    {
        if (val[x]) return 0;
        if (!len) return 1;
        if (vis[x][len]) return dp[x][len];
        vis[x][len] = 1; double& a = dp[x][len];
        a = 0;
        for (int i = 0 ; i < n ; ++ i)
            a += p[i] * F(u[x][i] , len - 1);
        return a;
    }
}heap;
char str[5] , t[25][25];
void work()
{
    int i , cnt = 0;
    heap.clear();
    scanf("%d",&m);
    for (i = 0 ; i < m ; ++ i)
        scanf("%s" , t[i]);
    scanf("%d",&n) , dict.clear();
    for (i = 0 ; i < n ; ++ i)
        scanf("%s %lf" , str , &p[i]) , dict[*str] = cnt ++;
    for (i = 0 ; i < m ; ++ i)
       heap.insert(t[i]);
    heap.getFail();
    scanf("%d" , &L);
    memset(vis , 0 , sizeof(vis));
    printf("Case #%d: %f\n" , ++ ca , heap.F(0 , L));
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%d",&n) , n)
        work();
    return 0;
}
