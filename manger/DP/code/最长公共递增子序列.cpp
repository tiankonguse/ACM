/*************************************************************************
    > File Name: 最长公共递增子序列.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/8 15:17:40
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

//给你两个数组a和b,长度分别代表la和lb.
//求最长公共递增子序列
//复杂度 O(n^2)
const int N = 500;
int f[N][N], dp[N];

int gcis(int* a, int la, int* b, int lb, int* ans) {
    int i, j, k, mx;
    memset(f, -1, sizeof(f));
    memset(dp, 0, sizeof(dp));

    for (i = 0; i < la; i++) {
        if(i){
            memcpy(f[i], f[i-1], sizeof(f[0]));
        }
        for (k = 0, j = 0; j < lb; j++) {
            if (b[j] < a[i] && dp[j] > dp[k]) k = j;
            if (b[j] == a[i] && dp[k] + 1 > dp[j]) {
                dp[j] = dp[k] + 1, f[i][j] = i * lb + k;
            }
        }
    }
    //dp[j]是b串以j为结尾的最长公共子序列
    //找到答案所在的位置
    for (mx = 0, j = 0; j < lb; j++){
        if (dp[j] > dp[mx]) mx = j;
    }


    //根据答案的位置，找到路径
    for(i=(la - 1) * lb + mx, j = dp[mx]; j; i=f[i/lb][i%lb], j--){
        ans[j-1] = b[i%lb];
    }

    //返回答案
    return dp[mx];
}
int main() {

    return 0;
}
