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
enum {VAL,MINVAL,MAXVAL};
const int maxn = 1000000000;
const int N = 2100;
int ans[N][N][3];
int str[N];

int main() {

    int n,k,i,j;
    int bottom,top;
    int tmp;
    while(~scanf("%d%d",&n,&k)) {
        for(i=1; i<=n; i++) {
            scanf("%d",&str[i]);
        }
        ans[1][0][VAL] = 0;
        ans[1][0][MINVAL] = str[1];
        ans[1][0][MAXVAL] = str[1];
        ans[1][1][VAL] = 0;
        ans[1][1][MINVAL] = -maxn;
        ans[1][1][MAXVAL] = maxn;
        for(i=2; i<=n; i++) {
            for(j=0; j<=k; j++) {
                if(j >= i) {
                    ans[i][j][VAL] = 0;
                    ans[i][j][MINVAL] = -maxn;
                    ans[i][j][MAXVAL] = maxn;
                    break;
                } else if(j == 0){
                    ans[i][j][VAL] = max(ans[i-1][j][VAL], abs(str[i] - str[i-1]));
                    ans[i][j][MINVAL] = str[i];
                    ans[i][j][MAXVAL] = str[i];
                }else{
                    ans[i][j][VAL] = ans[i-1][j-1][VAL];
                    ans[i][j][MINVAL] = ans[i-1][j-1][MINVAL] - ans[i-1][j-1][VAL];
                    ans[i][j][MAXVAL] = ans[i-1][j-1][MAXVAL] + ans[i-1][j-1][VAL];


                    bottom = ans[i-1][j][MINVAL] - ans[i-1][j][VAL];
                    top = ans[i-1][j][MAXVAL] + ans[i-1][j][VAL];
                    if(str[i] <= top && str[i] >= bottom) {
                        tmp = ans[i-1][j][VAL];
                    } else {
                        if(str[i] < bottom) {
                            tmp = ans[i-1][j][MINVAL] - str[i];
                        } else {
                            tmp = str[i] - ans[i-1][j][MAXVAL];
                        }
                    }
                    if(tmp < ans[i][j][VAL]) {
                        ans[i][j][VAL] = tmp;
                        ans[i][j][MINVAL] = str[i];
                        ans[i][j][MAXVAL] = str[i];
                    }
                }
            }
        }


        for(i=1; i<=n; i++) {
        	printf("i=%d \n",i);
            for(j=0; j<=min(i,k); j++) {
            	printf("%d %d %d\n",ans[i][j][VAL],ans[i][j][MINVAL],ans[i][j][MAXVAL]);
            }
            puts("");
        }
        printf("%d\n",ans[n][k][VAL]);

    }



    return 0;
}
/*
4 1
-1 -1 1 1
*/
