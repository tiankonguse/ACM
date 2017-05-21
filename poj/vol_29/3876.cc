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
#define maxn 505
using namespace std;

double dp[maxn][maxn][2];
bool mark[maxn][maxn][2];
int val[30] = {5, 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20};
double dfs(int n, int m, int state){
    if(mark[n][m][state]) return dp[n][m][state];
    if(n == 0 || m == 0) return 0.0;
    double p0 = 0, p1 = 0;
    for(int i=1;i<=20;i++){
        if(n - i >= 0) p0 += 0.05 * (1.0 - dfs(n - i, m, 1));
        else p1 += 0.05;
    }
    if(state == 0){
        mark[n][m][state] = true;
        return dp[n][m][state] = p0 + p1 * (1.0 - dfs(n, m, 1));
    }
    else{
        double t[4], tmp; int cnt = 0, ct;
        bool used[4];
        fill(t, t + 4, 0.0);
        fill(used, used + 4, false);
        for(int i=1;i<=20;i++){
            tmp = 0;
            ct = 0;
            for(int j=-1;j<=1;j++){
                if(m >= val[i + j]) tmp += (1.0 - dfs(n, m - val[i + j], 0)) / 3.0;
                else ct++;
            }
            t[ct] = max(t[ct], tmp);
            used[ct] = true;
        }
        double y = 0, k;
        for(int i=0;i<4;i++){
            if(used[i]){
                k = 1.0 * i / 3.0;
                y = max(y, (k * (1.0 - p0 - p1) + t[i]) / (1.0 - k * p1));
            }
        }
        mark[n][m][state] = true;
        return dp[n][m][state] = y;
    }
}
int main(){
    int n;
    while(scanf("%d", &n) && n){
        dfs(n, n, 0);
        printf("%.10lf %.10lf\n", dp[n][n][0], dp[n][n][1]);
    }
    return 0;
}
