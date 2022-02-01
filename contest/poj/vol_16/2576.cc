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
#define maxm 22550
#define maxn 105
using namespace std;
bool mark[maxn][maxm];
int a[maxn];
int main(){
    int n, s, l, t, p, q, res;
    while(~scanf("%d", &n)){
        s = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            s += a[i];
        }
        memset(mark, false, sizeof(mark));
        mark[0][0] = true;
        l = s >> 1;
        t = 0;
        q = n / 2; if(n % 2 == 1) q++;
        for(int i=1;i<=n;i++){
            p = 0;
            for(int j=0;j<q;j++){
                for(int k=0;k<=t;k++){
                    if(mark[j][k]){
                        p = max(p, k + a[i]);
                        mark[j + 1][k + a[i]] = true;
                    }
                }
            }
            t = p;
        }
        if(n % 2 == 0){
            for(int i=l;i>=0;i--){
                if(mark[q][i]){
                    res = i;
                    break;
                }
            }
            printf("%d %d\n", res, s - res);
        }
        else{
            for(int i=l;i>=0;i--){
                if(mark[q][i] || mark[q - 1][i]){
                    res = i;
                    break;
                }
            }
            printf("%d %d\n", res, s - res);
        }
    }
    return 0;
}
