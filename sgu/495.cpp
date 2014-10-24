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
#define N 100005
int n , m ;
double res , f[N];

void work()
{
    int i ;
    cin >> n >> m;
    for (i = 1 ; i <= m ; ++ i) {
        if (i == 1)
            f[i] = 1;
        else
            f[i] = (1.0 - f[i - 1]) * f[i - 1] + f[i - 1] * (f[i - 1] - 1.0 / n);
        res += f[i];
    }
    printf("%.10f\n" , res);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
