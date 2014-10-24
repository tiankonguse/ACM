#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;

int n , a[10005];

void work(int l , int r) {
    if (l > r) return;
    int i ;
    for (i = l + 1 ; i <= r ; ++ i)
        if (a[i] > a[l])
            break;
    work(l + 1 , i - 1);
    work(i , r);
    printf("%d\n" , a[l]);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    int i , j , x;
    n = 0;
    while (~scanf("%d",&x))
        a[++ n] = x;
    work(1 , n);
    return 0;
}
