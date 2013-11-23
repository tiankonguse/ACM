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
int lll;

int str[100][100];

int main() {
    int n,m,i,j;
    int ans;
    while(~scanf("%d%d",&n,&m)) {
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                scanf("%d",&str[i][j]);
            }
        }
        ans = 4;
        for(i=0; i<m; i++) {
            if(str[i][0] == 1 || str[i][m-1] == 1) {
                ans = 2;
                break;
            }
        }
        for(j=0; j<m; j++) {
            if(str[0][j] == 1 || str[n-1][j] == 1) {
                ans = 2;
                break;
            }
        }
        printf("%d\n",ans);

    }



    return 0;
}

