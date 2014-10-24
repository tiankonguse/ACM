#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 10005
int n , B , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int size[N] , ans;
int cnt[N] , capital[N] , bel[N];
stack<int> S;

void dfs(int x , int fa) {
    size[x] = 1 , S.push(x);
    int now = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
            now += size[y];
            if (now >= B) {
                ++ ans;
                cnt[ans] = now;
                capital[ans] = x;
                while (S.top() != x) {
                    bel[S.top()] = ans;
                    S.pop();
                }
                now = 0;
            }
        }
    }
    size[x] += now;
}

void work() {
    int i , x , y;
    scanf("%d%d",&n,&B);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    if (n < B) {
        puts("0");
        return;
    }
    if (!S.empty()) {
        if (!ans) {
            ++ ans;
            capital[ans] = S.top();
        }
        while (!S.empty()) {
            bel[S.top()] = ans , S.pop();
        }
    }
    printf("%d\n" , ans);
    for (i = 1 ; i <= n ; ++ i)
        printf("%d%c" , bel[i] , " \n"[i == n]);
    for (i = 1 ; i <= ans ; ++ i)
        printf("%d%c" , capital[i] , " \n"[i == ans]);
}

int main()
{
    work();
    return 0;
}
