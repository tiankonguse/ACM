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
#define maxn 110
#define maxj 10010
#define sqr(x) ((x) * (x))
using namespace std;
char mp[maxn][maxn];
int pos[maxj][2];
int n;
bool check(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n) return true;
    else return false;
}
int main(){
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf(" %s", mp[i]);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mp[i][j] == 'J'){
                    pos[cnt][0] = i;
                    pos[cnt++][1] = j;
                }
            }
        }
        int res = 0;
        int x1, y1, x2, y2, x3, y3, x4, y4, nr;
        for(int i=0;i<cnt;i++){
            x1 = pos[i][0], y1 = pos[i][1];
            for(int j=i+1;j<cnt;j++){
                x2 = pos[j][0], y2 = pos[j][1];
                nr = sqr(x1 - x2) + sqr(y1 - y2);
                if((x1 - x2 + y1 - y2) % 2 != 0 || nr <= res) continue;
                x3 = (x1 + x2 + y1 - y2) >> 1;
                y3 = (y1 + y2 + x2 - x1) >> 1;
                x4 = (x1 + x2 + y2 - y1) >> 1;
                y4 = (y1 + y2 + x1 - x2) >> 1;
                if(check(x3, y3) && check(x4, y4) && (mp[x3][y3] == 'J' || mp[x4][y4] == 'J')
                   && mp[x3][y3] != 'B' && mp[x4][y4] != 'B'){
                    res = nr;
                }
            }
        }
        printf("%d\n", res >> 1);
    }
    return 0;
}
