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
#define maxn 85
using namespace std;
char str[maxn];
int dp1[maxn], dp2[maxn];
int check(int l1, int r1, int l2, int r2){
    while(str[l1++] == '0'); l1 = min(l1 - 1, r1);
    while(str[l2++] == '0'); l2 = min(l2 - 1, r2);
    if(r1 - l1 < r2 - l2) return 1;
    else if(r1 - l1 > r2 - l2) return -1;
    for(int i=0;i<=r1-l1;i++){
        if(str[l1+i] < str[l2+i]) return 1;
        else if(str[l1+i] > str[l2+i]) return -1;
    }
    return 0;
}
int main(){
    int n, res;
    while(scanf(" %s", str + 1)){
        n = strlen(str + 1);
        if(n == 1 && str[1] == '0') break;
        for(int i=1;i<=n;i++){
            dp1[i] = 1;
            for(int j=i-1;j>=1;j--){
                if(check(dp1[j], j, j + 1, i) == 1){
                 //   printf("checkMin(%d, %d, %d, %d)\n", dp1[j], j, j+1, i);
                    dp1[i] = j + 1;
                    break;
                }
            }
          //  cout<<dp1[i]<<endl;
        }
        res = dp1[n];
        memset(dp2, 0xff, sizeof(dp2));
        dp2[res] = n;
        for(int i=res-1;i>=1;i--){
            if(check(i, n, res, n) == 0){
                dp2[i] = n;
                continue;
            }
            for(int j=res-1;j>=1;j--){
                if(check(i, j, j + 1, dp2[j + 1]) == 1){
                    dp2[i] = j;
                    break;
                }
            }
        }
        int p=1;
        for(int i=1;i<=n;i++){
            putchar(str[i]);
            if(i == dp2[p] && i != n){
                putchar(',');
                p = dp2[p] + 1;
            }
        }
        puts("");
    }
    return 0;
}
