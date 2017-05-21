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
#include <bitset>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 105
using namespace std;
int mp[maxn][maxn];
bitset<100> bs1[maxn], bs2[maxn];
int n, m;
bool used[maxn];
void dfs1(int u){
    for(int i=0;i<n;i++){
        if(mp[u][i] == 1){
            if(!used[i]) dfs1(i);
            used[i] = true;
            bs1[u] |= bs1[i];
            bs1[u][i] = 1;
        }
    }
}
void dfs2(int u){
    for(int i=0;i<n;i++){
        if(mp[u][i] == -1){
            if(!used[i]) dfs2(i);
            used[i] = true;
            bs2[u] |= bs2[i];
            bs2[u][i] = 1;
        }
    }
}
int main(){
    int a, b, res;
    while(~scanf("%d%d", &n, &m)){
        memset(mp, 0, sizeof(mp));
        for(int i=0;i<m;i++){
            scanf("%d%d", &a, &b);
            a--, b--;
            mp[a][b] = 1;
            mp[b][a] = -1;
        }
        for(int i=0;i<n;i++){
            bs1[i].reset();
            bs2[i].reset();
        }
        memset(used, false, sizeof(used));
        for(int i=0;i<n;i++){
            if(!used[i]) dfs1(i);
        }
        memset(used, false, sizeof(used));
        for(int i=0;i<n;i++){
            if(!used[i]) dfs2(i);
        }
        res = 0;
        for(int i=0;i<n;i++){
            if(bs1[i].count() + bs2[i].count() == n - 1) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
