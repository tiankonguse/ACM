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
#include <complex>

#define MAXN 100
#define eps (1e-4)
#define x real()
#define y imag()
using namespace std;
typedef complex<double> Point;
inline int sgn(double a){return (a>eps) - (a<-eps);}
double cross(Point a,Point b){return imag(conj(a)*b);}
double dmul(Point a,Point b){return real(conj(a)*b);}
bool crosspoint(Point p1,Point p2,Point q1,Point q2){
    double a=cross(p2-p1,q2-q1),b=cross(p2-p1,p2-q1),c=cross(q2-q1,p2-p1),d=cross(q2-q1,q2-p1);
    if(a==0){return b!=0? 0 : (sgn(dmul(q1-p1,q1-p2))<=0 || sgn(dmul(q2-p1,q2-p2))<=0);}
    else return (sgn(b/a)>=0 && sgn(b/a-1)<=0 && sgn(d/c)>=0 && sgn(d/c-1)<=0);
}

Point line[MAXN][2];

int parents[MAXN];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}
void init(){
    memset(parents, 0xff, sizeof(parents));
}

int main(){
    int N,a,b,ra,rb;
    while(scanf("%d",&N) && N){
        for(int i=0;i<N;i++){
            scanf("%lf%lf%lf%lf", &line[i][0].x, &line[i][0].y, &line[i][1].x, &line[i][1].y);
        }
        init();
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(crosspoint(line[i][0], line[i][1], line[j][0], line[j][1])){
                    ra = Find(i);
                    rb = Find(j);
                    if(ra != rb) Union(ra,rb);
                }
            }
        }
        while(scanf("%d%d",&a,&b), a+b){
            if(Find(a - 1) == Find(b - 1))puts("CONNECTED");
            else puts("NOT CONNECTED");
        }
    }
    return 0;
}
