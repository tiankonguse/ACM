#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0x3f3f3f3f = 1061109567 (recommended)
//const int inf = 0x3f3f3f3f;
// 0x3FFFFFFFFFFFFFFFLL = 4611686018427387903 (recommended)
//const LL Inf = 0x3FFFFFFFFFFFFFFFLL;
// 10^9 + 7
//const int mod = 1000000007;

//#define memsetMin(arr) memset(arr, 0xc0, sizeof(arr))
//#define memsetMax(arr) memset(arr, 0x3f, sizeof(arr))

//memset
//memset(dpMin, 0x3f, sizeof(dpMin)); // inf
//memset(dpMax, 0xc0, sizeof(dpMax)); // -inf

const int N = 1111111;
pair<int, LL> str[N];
char ans[N];
int n;


bool check() {

    if(n == 1){
        return false;
    }

    if(n == 2 && str[0].second != str[1].second){
        return false;
    }

    sort(str, str+n, [](pair<int, LL>& a, pair<int, LL>& b) {
        return a.second > b.second;
    });

    LL sum = 0;
    for(int i=0; i<n; i++) {
        sum += str[i].second;
    }

    if(str[0].second * 2 > sum){
        return false;
    }


    LL sums[3];
    for(int j=0; j<3; j++) {
        sums[j] = 0;
    }
    int minIndex = 0;

    for(int i=0; i<n; i++) {
        sums[minIndex] += str[i].second;
        ans[str[i].first] = '1' + minIndex;

        if(sums[minIndex]*2 > sum) {
                int a = 0;
            int b = 2/a;
            return false;
        }

        for(int j=0; j<3; j++) {
            if(sums[j] < sums[minIndex]) {
                minIndex = j;
            }
        }
    }
    ans[n] = '\0';
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            LL tmp;
            scanf("%lld", &tmp);
            str[i].first = i;
            str[i].second = tmp;
        }

        if(check()) {
            printf("%s\n", ans);
        } else {
            printf("Impossible\n");
        }


    }
    return 0;
}

/*
6
5
1 3 1 2 3
4
2 3 1 4
2
1 100
1
1
2
2 2
2
2 3
*/


