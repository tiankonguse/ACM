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
#define maxn 1005
using namespace std;
struct Point{
    int x, y;
}p[maxn];
inline int cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
inline int cross(Point a, Point b, Point c){
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
bool cmp(Point a, Point b){
    int t = cross(a, b);
    if(t == 0){
        if(a.x * b.x < 0 || a.y * b.y < 0){
            return a.y < b.y || a.y == b.y && a.x < b.x;
        }
        else{
            return abs(a.x) < abs(b.x) || abs(a.y) < abs(b.y);
        }
    }
    else return t > 0;
}
void polar_sort(int n){
    int mx = 0, x0, y0;
    for(int i=0;i<n;i++){
        if(p[i].x < p[mx].x || (p[i].x == p[mx].x && p[i].y < p[mx].y)) mx = i;
    }
    swap(p[0], p[mx]);
    x0 = p[0].x, y0 = p[0].y;
    for(int i=0;i<n;i++){
        p[i].x -= x0;
        p[i].y -= y0;
    }
    sort(p + 1, p + n, cmp);
    for(int i=n-1;i>=0;i--){
        if(cross(p[i], p[i-1]) != 0){
            reverse(p + i, p + n);
            break;
        }
    }
}

int main(){
    int T, N;
    for(scanf("%d", &T);T--;){
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        if(N <= 5){ puts("NO"); continue; }
        polar_sort(N);
        p[N] = p[0];
        p[N+1] = p[1];
        bool flag = true, ok = true, ok2 = false;
        for(int i=0;i<N;i++){
            if(cross(p[i], p[i + 1], p[i + 2]) == 0) flag = true;
            else{
                ok2 = true;
                if(flag) flag = false;
                else{
                    ok = false;
                    break;
                }
            }
        }
        puts(ok && ok2? "YES" : "NO");
    }
    return 0;
}
