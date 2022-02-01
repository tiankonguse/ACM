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
#define N 100005

void work()
{
    LL m;
    cin >> m;
    if (m >= 2) {
        m = (m << 3) - 7;
        LL x = sqrt(m + 1e-8);
        if (x * x == m)
            puts("YES");
        else
            puts("NO");
    } else
        puts("NO");
}

int main()
{
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}

