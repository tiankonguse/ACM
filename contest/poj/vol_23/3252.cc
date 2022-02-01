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
#define maxn 50
using namespace std;
int dp[maxn][maxn];
void init(){
    dp[0][0] = dp[1][0] = 1;
    for(int i=2;i<=40;i++){
        dp[i][0] = 1;
        for(int j=1;j<=i;j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
}
int cal(int n, int ze){
    int sum = 0;
    if(ze < 0) ze = 0;
    for(int i=ze;i<=n;i++){
        sum += dp[n][i];
    }
//    printf("cal(%d, %d) = %d\n", n, ze, sum);
    return sum;
}
int num[maxn];
int fun(int x){
    if(x == 0) return 0;
    int p = 0, res = 0;
    int cnt = 0;
    while(x){
        num[cnt++] = x % 2;
        x >>= 1;
    }
    int z = (cnt + 1) >> 1;
    for(int i=cnt-1;i>=0;i--){
        if(i == cnt - 1){
            for(int j=i;j>=1;j--){
                res += cal(j, (j + 1) / 2);
            }
            continue;
        }
        if(num[i] == 0) z--;
        else{
            for(int j=i;j>=0;j--){
                res += cal(j, z - (i - j + 1));
            }
        }
    }
    if(z <= 0) res++;
    return res;
}
int main(){
    init();
    int a, b;
    while(~scanf("%d%d", &a, &b)){
        printf("%d\n", fun(b) - fun(a - 1));
    }
    return 0;
}
