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
#define maxn 100050
using namespace std;

struct point{
    int x,y;
}pnt[maxn],res[maxn];

bool mult(point sp,point ep,point op){
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool operator < (const point &l,const point &r){
  return l.y<r.y || (l.y==r.y && l.x<r.x);
}
inline int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int graham(point pnt[],int n,point res[]){
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0)return 0;res[0]=pnt[0];
    if(n==1)return 1;res[1]=pnt[1];
    if(n==2)return 2;res[2]=pnt[2];
    for(i=2;i<n;i++){
        while(top&&mult(pnt[i],res[top],res[top-1]))top--;
        res[++top]=pnt[i];
    }
    len=top;res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
       while(top!=len && mult(pnt[i],res[top],res[top-1]))top--;
       res[++top]=pnt[i];
    }
    return top;
}
inline int cross(point o, point p1, point p2) {
    return (p1.x - o.x) * (p2.y - o.y) - (p2.x - o.x) * (p1.y - o.y);
}
int solve(int n) {
    int q = 1, ret = 0;
    for (int i = 0; i < n; ++i) {
        while ( cross(res[i], res[i + 1], res[q + 1]) >
                cross(res[i], res[i + 1], res[q]) ) {
            q = (q + 1) % n;
        }
        ret = max(ret, max( dist(res[i].x, res[i].y, res[q].x, res[q].y),
                            dist(res[i + 1].x, res[i + 1].y, res[q + 1].x, res[q + 1].y) ) );
    }
    return ret;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &pnt[i].x, &pnt[i].y);
        }
        int g = graham(pnt, n, res);
        printf("%d\n", solve(g));
    }
    return 0;
}
