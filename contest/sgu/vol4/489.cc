#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 10010
using namespace std;
int dp[2][maxn];

int main(){
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        if (n == 1) { printf("%d\n", 1 % m); continue; }
        dp[1][1] = 1;
        int now = 0, pre = 1;
        for (int i = 2; i <= n; ++i) {
            if(i % 2 == 0){
                dp[now][i] = 0;
                for (int j = i - 1; j >= 1; --j) {
                    dp[now][j] = (dp[now][j + 1] + dp[pre][j]) % m;
                }
            }
            else{
                dp[now][1] = 0;
                for(int j = 2;j <= i; ++j){
                    dp[now][j] = (dp[now][j - 1] + dp[pre][j - 1]) % m;
                }
            }
            swap(now, pre);
        }
        int res = 0;
        for(int i = 1;i <= n; ++i) {
            res = (res + dp[pre][i]) % m;
        }
        printf("%d\n",(res + res) % m);
    }
    return 0;
}
