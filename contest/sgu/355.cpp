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
#define M 100005


void work()
{
    int n , i , j , x , y , z = 0;
    cin >> n;
    for (i = 1 ; i <= n ; ++ i) {
        x = i , y = 1;
        for (j = 2 ; j * j <= n ; ++ j)
            while (x % j == 0)
                x /= j , ++ y;
        if (x > 1)
            ++ y;
        z = max(z , y);
    }
    printf("%d\n" , z);
    for (i = 1 ; i <= n ; ++ i) {
        x = i , y = 1;
        for (j = 2 ; j * j <= n ; ++ j)
            while (x % j == 0)
                x /= j , ++ y;
        if (x > 1)
            ++ y;
        z = max(z , y);
        printf("%d%c" , y , " \n"[i == n]);
    }
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

