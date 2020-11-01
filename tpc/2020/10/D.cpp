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

int n;
const int N = 111111;
pair<LL, LL> str[N];

LL str2[N*4][N*4];

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%lld%lld", &str[i].first, &str[j].second);

        }

    }

    return 0;
}


