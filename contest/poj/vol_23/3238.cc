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
#define maxn 256
using namespace std;
int data[4][4]={{0,0,0,0},{0,1,2,3},{0,2,3,1},{0,3,1,2}};
int md[7]={2,4,16,256,65536};

int nim_mul(int x,int y){
    if(x<y)return nim_mul(y,x);
    if(x<4)return data[x][y];
    int a,M,p,q,s,t,c1,c2,c3;
    for(a=0;a<5;a++){
        if(md[a]>x)break;
    }
    a--;
    M=md[a];
    p=x/M;q=x%M;
    s=y/M;t=y%M;
    c1=nim_mul(p,s);
    c2=nim_mul(p,t)^nim_mul(q,s);
    c3=nim_mul(q,t);
    return M*(c1^c2)^c3^nim_mul(M/2,c1);
}
bool dp[maxn][maxn];
int pre[maxn][maxn];
int res[maxn];

int main() {
    int n1, n2;
    int x, y, z;
    while (~scanf("%d%d", &n1, &n2)) {
        int t = 0;
        for (int i = 0; i < n1; ++i) {
            scanf("%d%d", &x, &y);
            --x, --y;
            t ^= nim_mul(x, y);
        }
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for (int i = 0; i < n2; ++i) {
            scanf("%d%d", &x, &y);
            --x, --y;
            z = nim_mul(x, y);
            for (int j = 0; j < 256; ++j) {
                if (dp[i][j]) {
                    dp[i + 1][j] = true;
                    dp[i + 1][j ^ z] = true;
                    pre[i + 1][j] = j;
                    pre[i + 1][j ^ z] = j;
                }
            }
        }
        if (dp[n2][t]) {
            puts("Yes");
            int now = t;
            for (int i = n2 ; i >= 1; --i) {
                if (pre[i][now] == now) res[i] = 1;
                else res[i] = 0;
                now = pre[i][now];
            }
            for (int i = 1; i <= n2; ++i) {
                if (res[i] == 1) puts("T");
                else puts("H");
            }
        }
        else puts("No");
    }
    return 0;
}
