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
#define maxn 310
using namespace std;
typedef __int64 ll;
ll a[maxn], b[maxn];
ll matx[maxn];
set <ll> fy;
map <ll, int> maty;

int N;
ll M;

int path(int u){
    ll v, k;
    ll l, r;
    if (a[u] > 0) {
        l = (1 - b[u] + a[u] - 1) / a[u];
        r = (M - b[u] + a[u] - 1) / a[u];
    }
    else if (a[u] < 0) {
        r = (1 - b[u] + a[u] + 1) / a[u];
        l = (M - b[u] + a[u] + 1) / a[u];
    }
    else l = r = 0;
    l = max(0LL, l);
    for (k = l; k <= r; ++k) {
        v = k * a[u] + b[u];
        if (v <= 0 || v > M) break;
        if(fy.find(v) == fy.end()){
             fy.insert(v);
             if(maty.find(v) == maty.end() || path(maty[v])){
                matx[u]=v;
                maty[v]=u;
                return 1;
             }
        }
    }
    return 0;
}
int hungary(){
   int res=0;
   memset(matx,0xff,sizeof(matx));
   maty.clear();

   for(int i=0;i<N;i++){
       if(matx[i]<0){
           fy.clear();
           res += path(i);
       }
   }
   return res;
}
int main() {
    int n; ll m;
    while (~scanf("%d %I64d", &N, &M)) {
        for (int i = 0; i < N; ++i) {
            scanf("%I64d %I64d", &a[i], &b[i]);
        }
        int h = hungary();
        ll pos = 1;
        for (int i = 0; i < N; ++i) {
            if (matx[i] == -1) {
                for (; pos <= M; ++pos) {
                    if (maty.find(pos) == maty.end()) {
                        printf("%I64d", pos);
                        ++pos;
                        break;
                    }
                }
            }
            else printf("%I64d", matx[i]);
            if (i == N - 1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}

