#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0x3f3f3f3f = 1061109567 (recommended)
const int inf = 0x3f3f3f3f;
// 0x3FFFFFFFFFFFFFFFLL = 4611686018427387903 (recommended)
const LL Inf = 0x3FFFFFFFFFFFFFFFLL;
// 10^9 + 7
const int mod = 1000000007;

#define memsetMin(arr) memset(arr, 0xc0, sizeof(arr))
#define memsetMax(arr) memset(arr, 0x3f, sizeof(arr))

//memset
//memset(dpMin, 0x3f, sizeof(dpMin)); // inf
//memset(dpMax, 0xc0, sizeof(dpMax)); // -inf

const int N = 1111;
int n,m;
LL str[N][N];
LL X[N], Y[N];

LL gcd(LL a, LL b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

bool check() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            LL x = X[i], y = Y[j];
            str[i][j] = x * y / gcd(x, y);
        }
    }

    for(int i=0; i<n; i++) {
        LL x = str[i][0];
        for(int j=0; j<m; j++) {
            x = gcd(x, str[i][j]);
        }
        if(x != X[i]) {
            return false;
        }
    }
    for(int j=0; j<m; j++) {
        LL y = str[0][j];
        for(int i=0; i<n; i++) {
            y = gcd(y, str[i][j]);
        }
        if(y != Y[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n,&m);
        for(int i=0; i<n; i++) {
            scanf("%lld", &X[i]);
        }
        for(int i=0; i<m; i++) {
            scanf("%lld",&Y[i]);
        }
        if(!check()) {
            printf("No\n");
        } else {
            printf("Yes\n");
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    printf("%lld%c", str[i][j], j==m-1?'\n':' ');
                }
            }
        }

    }

    return 0;
}

/*

4
3 4
1 1 1
1 1 1 1
3 4
1 1 1
1 1 1 2
3 4
1 2 3
4 3 2 1
2 2
2 2
4 4
*/

