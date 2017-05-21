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
#define maxn 200200
using namespace std;
typedef __int64 ll;

int parents[maxn];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}
void init(){
    memset(parents, 0xff, sizeof(parents));
}
map<int, int> mpx, mpy;
set<int> xx[maxn], yy[maxn];
struct Point {
    int x, y;
} p[maxn];

int main() {
    int n;
    int x, y;
    while (~scanf("%d", &n)) {
        init(); 
        mpx.clear(), mpy.clear();
        bool f1, f2;
        int id = 0;
        int id1, id2, r1, r2;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
            x = p[i].x, y = p[i].y;
            
            f1 = mpx.find(x) != mpx.end();
            f2 = mpy.find(y) != mpy.end();
            ++id;
            
            if (f1 && f2) {
                id1 = mpx[x], id2 = mpy[y];
                r1 = Find(id1), r2 = Find(id2);
                
                if (r1 != r2) {
                    Union(r1, r2);
                }
                parents[id] = Find(r1);
            }
            else if (f1) {
                id1 = Find(mpx[x]);
                parents[id] = id1;
               
            }
            else if (f2){
                id2 = Find(mpy[y]);
                parents[id] = id2; 
            }
            mpx[x] = mpy[y] = id;
        }
       
        for (int i = 0; i < n; ++i) {
            x = p[i].x;
            y = p[i].y;
            xx[ Find(mpx[x]) ].insert( x );
            yy[ Find(mpy[y]) ].insert( y );
        }    
        ll ret = 0;
        
        for (int i = 1; i <= n; ++i) ret += 1LL * xx[i].size() * yy[i].size();
        
        printf("%I64d\n", ret);
    }
    return 0;
}

