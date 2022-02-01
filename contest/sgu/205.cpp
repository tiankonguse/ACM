#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 1005
int n , m , K , X[N];
int a[200][200];
int f[N][200];
pair<int , int> p[N][200];
void print(int x , int y) {
    if (x == 0) return;
    print(x - 1 , p[x][y].first);
    printf("%d%c" , p[x][y].second , " \n"[y == n]);
}

void work() {
    int i , j , k ;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&X[i]);
    scanf("%d%d",&m,&K);
    for (i = 0 ; i < m ; ++ i) {
        for (j = 0 ; j < K ; ++ j) {
            scanf("%d",&a[i][j]);
        }
    }
    memset(f , 63 , sizeof(f));
    f[0][0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            for (k = 0 ; k < K ; ++ k) {
                if (f[i + 1][k % m] > f[i][j] + abs(X[i + 1] - a[j][k])) {
                    f[i + 1][k % m] = f[i][j] + abs(X[i + 1] - a[j][k]);
                    p[i + 1][k % m] = make_pair(j , k);
                }
            }
        }
    }
    int ans = 1 << 30;
    for (i = 0 ; i < m ; ++ i)
        ans = min(ans , f[n][i]);
    printf("%d\n" , ans);
    for (i = 0 ; i < m ; ++ i) {
        if (f[n][i] == ans) {
            print(n , i);
            break;
        }
    }
}

int main(){
    work();
    return 0;
}
