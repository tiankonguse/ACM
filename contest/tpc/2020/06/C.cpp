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

LL str[111111];

bool check(int n) {

    stack<LL> sta;

    for(int i=0; i<n; i++) {
        while(!sta.empty() && sta.top() >= str[i]) {
            if(sta.top() % str[i] == 0) {
                sta.pop();
            } else {
                return false;
            }
        }

        if(sta.empty()) {
            sta.push(str[i]);
            continue;
        }

        // sta.top() < str[i]
        if(str[i] % sta.top() != 0) {
            return false;
        }
        sta.push(str[i]);
    }

    return true;

}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%lld", &str[i]);
        }
        printf("%s\n", check(n)?"Yes":"No");

    }

    return 0;
}


