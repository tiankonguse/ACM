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
#define maxn 50050
using namespace std;
int inv[maxn];
bool mark[maxn];
int res[maxn];
int main(){
    for(int i=1;i<=50000;i++) inv[i] = 1LL * i * (i - 1) / 2;
    int n, m;
    while(~scanf("%d%d", &n, &m) && n != -1){
        memset(mark, false, sizeof(mark));
        for(int i=1;i<=n;i++){
            if(inv[n - i] >= m){
                res[i] = i;
                mark[i] = true;
            }
            else{
                res[i] = i + m - inv[n - i];
                mark[res[i]] = true;
                int t = i + 1;
                for(int j=n;j>=i;j--){
                    if(!mark[j]) res[t++] = j;
                }
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(i == n) printf("%d\n", res[i]);
            else printf("%d ", res[i]);
        }
    }
    return 0;
}
