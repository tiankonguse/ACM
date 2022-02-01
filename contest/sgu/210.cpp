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

#define N 505
int n , pre[N] , mcnt;
pair<int , int> a[N];
struct edge {
    int x , next;
}e[N * N];
int re[N] , er[N];
bool f[N] , u[N];

bool find(int x) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y]) {
            f[y] = 1;
            if (!re[y] || find(re[y])) {
                re[y] = x , er[x] = y;
                return 1;
            }
        }
    }
    return 0;
}

void work()
{
    int i , j , x;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i].first) , a[i].second = i;
    }
    sort(a + 1 , a + n + 1 , greater< pair<int , int> >());
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&j);
        while (j --) {
            scanf("%d",&x);
            e[mcnt] = (edge) {x , pre[i]} , pre[i] = mcnt ++;
        }
    }
    for (i = 1 ; i <= n ; ++ i) {
        memset(f , 0 , sizeof(f));
        u[a[i].second] = find(a[i].second);
    }
    for (i = 1 ; i <= n ; ++ i) {
        printf("%d%c" , er[i] , " \n"[i == n]);
    }
}


int main()
{
    work();
    return 0;
}
