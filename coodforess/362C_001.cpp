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
const int N = 5555;
int pre[N][N];
int next[N][N];
int str[N];

int main() {
    int n,i,j,ans,num,sum,tmp;
    while(~scanf("%d",&n)) {
        for(i=0; i<n; i++) {
            scanf("%d",&str[i]);
        }
        sum = 0;
        for(i=0; i<n; i++) {
            pre[i][i] = next[i][i] = 0;
            for(j=i+1; j<n; j++) {
                if(str[j] < str[i]) {
                    next[i][j] = next[i][j-1] + 1;
                } else {
                    next[i][j] = next[i][j-1];
                }
            }
            for(j = i-1; j>=0; j--) {
                if(str[j] > str[i]) {
                    pre[i][j] = pre[i][j+1] + 1;
                } else {
                    pre[i][j] = pre[i][j+1];
                }
            }
            sum += pre[i][0];
        }

//        for(i=0; i<n; i++) {
//            printf("%d ",i);
//        }
//        puts("");
//        printf("sum=%d\n",sum);
//
//        for(i=0; i<n; i++) {
//            for(j=0; j<n; j++) {
//                printf("%d ",j<i?0:next[i][j]);
//            }
//            puts("");
//        }
//        puts("");
//        for(i=0; i<n; i++) {
//            for(j=0; j<n; j++) {
//                printf("%d ",j>i?0:pre[i][j]);
//            }
//            puts("");
//        }

        ans = 0,num = 0;
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                tmp = 2*next[i][j-1] - (j-i-1) + 2*pre[j][i+1] - (j-i-1);

                if(str[i] < str[j]) {
                    tmp--;
                } else {
                    tmp++;
                }
//                if(tmp == 5) {
//                    printf("i=%d j=%d\n",i,j);
//                }
                if(tmp > ans) {
                    ans  = tmp;
                    num = 1;
                } else if(tmp == ans) {
                    num++;
                }
            }
        }

        printf("%d %d\n",sum-ans,num);

    }
    return 0;
}
