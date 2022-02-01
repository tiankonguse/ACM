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
#define maxn 111
using namespace std;
struct Point{
    int x, y;
}p[maxn];

inline int cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
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
    sort(p + 1, p + n, cmp);
    for(int i=n-1;i>=0;i--){
        if(cross(p[i], p[i-1]) != 0){
            reverse(p + i, p + n);
            break;
        }
    }
}

int main(){
    int n = 0;
    while(~scanf("%d%d", &p[n].x, &p[n].y)) n++;
    polar_sort(n);
    for(int i=0;i<n;i++){
        printf("(%d,%d)\n", p[i].x, p[i].y);
    }
    return 0;
}
