#include"iostream"
using namespace std;
double min(double a,double b){
   return a<b?a:b;
}
int main(){
    double r,x1,y1,x2,y2,t;
    int res;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)&&x1){
        if(x1<y1){t=x1;x1=y1;y1=t;}
        if(x2<y2){t=x2;x2=y2;y2=t;}
        r=min(x2/x1,y2/y1);
        res=(int)(r*100);
        if(res>100)res=100;
        printf("%d%%\n",res);
    }
    return 0;
}
