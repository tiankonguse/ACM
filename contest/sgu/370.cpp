
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 2000005
LL ans;
bool f[N];
int prime[N] , tot;
int mu[N] , sum[N];
int n , m;
void work() {
    cin >> n >> m;
    if (n == 1 && m == 1) {
        puts("0");
    } else if (n == 1 || m == 1) {
        puts("1");
    } else {
        -- n , -- m;
        if (n > m) swap(n , m);
        int i , j , x;
        mu[1] = 1;
        for (i = 2 ; i <= n && i <= m ; ++ i)
        {
            if (!f[i]) {
                prime[tot ++] = i ;
                mu[i] = -1;
            }
            for (j = 0 ; j < tot ; ++ j)
            {
                x = i * prime[j];
                if (x > n) break;
                f[x] = 1 ;
                if (i % prime[j] == 0) { // x isn't the square free number.
                    mu[x] = 0;
                    break;
                }
                else { // x is updated by another prime.
                    mu[x] = -mu[i];
                }
            }
        }
        for (i = 1 ; i <= n && i <= m  ; ++ i)
            sum[i] = sum[i - 1] + mu[i];
        ans = 2;
        for (i = 1 ; i <= n ; i = x + 1) {
            x = min(n / (n / i) , m / (m / i));
            ans += (LL) (sum[x] - sum[i - 1]) * (n / i) * (m / i);
        }
        cout << ans << endl;
    }
}


int main(){
    //freopen("~input.txt" , "r" , stdin);
    //while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
