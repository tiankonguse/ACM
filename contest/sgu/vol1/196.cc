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
#define maxn 100100
using namespace std;
typedef __int64 ll;
int cnt[maxn];
int main(){
    int n, m, a;
    ll res;
    while(~scanf("%d %d", &n, &m)){
        for(int i=0;i<m+m;i++){
            scanf("%d", &a);
            cnt[a]++;
        }
        res = 0;
        for(int i=1;i<=n;i++) res += cnt[i] * cnt[i];
        printf("%I64d\n", res);
    }
    return 0;
}
