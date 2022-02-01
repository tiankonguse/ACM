/*************************************************************************
  > File Name: 2.2.cpp
  > Author: tiankonguse
  > Mail: i@tiankonguse.com
  > Created Time: Mon 26 May 2014 11:31:15 AM CST
***********************************************************************/
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
int map[4]= {-2,-1,1,2};
LL C[N][N];
LL mod = 9999991;
LL str[2][N][N], sum[2][N];

void getC() {
	memset(C,0,sizeof(C));
    C[0][0] = 1;
    for(int i = 1; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] =( C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}

void DP(LL str[N][N], LL sum[N], int x, int n, int k) {
    str[0][x] = 1;
    sum[0] = 1;
    for(int t=1; t<=k; t++) {
        for(int i=2; i<=n; i++) {
            for(int kk=0; kk<4; kk++) {
                str[t][i] = (str[t][i] + str[t-1][i+map[kk]]) % mod;
            }
            sum[t] = (sum[t] + str[t][i]) % mod;
        }
    }
}

LL get(int k, int i) {
    return ((C[k][i] * sum[0][i] % mod) * sum[1][k-i] % mod);
}

int main() {
    getC();
    int t,n,m,k,x,y;
    LL ans;
    scanf("%d",&t);
    for(int tt=1; tt<=t; tt++) {
        scanf("%d%d%d%d%d",&n,&m,&k,&x,&y);
        n++,m++,x++,y++;
		memset(str,0,sizeof(str));
		memset(sum,0,sizeof(sum));
        DP(str[0], sum[0], x, n, k);
        DP(str[1], sum[1], y, m, k);

        ans = 0;
        for(int i = 0; i <= k; i++) {
            ans = (ans +   get(k, i))%mod;
        }
        printf("Case #%d:\n%lld\n",tt,ans);
    }

    return 0;
}
