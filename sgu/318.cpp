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
#define N 5005
#define M 100005
int n , m;
LL a[N] , b[N];
int f[N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}

void work()
{
    int i , j , x;
    scanf("%d%d",&m,&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&j);
        while (j --) {
            scanf("%d",&x);
            if (i < 50)
                a[x] |= 1LL << i;
            else
                b[x] |= 1LL << i - 50;
        }
    }
    for (i = 1 ; i <= m ; ++ i)
        f[i] = i;
    for (i = 1 ; i <= m ; ++ i)
        for (j = i + 1 ; j <= m ; ++ j)
            if (a[i] == a[j] && b[i] == b[j])
                f[getf(i)] = getf(j);
    set<int> res;
    for (i = 1 ; i <= m ; ++ i)
        if (a[i] || b[i])
            res.insert(getf(i));
    cout << res.size() << endl;
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

