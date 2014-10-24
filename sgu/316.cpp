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
#define N 605
int n , m;
int hp[N] , cnt[N];

void work()
{
    int i , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        hp[i] = 100;
    while (m -- ) {
        scanf("%d%d",&x,&y);
        if (hp[x] > 0) {
            if (hp[y] > 0) {
                cnt[x] += 3;
            }
            hp[y] -= 8;
        }
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (hp[i] > 0)
            cnt[i] += hp[i] / 2;
        printf("%d %d\n" , hp[i] , cnt[i]);
    }
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

