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
#define maxn 200200
using namespace std;
struct node {
    int x, w, id;
    friend bool operator < (node a, node b) {
        return a.x < b.x;
    }
} p[maxn];

int lg[maxn], dpmax[20][maxn],  maxpos[20][maxn];
void rmq_init(int n){
    int i, j, k;
    for(lg[0]=-1,i=1;i<=n;i++){
        lg[i] = ((i & (i - 1)) == 0)? lg[i - 1] + 1: lg[i - 1];
        dpmax[0][i] = p[i].w;
        maxpos[0][i] = i;
    }
    for(k=1;k<=lg[n];k++){
        for(i=1;i+(1<<k)-1<=n;i++){
            j = i + (1 << (k - 1));
            if(dpmax[k - 1][i] > dpmax[k - 1][j]){
                dpmax[k][i] = dpmax[k - 1][i];
                maxpos[k][i] = maxpos[k - 1][i];
            }
            else{
                dpmax[k][i] = dpmax[k - 1][j];
                maxpos[k][i] = maxpos[k - 1][j];
            }
        }
    }
}
int getMax(int a, int b){
    int t = lg[b - a + 1], p = b - (1 << t) + 1;
    return max(dpmax[t][a], dpmax[t][p]);
}
int getMaxpos(int a, int b){
    int t = lg[b - a + 1], p = b - (1 << t) + 1;
    if(dpmax[t][a] > dpmax[t][p]) return maxpos[t][a];
    else return maxpos[t][p];
}

int find1(int l, int r, int x){ // a[res] <= x
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(p[mid].x <= x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int find3(int l, int r, int x){ // a[res] >= x
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(p[mid].x >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main() {
    int n, d;
    int res, r1, r2;
    while (~scanf("%d%d", &n, &d)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &p[i].x, &p[i].w);
        }
       // sort(p + 1, p + n + 1);
        rmq_init(n);
        res = r1 = r2 = -1;
        int cp, cf, mx, tx, tp;
        for (int i = 1; i <= n; ++i) {
            cp = find1(1, n, p[i].x - d);
            cf = find3(1, n, p[i].x + d);
            mx = -inf;
            if (cp > 0) {
                tx = getMax(1, cp);
                if (tx > mx) {
                    mx = tx;
                    tp = getMaxpos(1, cp);
                }
            }
            if (cf <= n) {
                tx = getMax(cf, n);
                if (tx > mx) {
                    mx = tx;
                    tp = getMaxpos(cf, n);
                }
            }
            if (mx + p[i].w > res) {
                res = mx + p[i].w;
                r1 = i;
                r2 = tp;
            }
        }
        printf("%d %d\n", r1, r2);
    }
    return 0;
}
