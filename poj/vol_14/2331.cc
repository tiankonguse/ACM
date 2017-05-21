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

using namespace std;
typedef vector<int> vi;
#define pb push_back
vi v[2][10010];
int L[5], C[5], des[2];
int n, res, cnt[2];
int sel[5], snt[5];

bool check(int s){
    int t;
    for(int i=0;i<(1<<n);i++){
        t = 0;
        for(int j=0;j<n;j++){
            if((i>>j) & 1) t += sel[j];
            else t -= sel[j];
        }
        if(t == des[s]){
            v[s][cnt[s]++] = vi(snt, snt + n);
            return true;
        }
    }
    return false;
}
void dfs(int d, int s){
    if(d == n){
        check(s);
        return;
    }
    for(int i=0;i<=C[d];i++){
        snt[d] = i;
        sel[d] = i * L[d];
        dfs(d + 1, s);
    }
}
int main(){
    int x1, y1, x2, y2, t;
    while(~scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n)){
        for(int i=0;i<n;i++) scanf("%d", &L[i]);
        for(int i=0;i<n;i++) scanf("%d", &C[i]);
        des[0] = x2 - x1, des[1] = y2 - y1;
        cnt[0] = cnt[1] = 0;
        dfs(0, 0), dfs(0, 1);
        res = inf;
        for(int i=0;i<cnt[0];i++){
            for(int j=0;j<cnt[1];j++){
                t = 0;
                for(int k=0;k<n;k++){
                    if(v[0][i][k] + v[1][j][k] <= C[k]){
                        t += v[0][i][k] + v[1][j][k];
                    }
                    else{
                        t = inf;
                        break;
                    }
                }
                res = min(res, t);
            }
        }
        if(res == inf) puts("-1");
        else printf("%d\n", res);
    }
    return 0;
}
