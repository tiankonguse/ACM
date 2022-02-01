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
#include <cassert>
using namespace std;
typedef long long LL;

#define N 55
int n , K , ca;
pair<int , int> a[N];
bool cmp(pair<int , int> A , pair<int , int> B) {
    return A.second * B.first > A.first * B.second;
}
int f[N][N][N * N];
void work() {
    int i , j , k;
    scanf("%d%d",&n,&K);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d%d",&a[i].first , &a[i].second);
    sort(a , a + n , cmp);
    memset(f[0] , 0x80 , sizeof(f[0]));
    f[0][0][0] = 0;
    int sy = 0;
    for (i = 0 ; i < n ; ++ i) {
        memset(f[i + 1] , 0x80 , sizeof(f[i + 1]));
        for (j = 0 ; j <= K ; ++ j) {
            for (k = 0 ; k <= sy ; ++ k) {
                if (f[i][j][k] >= 0) {
                    f[i + 1][j][k] = max(f[i + 1][j][k] , f[i][j][k]);
                    f[i + 1][j + 1][k + a[i].second] = max(f[i + 1][j + 1][k + a[i].second] , f[i][j][k] + a[i].first * (k + k + a[i].second));
                }
            }
        }
        sy += a[i].second;
    }
    int ans = -1;
    for (i = 0 ; i <= sy ; ++ i)
        ans = max(ans , f[n][K][i]);
    printf("Case %d: %d\n" , ++ ca , ans);
}

int main(){
    //freopen("1.txt","r",stdin);
    int _ ; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
