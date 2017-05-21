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
#include <string>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 120
using namespace std;
int mp[maxn][maxn];
bool used[maxn][maxn];
bool mark[maxn][maxn];
int n;
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
bool range(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n) return false;
    else return true;
}
bool dfs(int x, int y){
    if(x == n-1 && y == n-1) return true;
    used[x][y] = true;
    int tx, ty;
    for(int i=0;i<4;i++){
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if(range(tx, ty) && mark[tx][ty] && !used[tx][ty]){
            if(dfs(tx, ty)) return true;
        }
    }
    return false;
}
bool check(int l, int h){
    memset(used, false, sizeof(used));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j] >= l && mp[i][j] <= h) mark[i][j] = true;
            else mark[i][j] = false;
        }
    }
    return mark[0][0] && dfs(0, 0);
}
int main(){
    int ht, lt;
    while(~scanf("%d", &n)){
        ht = 0, lt = inf;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &mp[i][j]);
                ht = max(ht, mp[i][j]);
                lt = min(lt, mp[i][j]);
            }
        }
        int low = lt;
        int l, h, mid;
        int ans = inf;
        for(;low<=mp[0][0];low++){
            l = low, h = ht;
            while(l <= h){
                mid = (l + h) >> 1;
                if(check(low, mid)){
                //    printf("check(%d,%d)=true\n", low, mid);
                    ans = min(ans, mid - low);
                    h = mid - 1;
                }
                else l = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
