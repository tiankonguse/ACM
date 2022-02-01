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
#define N 105
int n;
LL a[N] , res;

void work()
{
    int i , j ; LL x;
    res = 0;
    for (i = 0 ; i < n ; ++ i)
        scanf("%lld",&a[i]);
    for (j = 59 ; j >= 0; -- j) {
        for (i = 0 ; i < n ; ++ i)
            if (a[i] >> j & 1) {
                x = a[i];
                break;
            }
        if (i < n) {
            if (~res >> j & 1)
                res ^= x;
            for ( ; i < n ; ++ i)
                if (a[i] >> j & 1)
                    a[i] ^= x;
        }
    }
    cout << res << endl;
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    while (~scanf("%d",&n))
        work();
    return 0;
}


