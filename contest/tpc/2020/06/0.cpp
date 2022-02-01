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

int main() {
    vector<LL> vec;
    vec.resize(100001);
    int t;
    scanf("%d", &t);
    while(t--) {
        LL n,m;
        scanf("%lld%lld", &n, &m);
        vec.clear();
        for(int i=0; i<n; i++) {
            LL v = 0;
            scanf("%lld", &v);
            vec.push_back(v);
        }

        int lastPos = -1;
        LL sum = 0;
        bool flag = true;
        for(int i=0; i<n; i++) {
            if(vec[i] == -1) {
                lastPos = i;
                vec[i] = 0;
            }
            sum += vec[i];
            if(i < 2){
                continue;
            }

            if(sum < m) {
                if(lastPos + 2 < i) {
                    flag = false;
                    break;
                }
                vec[lastPos] += (m - sum);
                sum = m;
            }

            sum -= vec[i-2];
        }

        if(flag) {
            sum = 0;
            for(auto v: vec) {
                sum += v;
            }
            printf("%lld\n", sum);
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}


