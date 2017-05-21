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
#define maxn 5050
using namespace std;
struct rectangles{
    int x1, x2, y1, y2;
    friend bool operator<(rectangles a, rectangles b){
        return a.x1 < b.x1;
    }
}rec[maxn];

int main(){
    int n, res;
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d", &rec[i].x1, &rec[i].x2, &rec[i].y1, &rec[i].y2);
        }
       // sort(rec, rec + n);
        res = 0;
//        for(int i=1;i<n;i++){
//            if(rec[i].x2 >= rec[0].x2 && rec[i].y1 <= rec[0].y1 && rec[i].y2 >= rec[0].y2){
//                res++;
//                break;
//            }
//        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) continue;
                if(rec[j].x1 <= rec[i].x1 && rec[j].x2 >= rec[i].x2 && rec[j].y1 <= rec[i].y1 && rec[j].y2 >= rec[i].y2){
                    res++;
                    break;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
