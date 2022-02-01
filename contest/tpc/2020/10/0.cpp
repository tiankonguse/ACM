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
char ans[111111];

int try_fill(int n, LL half, char v) {

    //one
    LL sum = 0;
    int num = 0;
    for(int i=0; i<n; i++) {
        if(ans[i] != '\0') {
            continue;
        }
        if(str[i] + sum <= half) {
            sum += str[i];
            ans[i] = v;
            num++;
        }
    }
    return num;
}

bool check(int n) {
    memset(ans, '\0', sizeof(ans));

    sort(str, str+n, [](LL a, LL b) {
        return a>b;
    });

    LL sum = 0;
    for(int i=0; i<n; i++) {
        sum += str[i];
        //printf("%d:%lld\n", i, str[i]);
    }
    LL half = (sum+1)/2;

    int num = 0;
    for(int i=0; i<3; i++) {
        num += try_fill(n, half, '1' + i);
    }
    //printf("sum = %lld half=%lld num = %d\n", sum, half, num);

    return num == n;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%lld", &str[i]);
        }

        if(n != 1 && check(n)) {
            printf("%s\n", ans);
        } else {
            printf("Impossible\n");
        }


    }
    return 0;
}


