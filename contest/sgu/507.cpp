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
#include <set>
#include <map>
typedef long long LL;
using namespace std;

#define N 50005

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N];
int a[N] , ans[N];
multiset<int> h[N];

void dfs(int x) {
    if (!~pre[x]) {
        h[x].insert(a[x]);
        return;
    }
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        dfs(y);
        ans[x] = min(ans[x] , ans[y]);
        if (h[x].size() < h[y].size())
            swap(h[x] , h[y]);
        for (multiset<int>::iterator it = h[y].begin() , it2 ; it != h[y].end() ; ++ it) {
            it2 = h[x].lower_bound(*it);
            if (it2 != h[x].end())
                ans[x] = min(ans[x] , *it2 - *it);
            if (it2 != h[x].begin()) {
                -- it2;
                ans[x] = min(ans[x] , *it - *it2);
            }
            h[x].insert(*it);
        }
        h[y].clear();
    }
}

void work()
{
    int i , x;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 2 ; i <= n ; ++ i) {
        scanf("%d",&x);
        e[mcnt] = (edge) {i , pre[x]} , pre[x] = mcnt ++;
    }
    for (i = n - m + 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= n ; ++ i)
        ans[i] = 2147483647;
    dfs(1);
    for (i = 1 ; i <= n - m ; ++ i)
        printf("%d%c" , ans[i] , " \n"[i == n - m]);
}

int main()
{
    work();
    return 0;
}

