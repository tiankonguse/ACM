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
bool obs[maxn], mark[maxn];
int main(){
    int n, z, m, k, a, p;
    while(~scanf("%d%d%d", &n, &z, &m)){
        memset(obs, false, sizeof(obs));
        for(int i=0;i<m;i++){
            scanf("%d", &a);
            obs[a] = true;
        }
        bool flag = false;
        for(k=1;k<=n;k++){
            memset(mark, false, sizeof(mark));
            p = 1;
            while(1){
                if(mark[p] || obs[p]) break;
                if(p == z){
                    flag = true;
                    break;
                }
                mark[p] = true;
                p += k;
                if(p > n) p -= n;
            }
            if(flag) break;
        }
        printf("%d\n", k);
    }
    return 0;
}
