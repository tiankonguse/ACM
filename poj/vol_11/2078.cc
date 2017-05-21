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
#define maxn 8
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int mat[maxn][maxn];
int sel[maxn];
int n, res;
void dfs(int d, int s){
    if(d == n){
        int t = -inf, tr;
        rep(j, n){
            tr = 0;
            rep(i, n){
                tr += mat[i][(sel[i] + j) % n];
            }
            t = max(t, tr);
        }
        res = min(res, t);
        return;
    }
    for(int i=0;i<n;i++){
        sel[d] = i;
        s += mat[d][i];
        if(s < res) dfs(d + 1, s);
        s -= mat[d][i];
    }
}
int main(){
    while(~scanf("%d", &n) && n != -1){
        rep(i, n) rep(j, n) scanf("%d", &mat[i][j]);
        res = inf;
        dfs(1, mat[0][0]);
        printf("%d\n", res);
    }
    return 0;
}
