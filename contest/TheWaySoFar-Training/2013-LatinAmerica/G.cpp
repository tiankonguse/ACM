#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
const int maxn = 100005;
vector<int> ans;
int f[maxn][20],h[maxn],n,a[maxn],l[maxn],r[maxn];

int lmin(int l,int r){
    int s=log(r-l+1)/log(2);
    while (l+(1<<s)<r-(1<<s)+1) ++s;
    return min(f[l][s],f[r-(1<<s)+1][s]);
}

void init()
{
    for(int i = 0; i < n; ++i) scanf("%d",&h[i]);
    memset(f,63,sizeof(f));
    for (int i=0; i<n; ++i) f[i][0]=h[i];
    for (int j=1; j<20; ++j)
        for (int i=0; i+(1<<j)<=n; ++i)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
void solve()
{
    ans.clear();
    int top = 0;
    for(int i = 0; i < n; ++i){
        while(top > 0 && h[a[top - 1]] <= h[i]) --top;
        l[i] = top == 0 ? -1 : a[top - 1];
        a[top++] = i;
    }
    top = 0;
    for(int i = n - 1; i >= 0; --i){
        while(top > 0 && h[a[top - 1]] <= h[i]) --top;
        r[i] = top == 0 ? -1 : a[top - 1];
        a[top++] = i;
    }
    for(int i = 0; i < n; ++i){
        int res = 0;
        if(l[i] != -1) res = max(res,lmin(l[i],i));
        if(r[i] != -1) res = max(res,lmin(i,r[i]));
        if(h[i] - res >= 150000) ans.push_back(i + 1);
    }
    for(int i = 0; i < ans.size(); ++i)
        printf("%d%c",ans[i],i == ans.size() - 1 ? '\n' : ' ');
}
int main() {
    while(~scanf("%d",&n)){
        init();
        solve();
    }
    return 0;
}
