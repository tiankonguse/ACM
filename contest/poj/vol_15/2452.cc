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
#define maxn 50050
using namespace std;
int a[maxn];
int lg[maxn], dpmax[20][maxn], dpmin[20][maxn], maxpos[20][maxn];
void rmq_init(int n){
    int i, j, k;
    for(lg[0]=-1,i=1;i<=n;i++){
        lg[i] = ((i & (i - 1)) == 0)? lg[i - 1] + 1: lg[i - 1];
        dpmax[0][i] = dpmin[0][i] = a[i];
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
            dpmin[k][i] = min(dpmin[k - 1][i], dpmin[k - 1][j]);
        }
    }
}
int getMaxpos(int a, int b){
    int t = lg[b - a + 1], p = b - (1 << t) + 1;
    if(dpmax[t][a] > dpmax[t][p]) return maxpos[t][a];
    else return maxpos[t][p];
}
int getMin(int a, int b){
    int t = lg[b - a + 1], p = b - (1 << t) + 1;
    return min(dpmin[t][a], dpmin[t][p]);
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        rmq_init(n);
        int res = -1, l, r, mid, t, tr;
        for(int i=1;i<n;i++){
            l = i + 1, r = n, tr = -1;
            while(l <= r){
                mid = (l + r) >> 1;
                t = getMaxpos(i + 1, mid);
                if(getMin(i + 1, t) > a[i]){
                    tr = t;
                    l = mid + 1;
                }
                else r = t - 1;
            }
            if(tr != -1) res = max(res, tr - i);
        }
        printf("%d\n", res);
    }
    return 0;
}
