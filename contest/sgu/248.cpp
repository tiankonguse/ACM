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
#define N 2005
int n , c[N] , V;
int f[10000005];

void work()
{
    int i , j;
    cin >> n;
    for (i = 0 ; i < n ; ++ i)
        cin >> c[i];
    cin >> V;
    memset(f , 63 , sizeof(f));
    f[0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = c[i] ; j <= V ; ++ j)
            f[j] = min(f[j - c[i]] + 1 , f[j]);
    }
    if (f[V] == 0x3F3F3F3F)
        f[V] = -1;
    cout << f[V] << endl;
}

int main()
{
    work();
    return 0;
}

