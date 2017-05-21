#include"iostream"
#include"cmath"
using namespace std;
struct color{
   double r,g,b;
}data[17],col;
double d(double a1,double b1,double c1,double a2,double b2,double c2){
   return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2)+(c1-c2)*(c1-c2));
}
int main(){
    double min,dd;
    int p;
    for(int i=0;i<16;i++)scanf("%lf%lf%lf",&data[i].r,&data[i].g,&data[i].b);
    while(scanf("%lf%lf%lf",&col.r,&col.g,&col.b)){
        if(col.r==-1 && col.g==-1 && col.b==-1)break;
           min=1e9;
           for(int i=0;i<16;i++){
               dd=d(col.r,col.g,col.b,data[i].r,data[i].g,data[i].b);
               if(dd<min){min=dd;p=i;}
           }    
           printf("(%.0lf,%.0lf,%.0lf) maps to (%.0lf,%.0lf,%.0lf)\n",
                    col.r,col.g,col.b,data[p].r,data[p].g,data[p].b);
        
    }
    return 0;
}
