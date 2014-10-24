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

#define N 500005
int n , f[N];
int ans[N] , sum;
bool u[N];
void work()
{
    int i;
    scanf("%d",&n);
    for (i = 2 ; i <= n ; ++ i) {
        scanf("%d",&f[i]);
    }
    for (i = n ; i > 0 ; -- i) {
        if (!u[i] && !u[f[i]]) {
            u[i] = u[f[i]] = 1;
            ans[sum ++] = i;
        }
    }
    printf("%d\n" , sum * 1000);
    for (i = sum - 1 ; i >= 0 ; -- i) {
        printf("%d%c" , ans[i] , " \n"[!i]);
    }
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


