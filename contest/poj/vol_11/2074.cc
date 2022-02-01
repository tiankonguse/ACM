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
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<double, double> pdd;
vector<pdd> v;

int main(){
    int n;
    double hx1, hx2, hy, px1, px2, py, x1, x2, y, tx1, tx2;
    while(~scanf("%lf%lf%lf", &hx1, &hx2, &hy)){
        if(hx1 == 0 && hx2 == 0 && hy == 0) break;
        scanf("%lf%lf%lf", &px1, &px2, &py);
        v.clear();
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf", &x1, &x2, &y);
            if(y <= hy && y >= py){
                tx1 = hx2 - (hx2 - x1) * (hy - py) / (hy - y);
                tx2 = hx1 - (hx1 - x2) * (hy - py) / (hy - y);
                v.pb( mp(tx1, tx2) );
            }
        }
        sort(v.begin(), v.end());
        double end = px1, res = 0;
        int p = 0, m = v.size();
        while(end < px2 && p < m){
            res = max(res, min(px2, v[p].first) - end);
            end = max(end, v[p].second);
            p++;
        }
        res = max(res, px2 - end);
        if(res == 0) puts("No View");
        else printf("%.2lf\n", res);
    }
    return 0;
}
