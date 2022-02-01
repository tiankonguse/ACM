#include"iostream"
#include"algorithm"
#include"cmath"
using namespace std;
const double pi=acos(-1.0);
struct point{
       double x,y;
}pnt[1001],res[1001];
bool mult(point sp,point ep,point op){
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool operator < (const point &l,const point &r){
  return l.y<r.y || (l.y==r.y && l.x<r.x);
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
double dist(double x1,double y1,double x2,double y2){
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    int N,L,ans;
    double cir;
    while(~scanf("%d%d",&N,&L)){
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
        }
        ans=graham(pnt,N,res);
       /* for(int i=0;i<ans;i++){
           printf("%lf,%lf\n",res[i].x,res[i].y);
        }*/
        cir=dist(res[0].x,res[0].y,res[ans-1].x,res[ans-1].y);
        for(int i=0;i<ans-1;i++){
          cir+=dist(res[i].x,res[i].y,res[i+1].x,res[i+1].y);
        }
        printf("%d\n",(int)(cir+2*pi*L+0.5));
    }
    return 0;
}
