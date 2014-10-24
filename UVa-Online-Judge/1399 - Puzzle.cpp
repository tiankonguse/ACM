#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
#define N 500005
int n , m;
struct ACautomaton
{
    int nodecnt;
    int u[N][26] , f[N];
    bool ban[N];
    queue<int> q;
    int newnode() {
        ban[nodecnt] = 0;
        memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
        return nodecnt ++;
    }
    void clear() {
        nodecnt = 0;
        newnode();
    }
    void insert(char str[]) {
        int x = 0;
        for (int i = 0 ; str[i] ; ++ i) {
            int c = str[i] - 'A';
            if (!u[x][c])
                u[x][c] = newnode();
            x = u[x][c];
        }
        ban[x] = 1;
    }
    void getFail() {
        for (int i = 0 ; i < m ; ++ i)
            if (u[0][i])
                f[u[0][i]] = 0 , q.push(u[0][i]);
        while (!q.empty()) {
            int x = q.front() ; q.pop();
            for (int i = 0 ; i < m ; ++ i) {
                int y = u[x][i];
                if (!y) {u[x][i] = u[f[x]][i]; continue;}
                q.push(y); int j = f[x];
                while (j && !u[j][i]) j = f[j];
                f[y] = u[j][i] , ban[y] |= ban[f[y]];
            }
        }
    }
}T;

char str[100];
bool use[N];
int deg[N] , f[N];
queue<int> Q;
vector<int> ans , e[N];

void work()
{
    int i , j , x , y , cnt;
    scanf("%d%d",&m,&n);
    T.clear();
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , str) , T.insert(str);
    T.getFail();
    memset(deg , 0 , sizeof(deg));
    memset(use , 0 , sizeof(use));
    Q.push(0) , use[0] = 1 , cnt = 0;
    while (!Q.empty())
    {
        x = Q.front() , Q.pop() , ++ cnt;
        for (i = 0 ; i < m ; ++ i)
        {
            y = T.u[x][i];
            if (!T.ban[y])
            {
                if (!use[y])
                    use[y] = 1 , Q.push(y);
            }
        }
    }
    for (i = 0 ; i < T.nodecnt ; ++ i) if (use[i])
        for (j = 0 ; j < m ; ++ j)
        {
            x = T.u[i][j];
            if (use[x])
                ++ deg[x];
        }
    memset(f , 0x80 , sizeof(f));
    if (deg[0])
    {
        puts("No");
        return;
    }
    Q.push(0) , f[0] = 0;
    while (!Q.empty())
    {
        x = Q.front() , Q.pop() , -- cnt;
        for (i = 0 ; i < m ; ++ i)
        {
            y = T.u[x][i];
            if (use[y])
            {
                f[y] = max(f[y] , f[x] + 1);
                if (!-- deg[y])
                    Q.push(y);
            }
        }
    }
    if (cnt < 0) while (1);
    if (cnt != 0)
    {
        puts("No");
        return;
    }
    int res = 0;
    ans.clear();
    for (i = 0 ; i < T.nodecnt ; ++ i)
        res = max(res , f[i]);
    if (!res)
    {
        puts("No");
        return;
    }
    for (i = 0 ; i < T.nodecnt ; ++ i)
        if (f[i] == res)
            ans.push_back(i);
    for (i = 0 ; i < T.nodecnt ; ++ i)
        if (use[i])
            e[i].clear();
    memset(deg , 0 , sizeof(deg));
    for (i = 0 ; i < T.nodecnt ; ++ i) if (use[i])
        for (j = 0 ; j < m ; ++ j)
        {
            x = T.u[i][j];
            if (use[x])
                ++ deg[i] , e[x].push_back(i);
        }
    memset(f , 0x80 , sizeof(f));
    for (i = 0 ; i < ans.size() ; ++ i)
        Q.push(ans[i]) , f[ans[i]] = 0;
    while (!Q.empty())
    {
        x = Q.front() , Q.pop();
        for (i = 0 ; i < e[x].size() ; ++ i)
        {
            y = e[x][i];
            f[y] = max(f[y] , f[x] + 1);
            if (!-- deg[y])
                Q.push(y);
        }
    }
    //printf("%d\n" , f[0]);
    x = 0;
    while (f[x])
    {
        for (i = m - 1 ; i >= 0 ; -- i)
            if (f[x] == f[T.u[x][i]] + 1)
            {
                putchar('A' + i);
                x = T.u[x][i];
                break;
            }
    }
    puts("");
}
int main()
{
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%s", s) , *s != '.')
        work();
    return 0;
}
