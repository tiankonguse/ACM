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
int h[maxn];
int main(){
    int n, b, res, t;
    while(~scanf("%d%d", &n, &b)){
        res = inf;
        for(int i=0;i<n;i++) scanf("%d", &h[i]);
        for(int i=(1<<n);i--;){
            t = 0;
            for(int j=0;j<n;j++){
                if(i & (1 << j)) t += h[j];
            }
            if(t >= b) res = min(res, t - b);
        }
        printf("%d\n", res);
    }
    return 0;
}
