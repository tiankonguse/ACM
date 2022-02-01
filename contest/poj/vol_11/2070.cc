#include"iostream"
using namespace std;
int main(){
    int cnt;
    bool f1,f2,f3;
    double sp,w,st;
    while(scanf("%lf%lf%lf",&sp,&w,&st)){
       if(sp==0 && w==0 && st==0)break;
       cnt=0;
       f1=f2=f3=false;
       if(sp<=4.5 && w>=150 && st>=200){cnt++;f1=true;}
       if(sp<=6.0 && w>=300 && st>=500){cnt++;f2=true;}
       if(sp<=5.0 && w>=200 && st>=300){cnt++;f3=true;}
       if(f1 || f2 || f3){
           if(f1)if(cnt--==1)printf("Wide Receiver\n");
                 else printf("Wide Receiver ");
           if(f2)if(cnt--==1)printf("Lineman\n");
                 else printf("Lineman ");
           if(f3)if(cnt--==1)printf("Quarterback\n");
                 else printf("Quarterback ");
       }
       else printf("No positions\n");
    }
    return 0;
}
