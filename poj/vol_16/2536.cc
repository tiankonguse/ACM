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
#define maxn 110
using namespace std;
double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int mat[maxn][maxn];
int matx[maxn],maty[maxn];
bool fy[maxn];
int N,M;

int path(int u){
   int v;
   for(v=0;v<M;v++){
      if(mat[u][v] && !fy[v]){
         fy[v]=1;
         if(maty[v]<0 || path(maty[v])){
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
   memset(maty,0xff,sizeof(maty));
   for(int i=0;i<N;i++){
       if(matx[i]<0){
           memset(fy,false,sizeof(fy));
           res+=path(i);
       }
   }
   return res;
}
struct point{
    double x, y;
}p[maxn];
int main(){
    int n, m; double s, v, x, y;
    while(~scanf("%d%d%lf%lf", &n, &m, &s, &v)){
        s *= v;
        memset(mat, 0, sizeof(mat));
        for(int i=0;i<n;i++){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        for(int i=0;i<m;i++){
            scanf("%lf%lf", &x, &y);
            for(int j=0;j<n;j++){
                if(dist(x, y, p[j].x, p[j].y) <= s){
                    mat[j][i] = 1;
                }
            }
        }
        N = n, M = m;
        printf("%d\n", n - hungary());
    }
    return 0;
}
