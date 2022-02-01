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
void work()
{
    int n , m , i , j;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < 1 << n ; ++ i) {
        for (j = 0 ; j < 1 << m ; ++ j) {
            printf("%d%c" , (i ^ (i >> 1)) << m | (j ^ (j >> 1)) , " \n"[j + 1 == (1 << m)]);
        }
    }
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


