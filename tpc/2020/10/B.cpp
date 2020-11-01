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


const char kOne = '#';
const char kZero = '.';
char str[11][11];
char input[11][11];

int ans;

void dfs(int lev, int n, int useNum) {
    if(useNum > 9){
        return ;
    }
    if(n == 3) {
        int num = 0;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(str[i][j] != input[i][j]) {
                    num++;
                }
            }
        }
        num /= 2;
        if(num < ans) {
            //printf("num = %d\n", num);
            //for(int i=0; i<4; i++) {
            //    printf("--: %s\n", str[i]);
            //}
            ans = num;
        }
        return ;
    }
    //2 + 4 + 4
    vector<pair<int, int>> buf;
    for(int l = lev; l < 10; l++) {
        if(l == 0) {
            for(int i=0; i<4; i++) {
                int x = i, y = i;
                if(str[x][y] != kOne) {
                    str[x][y] = kOne;
                    buf.push_back({x, y});
                }
            }
        } else if(l == 1) {
            for(int i=0; i<4; i++) {
                int x = i, y = 3 - i;
                if(str[x][y] != kOne) {
                    str[x][y] = kOne;
                    buf.push_back({x, y});
                }
            }
        } else if(l < 6) { // 2 3 4 5
            for(int j=0; j<4; j++) {
                int x = l - 2, y = j;
                if(str[x][y] != kOne) {
                    str[x][y] = kOne;
                    buf.push_back({x, y});
                }
            }
        } else { // 6 7 8 9
            for(int i=0; i<4; i++) {
                int x = i, y = l - 6;
                if(str[x][y] != kOne) {
                    str[x][y] = kOne;
                    buf.push_back({x, y});
                }
            }
        }
        dfs(l+1, n+1, useNum + buf.size());
        for(auto& p: buf) {
            str[p.first][p.second] = kZero;
        }
        buf.clear();
    }
}

int solver() {
    ans = 9;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            str[i][j] = kZero;
        }
    }
    dfs(0, 0, 0);
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<4; i++) {
            scanf("%s", input[i]);
        }
        printf("%d\n", solver());
    }
    return 0;
}

/*
2
####
####
#...
....
.#.#
####
.#..
##..

*/
