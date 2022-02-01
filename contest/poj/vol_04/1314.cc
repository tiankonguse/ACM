///For Valentine's Day specially!
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
#define maxn 30
using namespace std;
struct point{
    int x, y;
    char name;
    friend bool operator<(point a, point b){
        if(a.y == b.y) return a.x < b.x;
        else return a.y < b.y;
    }
}p[maxn];
int dist(int a, int b){
    return (p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y);
}
bool check(int a, int b, int c, int d){
 //   return dist(a, b) == dist(c, d) && dist(a, c) == dist(b, d) && dist(a, d) == dist(b, c) && p[a].y != p[c].y;
    return p[a].y == p[b].y && p[c].y == p[d].y && p[a].x == p[c].x && p[b].x == p[d].x;
}

struct result{
    char str[5];
    friend bool operator<(result a, result b){
        return strcmp(a.str, b.str) < 0;
    }
}res[maxn];

int main(){
    int n, _cnt = 1, m;
    while(scanf("%d", &n) && n){
        for(int i=0;i<n;i++){
            scanf(" %c %d %d", &p[i].name, &p[i].x, &p[i].y);
        }
        sort(p, p + n);
        m = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if(check(i, j, k, l)){
                            res[m].str[0] = p[k].name;
                            res[m].str[1] = p[l].name;
                            res[m].str[2] = p[j].name;
                            res[m].str[3] = p[i].name;
                            res[m++].str[4] = 0;
                        }
                    }
                }
            }
        }
        if(m == 0){
            printf("Point set %d: No rectangles\n", _cnt++);
        }
        else{
            sort(res, res + m);
            printf("Point set %d:\n", _cnt++);
            for(int i=0;i<m;i++){
                if(i != 0 && i % 10 == 0) puts("");
                printf(" %s", res[i].str);
            }
            puts("");
        }
    }
    return 0;
}
