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
#define maxn 15
using namespace std;
char mp[maxn][maxn];
int dir[256][2];

int main(){
    dir['\\'][0] = 1, dir['\\'][1] =  1;
    dir['/' ][0] = 1, dir['/' ][1] = -1;
    dir['-' ][0] = 0, dir['-' ][1] =  1;
    dir['|' ][0] = 1, dir['|' ][1] =  0;

    int t, n, m, cnt, tx, ty;
    bool flag;
    for(scanf("%d", &t);t--;){
        scanf("%d%d", &n, &m);
        cnt = 0; flag = false;
        for(int i=0;i<n;i++){
            scanf(" %s", mp[i]);
            for(int j=0;j<m;j++){
                cnt += mp[i][j] != '.';
            }
        }
        if(cnt == 0){ puts("INCORRECT"); continue; }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j] != '.'){
                    tx = i, ty = j;
                    while(tx >= 0 && tx < n && ty >= 0 && ty < m && mp[tx][ty] == mp[i][j]){
                        cnt--;
                        tx += dir[ mp[i][j] ][0];
                        ty += dir[ mp[i][j] ][1];
                    }
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        puts(cnt == 0 ? "CORRECT" : "INCORRECT");
    }
    return 0;
}
