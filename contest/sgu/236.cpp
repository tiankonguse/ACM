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
#include <cassert>
using namespace std;
typedef long long LL;

#define N 55
int n , m , pre[N] , mcnt;
struct edge{
    int x , c , t , next;
}e[N * N];

int cnt[N] , p[N];
bool f[N];
double d[N];
bool check(double val) {
    int i , x , y;
    double z;
    queue<int> Q;
    for (i = 1 ; i <= n; ++ i)
        d[i] = 1e30 , f[i] = 0 , cnt[i] = 0;
    Q.push(1) , d[1] = 0 , f[1] = 1;
    while (!Q.empty()) {
        x = Q.front() , Q.pop() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = -e[i].c + val * e[i].t;
            if (d[x] + z < d[y]) {
                d[y] = d[x] + z;
                if (!f[y]) {
                    f[y] = 1 , Q.push(y) , p[y] = x;
                    if (++ cnt[y] > n + 1)
                        return y;
                }
            }
        }
    }
    return 0;
}

void work()
{
    int i , x , y , z , w;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d%d",&x,&y,&z,&w);
        e[mcnt] = (edge) {y , z , w , pre[x]} , pre[x] = mcnt ++;
    }
    double top = 0 , bot = 233.0 , mid;
    while (bot - top > 1e-12) {
        mid = (top + bot) * 0.5;
        if (check(mid))
            top = mid;
        else
            bot = mid;
    }
    x = y = check(top);
    if (!x) {
        puts("0");
        return;
    }
    vector<int> res;
    memset(cnt , 0 , sizeof(cnt));
    while (cnt[x] <= 1) {
        ++ cnt[x];
        if (cnt[x] == 2)
            res.push_back(x);
        x = p[x];
    }
    /*do {
        res.push_back(x);
        x = p[x];
    }while (x != y);*/
    reverse(res.begin() , res.end());
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


