#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 200200
#define maxm 1000100
using namespace std;
int arr[maxn];
int lc[maxn], rc[maxn];
int pre[maxm], nxt[maxm];

int rk[maxn], mp[maxn];

int n, mx;
bool cmp(int a, int b){
    return arr[a] < arr[b];
}
void lisan(){
    for(int i=1;i<=n;i++) rk[i] = i;
    sort(rk + 1, rk + n + 1, cmp);
    mp[1] = arr[rk[1]];
    arr[rk[1]] = mx = 1;
    for(int i=2;i<=n;i++){
        if(arr[rk[i]] == mp[mx]) arr[rk[i]] = mx;
        else mp[++mx] = arr[rk[i]], arr[rk[i]] = mx;
    }
}
struct RMQ {
    int dpm[20][maxn];
    void init(int N, int a[]){
        for(int i=1;i<=N;i++){dpm[0][i]=a[i];}
        for(int j=1;(1<<j)<=N;j++){
            for(int i=1;i+(1<<j)-1<=N;i++){
                dpm[j][i]=max(dpm[j-1][i],dpm[j-1][i+(1<<(j-1))]);
            }
        }
    }
    int getm(int a,int b){
        int k=(int)(log((double)(b-a+1))/log(2.0));
        return max(dpm[k][a],dpm[k][b-(1<<k)+1]);
    }
} r1, r2;

int main(){
    int m, a, b;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        lisan();
        memset(pre, 0xff, sizeof pre);
        memset(nxt, 0xff, sizeof nxt);
        lc[0] = 0;
        int limit = 0;
        for (int i = 1; i <= n; ++i) {
            if (pre[ arr[i] ] == -1) lc[i] = lc[i - 1] + 1;
            else {
                limit = max(limit, pre[ arr[i] ]);
                lc[i] = i - limit;
            }
            pre[ arr[i] ] = i;
        }
        rc[n + 1] = 0;
        limit = inf;
        for (int i = n; i >= 1; --i) {
            if (nxt[ arr[i] ] == -1) rc[i] = rc[i + 1] + 1;
            else {
                limit = min(limit, nxt[ arr[i] ]);
                rc[i] = limit - i;
            }
            nxt[ arr[i] ] = i;
        }
        r1.init(n, lc), r2.init(n, rc);
        while (m--) {
            scanf("%d%d", &a, &b);
            ++a, ++b;
            int len = b - a + 1;
            int lt = rc[a], rt = lc[b];
            if (lt >= len || rt >= len) printf("%d\n", len);
            else {
                int ret = max(lt, rt);
                ret = max(ret, r1.getm(a + lt, b));
                ret = max(ret, r2.getm(a, b - rt));
                printf("%d\n", ret);
            }
        }
    }
    return 0;
}
