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
#define maxn 505
using namespace std;
int dat[maxn][2];
bool dan[maxn];
int main(){
    dat[1][0] = dat[1][1] = 1;
    for(int i=2;i<=500;i++) {
        dat[i][0] = (dat[i-1][0] - 1 + 15) % i + 1;
        dat[i][1] = (i - dat[i][0] + 1) % i + 1;
    }
    int n, m;
    while(scanf("%d%d", &n, &m) && (n + m)){
        memset(dan, false, sizeof(dan));
        for(int i=n;i<=m;i++) dan[ dat[i][0] ] = dan[ dat[i][1] ] = true;
        int mn = inf, safe = -1;
        for(int i=2;i<=n/2;i++) if(!dan[i]){
            if(min(i - 1, n - i + 1) < mn){
                mn = min(i - 1, n - i + 1);
                safe = i - 1;
            }
        }
        if(safe == -1) puts("Better estimate needed");
        else printf("%d\n", safe);
    }
    return 0;
}
