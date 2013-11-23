#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;

const int N = 555;
int str[N][N];
int rightSum[N][N];
int centerDis[N];
int centerPos[N*4];
int centerSum[N][N];
int rightMaxSum[N][N];
LL rightMaxNum[N][N];
int ans;
LL ansNum;

int main() {
    int m,n,r,i,j,h;

    while(~scanf("%d%d%d",&n,&m,&r)) {
    	ans = 0;
    	ansNum = 0;
        for(i=0; i<n; i++) {
            rightSum[i][0] = 0;
            for(j=0; j<m; j++) {
                scanf("%d",&str[i][j]);
                rightSum[i][j+1] = rightSum[i][j] + str[i][j];
            }
        }

        centerDis[0] = r;
        for(i=1; i<=r; i++) {
            for (centerDis[i] = centerDis[i-1]; i*i+centerDis[i]*centerDis[i] > r*r; centerDis[i]--);
        }

        centerPos[0] = 2*r+1;
        for (i = 1; i <= 2*r; i++) {
        	centerPos[i] = 0;
            for (h = 1; h <= r; h++) {
                if (h >= i-r && h <= i) {
                    centerPos[i] = max(centerPos[i], centerDis[h]+centerDis[i-h]+1);
                }
            }
        }

        for (i = r; i < n-r; i++) {
            for (j = r; j < m-r; j++) {
                centerSum[i][j] = rightSum[i][j+centerDis[0]+1] - rightSum[i][j-centerDis[0]];
                for (h = 1; h <= r; h++) {
                    centerSum[i][j] += rightSum[i+h][j+centerDis[h]+1] - rightSum[i+h][j-centerDis[h]];
                    centerSum[i][j] += rightSum[i-h][j+centerDis[h]+1] - rightSum[i-h][j-centerDis[h]];
                }
            }
        }

        for (i = r; i < n-r; i++) {
            rightMaxSum[i][m-r-1] = centerSum[i][m-r-1];
            rightMaxNum[i][m-r-1] = 1;
            for (j = m-r-2; j >= r; j--) {
                if (centerSum[i][j] <= rightMaxSum[i][j+1]) {
                    rightMaxSum[i][j] = rightMaxSum[i][j+1];
                    rightMaxNum[i][j] = rightMaxNum[i][j+1];
                    if (centerSum[i][j] == rightMaxSum[i][j+1]) {
                        rightMaxNum[i][j]++;
                    }
                } else {
                    rightMaxSum[i][j] = centerSum[i][j];
                    rightMaxNum[i][j] = 1;
                }
            }
        }

        for (i = r; i < n-r; i++) {
            for (j = i+2*r+1; j < n-r; j++) {
                if (rightMaxSum[i][r]+rightMaxSum[j][r] == ans) {
                    ansNum += rightMaxNum[i][r]*rightMaxNum[j][r];
                } else if (rightMaxSum[i][r]+rightMaxSum[j][r] > ans) {
                    ans = rightMaxSum[i][r]+rightMaxSum[j][r];
                    ansNum = rightMaxNum[i][r]*rightMaxNum[j][r];
                }
            }
        }
        for (i = r; i < n-r; i++) {
            for (j = r; j < m-r; j++) {
                for (h = 0; h <= 2*r; h++) {
                    if (j + centerPos[h]+r >= m){
                     continue;
                    }
                    if (i+h < n-r) {
                        int score = centerSum[i][j] + rightMaxSum[i+h][j+centerPos[h]];
                        if (score == ans) {
                            ansNum += rightMaxNum[i+h][j+centerPos[h]];
                        } else if (score > ans) {
                            ans = score;
                            ansNum = rightMaxNum[i+h][j+centerPos[h]];
                        }
                    }
                    if (h && i-h >= r) {
                        int score = centerSum[i][j] + rightMaxSum[i-h][j+centerPos[h]];
                        if (score == ans) {
                            ansNum += rightMaxNum[i-h][j+centerPos[h]];
                        } else if (score > ans) {
                            ans = score;
                            ansNum = rightMaxNum[i-h][j+centerPos[h]];
                        }
                    }
                }
            }
        }
        printf("%d %lld\n", ans, ansNum);
    }


    return 0;
}
