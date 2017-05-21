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
#define MAXN 222
using namespace std;

double x,y,r;
const double eps = 1e-6;
double dis[MAXN];
struct points{
    double x,y;
}p[MAXN];
double dist(double x1,double y1,double x2,double y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
double xmul(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
int main(){
    int n;
    while(~scanf("%lf %lf %lf",&x,&y,&r) && r>0){
        r = r*r;
        scanf("%d",&n);
        int q;
        for(q=0;q<n;q++){
            scanf("%lf %lf",&p[q].x,&p[q].y);
            dis[q] = dist(p[q].x,p[q].y,x,y);
            if(dis[q] > r){n--;q--;}
        }

        double sx,sy;
        int tnt,ans=0;
        for(int i=0;i<n;i++){
            sx=p[i].x-x;
            sy=p[i].y-y;
            tnt=0;
            for(int j=0;j<n;j++){
                if(xmul(sx,sy,p[j].x-x,p[j].y-y) >= 0)tnt++;
            }
            ans=max(ans,tnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
