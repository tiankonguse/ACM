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
#define maxn 1001000
#define maxm 1010
using namespace std;
int dp[maxn];
struct node{
    int l, r, e;
    friend bool operator<(node a, node b){
        return a.r < b.r;
    }
}seg[maxm];

int main(){
    int n, m, r, p;
    while(~scanf("%d%d%d", &n, &m, &r)){
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &seg[i].l, &seg[i].r, &seg[i].e);
        }
        sort(seg, seg + m);
        p = 0;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=n;i++){
            while(seg[p].r == i){
                if(seg[p].l - r < 0) dp[i] = max(dp[i], seg[p].e);
                else dp[i] = max(dp[i], seg[p].e + dp[seg[p].l - r]);
                p++;
            }
            if(i > 0) dp[i] = max(dp[i], dp[i - 1]);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
