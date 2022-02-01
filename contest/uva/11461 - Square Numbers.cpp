#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005

int n , m , ca;
int f[N];

void work()
{
    printf("%d\n" , f[m] - f[n - 1]);
}

void init()
{
    for (int i = 1 ; i * i <= 100000 ; ++ i)
        ++ f[i * i];
    for (int i = 2 ; i <= 100000 ; ++ i)
        f[i] += f[i - 1];
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    //int _; scanf("%d",&_); while (_ --)
    init();
    while (scanf("%d%d",&n , &m) , n || m)
        work();
    return 0;
}
