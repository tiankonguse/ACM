#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 605

int n , a[N][N] , b[N];
vector<int> e[N * N];
int c[N] , d[N] , p[N];
int ans[N][N] , deg[N * N];
void add(int x , int w) {
    for ( ; x <= n ; x += x & -x)
        c[x] += w;
}
int getKth(int k) {
    int x = 0 , i;
    for (i = 9 ; i >= 0 ; -- i) {
        if (x + (1 << i) <= n && c[x + (1 << i)] < k) {
            x += 1 << i;
            k -= c[x];
        }
    }
    return x + 1;
}

void work()
{
    int i , j , x , y , cnt , flag = 0;
    scanf("%d" , &n);
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < n ; ++ j)
            scanf("%d" , &a[i][j]);
    for (j = 0 ; j < n ; ++ j) {
        for (i = 0 ; i < n ; ++ i)
            b[i] = i - a[i][j];
        for (i = 1 ; i <= n ; ++ i)
            c[i] = i & -i;
        for (i = n - 1 ; i >= 0 ; -- i) {
            if (b[i] > i || b[i] < 0) flag = 1;
            x = getKth(b[i] + 1);
            add(x , -1);
            d[x] = i;
        }
        for (i = 2 ; i <= n ; ++ i) {
            e[d[i - 1] * n + j].push_back(d[i] * n + j);
            ++ deg[d[i] * n + j];
        }
    }
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < n ; ++ j)
            scanf("%d" , &a[i][j]);
    for (j = 0 ; j < n ; ++ j) {
        for (i = 0 ; i < n ; ++ i)
            b[i] = i - a[j][i];
        for (i = 1 ; i <= n ; ++ i)
            c[i] = i & -i;
        for (i = n - 1 ; i >= 0 ; -- i) {
            if (b[i] > i || b[i] < 0) flag = 1;
            x = getKth(b[i] + 1);
            add(x , -1);
            d[x] = i;
        }
        for (i = 2 ; i <= n ; ++ i) {
            e[j * n + d[i - 1]].push_back(j * n + d[i]);
            ++ deg[j * n + d[i]];
        }
    }
    stack<int> Q;
    for (i = 0 ; i < n * n ; ++ i)
        if (!deg[i])
            Q.push(i);
    cnt = 0;
    while (!Q.empty()) {
        x = Q.top() , Q.pop();
        ans[x / n][x % n] = ++ cnt;
        for (i = 0 ; i < e[x].size() ; ++ i) {
            y = e[x][i];
            if (!-- deg[y])
                Q.push(y);
        }
    }
    if (flag || cnt != n * n)
        puts("0");
    else {
        for (i = 0 ; i < n ; ++ i) {
            for (j = 0 ; j < n ; ++ j)
                printf("%d%c" , ans[i][j] , " \n"[j + 1 == n]);
        }
    }
}

int main()
{
    work();
    return 0;
}
