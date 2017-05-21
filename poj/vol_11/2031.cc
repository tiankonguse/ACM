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
#define maxn 105
using namespace std;
double mp[maxn][maxn];
bool inTree[maxn];
double min_length[maxn];
double prim(int n)
{
    double sum_length=0;
    memset(inTree,false,sizeof(inTree));
    for(int i=1;i<n;i++) min_length[i]=1e11;
    min_length[0]=0;
    for(int i=0;i<n;i++){
        int min_index=-1;
        for(int j=0;j<n;j++){
          if(!inTree[j]&&(min_index==-1 || min_length[j]<min_length[min_index])){
             min_index=j;
          }
        }
        inTree[min_index] = true;
        sum_length += min_length[min_index];
        for(int j=0;j<n;j++){
           if(!inTree[j] && mp[j][min_index]<min_length[j]){
                 min_length[j]=mp[j][min_index];
           }
        }
    }
    return sum_length;
}
struct cell{
    double x, y, z, r;
}p[maxn];
double dist(cell a, cell b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}
int main(){
    int n;
    while(scanf("%d", &n) && n){
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z, &p[i].r);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) mp[i][j] = 0;
                else mp[i][j] = max(0.0, dist(p[i], p[j]) - p[i].r - p[j].r);
            }
        }
        printf("%.3lf\n", prim(n));
    }
    return 0;
}
