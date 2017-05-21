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
const double eps = 1e-8;
const double r = 1.0;
struct point{
    double x, y;
}p[maxn], t[maxn * maxn];
double dist(point a, point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main(){
    int n, cnt;
    double x, y, px, py, d, d2, d3;
    while(scanf("%d", &n) && n){
        for(int i=0;i<n;i++){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                x = (p[i].x + p[j].x) / 2.0;
                y = (p[i].y + p[j].y) / 2.0;
                px = p[i].x - p[j].x;
                py = p[i].y - p[j].y;
                d = sqrt(px * px + py * py);
                d2 = d / 2.0;
                if(d2 > 1.0) continue;
                d3 = sqrt(1.0 - d2 * d2);
                t[cnt].x = x + py * d3 / d;
                t[cnt].y = y - px * d3 / d;
                cnt++;
                t[cnt].x = x - py * d3 / d;
                t[cnt].x = y + px * d3 / d;
                cnt++;
            }
        }
        int cc, res = 1;
        for(int i=0;i<cnt;i++){
            cc = 0;
            for(int j=0;j<n;j++){
                if(dist(t[i], p[j]) <= 1.0 + eps) cc++;
            }
            res = max(res, cc);
        }
        printf("%d\n", res);
    }
    return 0;
}
