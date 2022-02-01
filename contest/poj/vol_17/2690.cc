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
#define maxn 13 + 1
#define maxm 8192 + 10
#define maxc 5 + 1
using namespace std;
int cards[maxc];
int score[maxn][maxn];
int cnt[maxn];

void check(int n){
    for(int i=0;i<=5;i++) score[i][n] = cnt[i + 1] * (i + 1);
    score[6][n] = 0; for(int i=0;i<5;i++) score[6][n] += cards[i];
    score[7][n] = 0; for(int i=6;i>=1;i--) if(cnt[i] >= 3) { score[7][n] = score[6][n]; break; }
    score[8][n] = 0; for(int i=6;i>=1;i--) if(cnt[i] >= 4) { score[8][n] = score[6][n]; break; }
    score[9][n] = 0; for(int i=6;i>=1;i--) if(cnt[i] >= 5) { score[9][n] = 50; break; }
    score[10][n] = 0; if( (cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0 && cnt[4] > 0) ||
                          (cnt[2] > 0 && cnt[3] > 0 && cnt[4] > 0 && cnt[5] > 0) ||
                          (cnt[3] > 0 && cnt[4] > 0 && cnt[5] > 0 && cnt[6] > 0) ) score[10][n] = 25;
    score[11][n] = 0; if( (cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0 && cnt[4] > 0 && cnt[5] > 0) ||
                          (cnt[2] > 0 && cnt[3] > 0 && cnt[4] > 0 && cnt[5] > 0 && cnt[6] > 0) ) score[11][n] = 35;
    score[12][n] = 0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(i == j) continue;
            if(cnt[i] == 2 && cnt[j] == 3){
                score[12][n] = 40;
                return;
            }
        }
    }
}

int dp[maxn][maxm];
bool mark[maxn][maxm];
int path[maxm];
int res[maxn];
int main(){
    while(~scanf("%d %d %d %d %d", &cards[0], &cards[1], &cards[2], &cards[3], &cards[4])){
        memset(cnt, 0, sizeof(cnt));
        for(int j=0;j<5;j++) cnt[ cards[j] ]++;
        check(0);
        for(int i=1;i<13;i++){
            memset(cnt, 0, sizeof(cnt));
            for(int j=0;j<5;j++){
                scanf("%d", &cards[j]);
                cnt[ cards[j] ]++;
            }
            check(i);
        }
        memset(dp, 0, sizeof(dp));
        memset(mark, false, sizeof(mark));
        memset(path, 0xff, sizeof(path));
        mark[0][0] = true;
        int t;
        for(int i=0;i<13;i++){
            for(int j=0;j<8192;j++){
                if(mark[i][j]){
                    for(int k=0;k<13;k++){
                        if(!(j & (1 << k))){
                            t = j | (1 << k);
                            if(i == 5 && dp[i][j] + score[i][k] >= 63){
                                if(dp[i][j] + score[i][k] + 35 > dp[i + 1][t]){
                                    dp[i + 1][t] = dp[i][j] + score[i][k] + 35;
                                    path[t] = k;
                                }
                            }
                            else{
                                if(dp[i][j] + score[i][k] > dp[i + 1][t]){
                                    dp[i + 1][t] = dp[i][j] + score[i][k];
                                    path[t] = k;
                                }
                            }
                            mark[i + 1][t] = true;
                        }
                    }
                }
            }
        }
        t = 8191;
        int sum = 0;
        for(int i=12;i>=0;i--){
            res[i] = path[t];
            sum += score[i][res[i]];
            t -= (1 << path[t]);
        }
        for(int i=0;i<13;i++) printf("%d ", score[i][res[i]]);
        printf("%d %d\n", dp[13][8191] - sum, dp[13][8191]);
    }
    return 0;
}
