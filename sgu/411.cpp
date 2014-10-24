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
typedef unsigned long long ULL;
using namespace std;
#define N 2005
int n , m;
char s[N] , t[N];
ULL AL[N] , BL[N] , AR[N] , BR[N];
ULL power[N] , v[N] , MAGIC = 29;

void work() {
    int i , j , k; ULL x , y;
    scanf("%s%s" , s + 1 , t + 1);
    n = strlen(s + 1) , m = strlen(t + 1);
    power[0] = 1;
    for (i = 1 ; i <= n || i <= m ; ++ i)
        power[i] = power[i - 1] * MAGIC;
    for (i = 1 ; i <= n ; ++ i)
        AL[i] = AL[i - 1] * MAGIC + s[i] - 'a' + 1;
    for (i = n ; i > 0 ; -- i)
        AR[i] = AR[i + 1] * MAGIC + s[i] - 'a' + 1;
    for (i = 1 ; i <= m ; ++ i)
        BL[i] = BL[i - 1] * MAGIC + t[i] - 'a' + 1;
    for (i = m ; i > 0 ; -- i)
        BR[i] = BR[i + 1] * MAGIC + t[i] - 'a' + 1;
    for (k = min(n , m) ; k >= 1 ; -- k) {
        j = 0;
        for (i = 1 ; i + k - 1 <= n ; ++ i) {
            x = AL[i + k - 1] - power[k] * AL[i - 1];
            y = AR[i] - power[k] * AR[i + k];
            if (x == y)
                v[j ++] = x;
        }
        sort(v , v + j);
        for (i = 1 ; i + k - 1 <= m ; ++ i) {
            x = BL[i + k - 1] - power[k] * BL[i - 1];
            y = BR[i] - power[k] * BR[i + k];
            if (x == y) {
                if (*lower_bound(v , v + j , x) == x)
                    break;
            }
        }
        if (i + k - 1 <= m) {
            t[i + k] = 0;
            puts(t + i);
            break;
        }
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}

