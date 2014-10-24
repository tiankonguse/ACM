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

#define N 1005
int n , a[N];
int f[N];
void work()
{
    int i , j , cnt = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    if (a[1] != 2) {
        f[1] = 0;
        for (i = 2 ; i <= n ; ++ i) {
            f[i] = a[i - 1] - f[i - 1] - f[i - 2];
            if (f[i] > 1 || f[i] < 0) break;
        }
        if (i > n && f[n] + f[n - 1] == a[n])
            ++ cnt;
    }
    memset(f , 0 , sizeof(f));
    f[1] = 1;
    for (i = 2 ; i <= n ; ++ i) {
        f[i] = a[i - 1] - f[i - 1] - f[i - 2];
        if (f[i] > 1 || f[i] < 0) break;
    }
    if (i > n && f[n] + f[n - 1] == a[n])
        ++ cnt;
    cout << cnt << endl;
}

int main()
{
    work();
    return 0;
}

