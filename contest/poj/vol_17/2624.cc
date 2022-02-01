#include"iostream"
using namespace std;
double x[4],y[4];
int main(){
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",x,y,x+1,y+1,x+2,y+2,x+3,y+3)){
        if(x[0]==x[2] && y[0]==y[2])printf("%.3lf %.3lf\n",x[1]+x[3]-x[0],y[1]+y[3]-y[0]);
        else if(x[0]==x[3] && y[0]==y[3])printf("%.3lf %.3lf\n",x[1]+x[2]-x[0],y[1]+y[2]-y[0]);
        else if(x[1]==x[2] && y[1]==y[2])printf("%.3lf %.3lf\n",x[0]+x[3]-x[1],y[0]+y[3]-y[1]);
        else printf("%.3lf %.3lf\n",x[0]+x[2]-x[1],y[0]+y[2]-y[1]);
    }
    return 0;
}
