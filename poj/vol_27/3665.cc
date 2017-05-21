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
#define maxn 1010
using namespace std;
int rate[maxn];
int main(){
    int n, t, p, s, r;
    while(~scanf("%d%d", &n, &t)){
        for(int i=1;i<=n;i++){
            scanf("%d", &rate[i]);
        }
        while(t--){
            p = 1;
            for(int i=2;i<=n;i++){
                if(rate[i] > rate[p]){
                    p = i;
                }
            }
            printf("%d\n", p);
            s = rate[p] / (n - 1);
            r = rate[p] % (n - 1);
            rate[p] = 0;
            for(int i=1;i<=n;i++){
                if(i == p) continue;
                rate[i] += s;
                if(r){
                    r--;
                    rate[i]++;
                }
            }
        }
    }
    return 0;
}
