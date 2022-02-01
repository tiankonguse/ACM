#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MXN 1005
const double ep=1e-8;
const double pi=acos(-1.0);
typedef double ctype;
struct point {
  ctype x,y;
} p[MXN];
int s[MXN],top;
int n;

inline int d_sign(double a) {return fabs(a)<ep? 0: (a>0)? 1: -1;}
inline int d_sign(int a) {return a? a>0? 1 : -1 : 0;}

inline int t_left(int a,int b,int c) {
  return d_sign((p[b].x-p[a].x)*(p[c].y-p[b].y)-(p[c].x-p[b].x)*(p[b].y-p[a].y));
}

int comp_by_crd(const point &a,const point &b) {
  return (a.y==b.y)?(a.x<b.x):(a.y<b.y);
}

double Dis(point &a,point &b)
{
    return sqrt(((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))*1.0);
}


void graham() {
  sort(p+1,p+n+1,comp_by_crd);
  s[1]=1;s[2]=2;top=2;
  for (int i=3;i<=n;++i) {
    while (top>1 && t_left(s[top-1],s[top],i)<=0) --top;
    s[++top]=i;
  }
  int ltop=top;
  s[++top]=n-1;
  for (int i=n-2;i>=1;--i) {
    while (top>ltop && t_left(s[top-1],s[top],i)<=0) --top;
    s[++top]=i;
  }
}

int main() 
{
    double ans;
    int l;
    while(scanf("%d%d",&n,&l)!=EOF)
    {
         for (int i=1;i<=n;++i) 
         {
              scanf("%lf%lf",&(p[i].x),&(p[i].y));
         }
         graham();
         ans=0.0;
         for(int i=1;i<top;i++)
            ans+=Dis(p[s[i]],p[s[i+1]]);
         ans+=2*pi*l;
          printf("%.0f\n",ans);
    }

  return 0;
}

