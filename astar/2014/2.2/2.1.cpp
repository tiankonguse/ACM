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
const int MAX = 1002;
int str[2][N][N];
int notstate = 0, tmpState;
int map[8][2] = {{1, 0}, {-1, 0}, {0, 1},{0, -1}, {2, 0}, {-2, 0}, {0, 2}, {0, -2}};
int mod = 9999991;
bool have[N*N+1];
int state[N*N+1];
int num;

int main() {
    int t,n,m,k,x,y,i,j,tt,kk,ans,nindex, newi, newj, newstate, newnum;
    scanf("%d",&t);
    for(int tt=1; tt<=t; tt++) {
        memset(have,false,sizeof(have));
        scanf("%d%d%d%d%d",&n,&m,&k,&x,&y);
        n++,m++,x++,y++;
        memset(str[0],0,sizeof(str[0]));
        notstate = 0;

        ans = 0;

        str[notstate][x][y] = 1;

        num = 0;
        state[num++] = x*MAX + y;

        while(k--) {
            tmpState = !notstate;
            memset(str[tmpState],0,sizeof(str[tmpState]));
            newnum = num;
            for(nindex=0; nindex<num; nindex++) {
            	j =  state[nindex] % MAX;
            	i =  state[nindex] / MAX;
//            	printf("i=%d j=%d\n",i,j);
                for(kk=0; kk<8; kk++) {
                	newi = i+map[kk][0];
                	newj = j+map[kk][1];

                    if(newi >= 2 && newi <= n && newj >=2 && newj <= m){
//                    	printf("-->newi=%d newj=%d\n",newi,newj);
						str[tmpState][newi][newj] += str[notstate][i][j];
						str[tmpState][newi][newj] %= mod;

						newstate = newi*MAX + newj;
						if(!have[newstate]){
							have[newstate] = true;
							state[newnum++] = newstate;
						}
                    }

                }
            }
            num = newnum;
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
