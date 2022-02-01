#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
#define N 105
int n , m , ca;
LL f[26][N][1 << 10];
struct ACautomaton
{
    int nodecnt;
    int u[N][26] , f[N];
    int val[N];
    queue<int> q;
    inline int newnode() {
        val[nodecnt] = 0;
        memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
        return nodecnt ++;
    }
    void clear() {
        nodecnt = 0;
        newnode();
    }
    void insert(char str[] , int id) {
        int x = 0;
        for (int i = 0 ; str[i] ; ++ i) {
            int c = str[i] - 'a';
            if (!u[x][c])
                u[x][c] = newnode();
            x = u[x][c];
        }
        val[x] |= 1 << id;
    }
    void getFail() {
        for (int i = 0 ; i < 26 ; ++ i)
            if (u[0][i])
                f[u[0][i]] = 0 , q.push(u[0][i]);
        while (!q.empty()) {
            int x = q.front() ; q.pop();
            for (int i = 0 ; i < 26 ; ++ i) {
                int y = u[x][i];
                if (!y) {u[x][i] = u[f[x]][i]; continue;}
                q.push(y); int j = f[x];
                while (j && !u[j][i]) j = f[j];
                f[y] = u[j][i] , val[y] |= val[f[y]];
            }
        }
    }
}T;
char str[30];

LL F(int i , int j , int k)
{
    if (~f[i][j][k]) return f[i][j][k];
    if (i == n && k + 1 == (1 << m)) return 1;
    if (i == n) return 0;
    LL& a = f[i][j][k]; a = 0;
    for (int c = 0 ; c < 26 ; ++ c)
    {
        int x = T.u[j][c];
        a += F(i + 1 , x , k | T.val[x]);
    }
    return a;
}
vector<string> PA[26][N][1 << 10];
vector<string> dfs(int i , int j , int k)
{
    vector<string> emp;
    if (f[i][j][k]) return PA[i][j][k];
    f[i][j][k] = 1;
    if (i == n && k + 1 == (1 << m))
    {
        emp.push_back("");
        return PA[i][j][k] = emp;
    }
    if (i == n) return PA[i][j][k] = emp;
    string ch = "a";
    for (int c = 0 ; c < 26 ; ++ c)
    {
        int x = T.u[j][c];
        vector<string> tmp = dfs(i + 1 , x , k | T.val[x]);
        for (int ii = 0 ; ii < tmp.size() ; ++ ii)
        {
            emp.push_back(ch + tmp[ii]);
            //if (emp.size() > 16)
            //    return PA[i][j][k] = emp;
        }
        ++ ch[0];
    }
    return PA[i][j][k] = emp;
}

void work()
{
    int i , j , k , c , x;
    T.clear(); printf("Case %d: " , ++ ca);
    for (i = 0 ; i < m ; ++ i)
        scanf("%s" , str) , T.insert(str , i);
    T.getFail();
    memset(f , -1 , sizeof(f));
    LL ans = 0;
    printf("%lld suspects\n" , ans = F(0 , 0 , 0));
    if (ans > 42) return;
    memset(f , 0 , sizeof(f));
    vector<string> res = dfs(0 , 0 , 0);
    for (i = 0 ; i < res.size() ; ++ i)
        puts(res[i].c_str());
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
