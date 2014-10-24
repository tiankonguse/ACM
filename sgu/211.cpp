#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 1005
int n , m;
int a[N];
set<int> T , Z;

void update(int x , int w) {
    if (a[x] == 2) T.erase(x);
    if (a[x] == 0) Z.erase(x);
    a[x] += w , printf(" %d %d" , x , a[x]);
    if (a[x] == 2) T.insert(x);
    if (a[x] == 0) Z.insert(x);
}

void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        Z.insert(i);
    T.insert(i);
    while (m --) {
        scanf("%d",&j);
        x = *T.upper_bound(j);
        y = *--Z.upper_bound(x);
        if (j >= y) {
            printf("3");
            update(x , -2);
            update(x + 1 , 1);
            update(j , 1);
        } else if (a[j]) {
            printf("2");
            update(j , -1);
            update(j + 1 , 1);
        } else {
            printf("1");
            update(j , 1);
        }
        puts("");
    }
}

int main()
{
    freopen("1.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
