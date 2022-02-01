#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 1007
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

bool g[maxn][maxn];
int n, p[maxn];

int main(){
//    freopen("psortin.txt","r",stdin);
//    freopen("psortout.txt","w",stdout);
    int n;
    while(~scanf("%d", &n)){
        for(int i=1; i<=n; i++) scanf("%d", p+i);
        memset(g, false, sizeof g);
        for(int i=1, d; i<=n; i++)
        {
            scanf("%d", &d);
            if(i-d>=1) g[i][i-d]=g[i-d][i]=true;
            if(i+d<=n) g[i][i+d]=g[i+d][i]=true;
            g[i][i]=true;
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    g[i][j]=g[i][j] || g[i][k] && g[k][j];
        bool ok=false;
        for(int i=1; i<=n; i++)
            if(!g[i][p[i]])
            {
                printf("NO\n");
                ok=true;
            }
        if(!ok)printf("YES\n");
    }
	return 0;
}
