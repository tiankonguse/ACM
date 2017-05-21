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
#define maxn 55
using namespace std;
int arr[maxn];
int up[maxn], down[maxn];
int n, res;
void dfs(int d, int p, int q){
    if(p + q >= res) return;
    if(d == n){
        res = min(res, p + q);
        return;
    }
    int s = 0, e, tmp;
    for(int i=0;i<p;i++){
        if(up[i] < arr[d] && up[i] > s){
            s = up[i];
            e = i;
        }
    }
    if(s != 0){
        tmp = up[e];
        up[e] = arr[d];
        dfs(d + 1, p, q);
        up[e] = tmp;
    }
    else{
        up[p] = arr[d];
        dfs(d + 1, p + 1, q);
    }
    s = inf;
    for(int i=0;i<q;i++){
        if(down[i] > arr[d] && down[i] < s){
            s = down[i];
            e = i;
        }
    }
    if(s != inf){
        tmp = down[e];
        down[e] = arr[d];
        dfs(d + 1, p, q);
        down[e] = tmp;
    }
    else{
        down[q] = arr[d];
        dfs(d + 1, p, q + 1);
    }
}
int main(){
    while(~scanf("%d", &n) && n){
        for(int i=0;i<n;i++) scanf("%d", &arr[i]);
        res = sqrt(1.0 * n) + 1;
        dfs(0, 0, 0);
        printf("%d\n", res);
    }
    return 0;
}
