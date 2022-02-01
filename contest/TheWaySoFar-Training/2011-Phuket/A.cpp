#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;

int v[30],h[30];
int n;
int V,H;
LL ans;

void dfs(int x,LL V1,LL C1){
    if (V1>=V) ans=(ans==-1)?C1:min(ans,C1);

    if (x>n) return ;
    dfs(x+1,V1+(LL)H*v[x],C1+h[x]);
    dfs(x+1,V1,C1);
}

int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) scanf("%d%d",&v[i],&h[i]);
    int m;
    scanf("%d",&m);
    for (int i=1; i<=m; ++i){
        scanf("%d%d",&V,&H);
        ans=-1;
        dfs(1,0,0);
        printf("Case %d: ",i);
        if (ans==-1) puts("IMPOSSIBLE");
        else printf("%lld\n",ans);
    }
    return 0;
}
