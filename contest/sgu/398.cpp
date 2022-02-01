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
#define N 55
int n , X;
bool g[N][N];

void work()
{
    int i , j , k , x;
    scanf("%d%d",&n,&X);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&j);
        while (j --)
            scanf("%d",&x) , g[i][x] = g[x][i] = 1;
    }
    vector<int> res;
    for (i = 1 ; i <= n ; ++ i) {
        if (i != X && !g[X][i]) {
            for (j = 1 ; j <= n ; ++ j) {
                if (g[X][j] && g[j][i])
                    break;
            }
            if (j <= n)
                res.push_back(i);
        }
    }
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d\n" , res[i]);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

