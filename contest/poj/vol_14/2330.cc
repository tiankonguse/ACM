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
#define maxl 550
using namespace std;
int mp[maxn][maxn];
char res[maxl][maxl];
char cube[10][10] ={ // 6 * 7
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};
void draw(int x, int y){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(cube[i][j] != '.'){
                res[x + i][y + j] = cube[i][j];
            }
        }
    }
}
int main(){
    int n, m, w, h, t, x, y;
    while(~scanf("%d%d", &n, &m)){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d", &mp[i][j]);
            }
        }
        w = 4 * m + 2 * n + 1;
        h = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                h = max(h, 2 * (n - i - 1) + 3 * mp[i][j] + 3);
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                res[i][j] = '.';
            }
            res[i][w] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int t=1;t<=mp[i][j];t++){
                    y = 4 * j + 2 * (n - i - 1);
                    x = h - 1 - (3 * t + 2 * (n - i - 1) + 2);
                    draw(x, y);
                }
            }
        }
        for(int i=0;i<h;i++){
            puts(res[i]);
        }
    }
    return 0;
}
