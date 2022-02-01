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

int dis(int a, int b) {
    if(a > b) {
        return a - b;
    } else {
        return b - a;
    }
}

int main() {
    int t;
    char str[111111];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", str);
        int len = strlen(str);
        int one = 0, zero = 0;

        for(int i=0; i<len; i++) {
            if(str[i] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        if(one < zero){
            for(int i=0; i<len; i++) {
                str[i] = (1 - (str[i] - '0')) + '0';
            }
            swap(one, zero);
        }
        int ans = one - zero;

        one = zero = 0;
        int l = 1, r = len;
        for(r=1; r<=len; r++) {
            if(str[r-1] == '1') {
                one++;
            }else{
                zero++;
            }
            if(one > zero && one - zero == ans/2) {
                ans = ans - (one - zero);
                break;
            }
        }
        if(r > len) r--;
        printf("%d %d\n", l, r);

    }

    return 0;
}


