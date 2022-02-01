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
int ans[150];
map<int , int> LOG;
struct five
{
    int a[5];
    five () {memset(a , 0 , sizeof(a));}
    void update(five R) {
        for (int i = 0 ; i < 4 ; ++ i)
            a[i] |= R.a[i];
    }
    void insert(int x) {
        a[x / 30] |= 1 << (x % 30);
    }
    void query() {
        for (int i = 0 ; i < 5 ; ++ i)
            for (int j = a[i] ; j ; j &= j - 1)
                ++ ans[30 * i + LOG[j & -j]];
    }
};

struct ACautomaton
{
    int nodecnt;
    int u[N][26] , f[N];
    five val[N];
    queue<int> q;
    int newnode() {
        val[nodecnt] = five();
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
        val[x].insert(id);
    }
    int query(char *str) {
        int x = 0;
        for (int i = 0 ; str[i] ; ++ i) {
            int c = str[i] - 'a';
            x = u[x][c] , val[x].query();
        }
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
                f[y] = u[j][i] , val[y].update(val[f[y]]);
            }
        }
    }
}heap;
int n ;
char s[150][75] , str[1000005];
void work()
{
    heap.clear();
    memset(ans , 0 , sizeof(ans));
    for (int i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]) , heap.insert(s[i] , i);
    heap.getFail();
    scanf("%s" , str) , heap.query(str);
    int res = 0;
    for (int i = 0 ; i < n ; ++ i)
        res = max(ans[i] , res);
    printf("%d\n" , res);
    for (int i = 0 ; i < n ; ++ i)
        if (ans[i] == res)
            puts(s[i]);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    for (int i = 0 ; i < 30 ; ++ i)
        LOG[1 << i] = i;
    //int _; scanf("%d",&_); while (_ --)
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
