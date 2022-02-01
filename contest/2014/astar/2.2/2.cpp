#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int N = 1111;
int str[2][N][N];
int notstate = 0, tmpState;
int map[8][2] = {{1, 0}, {-1, 0}, {0, 1},{0, -1}, {2, 0}, {-2, 0}, {0, 2}, {0, -2}};
int mod = 9999991;

int main() {
    int t,n,m,k,x,y,i,j,tt,kk,ans;
    scanf("%d",&t);
    for(int tt=1; tt<=t; tt++) {
        scanf("%d%d%d%d%d",&n,&m,&k,&x,&y);
        n++,m++,x++,y++;
        memset(str[0],0,sizeof(str[0]));
        notstate = 0;
        ans = 0;
        str[notstate][x][y] = 1;
        while(k--) {
            tmpState = !notstate;
            memset(str[tmpState],0,sizeof(str[tmpState]));
            for(i=2; i<=n; i++) {
                for(j=2; j<=m; j++) {
                    for(kk=0; kk<8; kk++) {
                        str[tmpState][i][j] += str[notstate][i+map[kk][0]][j+map[kk][1]];
                        str[tmpState][i][j] %= mod;
                    }
                }
            }
            notstate = tmpState;
        }
        ans = 0;
        for(i=2; i<=n; i++) {
            for(j=2; j<=m; j++) {
                ans = (ans + str[notstate][i][j]) % mod;
            }
        }
        printf("Case #%d:\n%d\n",tt,ans);
    }

    return 0;
}
