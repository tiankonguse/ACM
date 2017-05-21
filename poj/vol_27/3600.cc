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
#define maxn 22
using namespace std;
int mask[maxn], B[maxn][maxn];
char buf[maxn];
int main(){
    int na, ma, nb, mb;
    while(scanf("%d%d", &na, &ma) == 2){
        memset(mask, 0, sizeof mask);
        for(int i=0;i<na;i++){
            scanf(" %s", buf);
            for(int j=0;j<ma;j++){
                mask[j] = (mask[j] << 1) | (buf[j] == '1');
            }
        }
        scanf("%d%d", &nb, &mb);
        for(int i=0;i<nb;i++){
            scanf(" %s", buf);
            for(int j=0;j<mb;j++){
                B[i][j] = (buf[j] == '1');
            }
        }
        int mx = 1 << nb;
        bool flag = false;
        for(int s=0;s<mx;s++){
            if(__builtin_popcount(s) == na){
                int p = 0;
                for(int i=0;i<mb;i++){
                    int t = 0;
                    for(int j=0;j<nb;j++){
                        if(s & (1 << j)){
                            t = (t << 1) | B[j][i];
                        }
                    }
                    if((t & mask[p]) == mask[p]) p++;
                    if(p == ma) break;
                }
                if(p == ma){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
