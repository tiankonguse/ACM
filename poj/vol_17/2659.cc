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
#define maxn 105
using namespace std;
int mp[maxn][maxn];
int main(){
    int n, m, k;
    int x, y, p, t;
    int lx, rx, ly, ry;
    while(~scanf("%d%d%d", &n, &m, &k)){
        memset(mp, 0, sizeof(mp));
        while(k--){
            scanf("%d%d%d%d", &x, &y, &p, &t);
            x--, y--;
            lx = max(0, x - p / 2);
            ly = max(0, y - p / 2);
            rx = min(n - 1, x + p / 2);
            ry = min(m - 1, y + p / 2);
            for(int i=lx;i<=rx;i++){
                for(int j=ly;j<=ry;j++){
                    if(t == 1) {
                        if(mp[i][j] >= 0) mp[i][j]++;
                    }
                    else mp[i][j] = -inf;
                }
            }
        }
        int mx = -1, cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j] > mx){
                    mx = mp[i][j];
                    cnt = 1;
                }
                else if(mp[i][j] == mx){
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
