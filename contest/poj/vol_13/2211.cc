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
int per[maxn];
int fac[maxn];
bool mark[maxn];
int main(){
    int T, n, k;
    fac[0] = 1;
    for(int i=1;i<=12;i++) fac[i] = fac[i - 1] * i;
    scanf("%d", &T);
    for(int _t=1;_t<=T;_t++){
        scanf("%d%d", &n, &k);
        for(int i=0;i<k;i++){
            scanf("%d", &per[i]);
        }
        memset(mark, false, sizeof(mark));
        int cnt, res = 0;
        for(int i=0;i<k;i++){
            cnt = 0;
            for(int j=1;j<per[i];j++){
                cnt += !mark[j];
            }
            mark[ per[i] ] = true;
            res += cnt * fac[n - i - 1] / fac[n - k];
        }
        printf("Variace cislo %d ma poradove cislo %d.\n", _t, res + 1);
    }
    return 0;
}
