#include"iostream"
#include"cmath"
using namespace std;
int main(){
    char ch1,ch2;
    double a,b,c,e,t,d,h,he;
    while(scanf(" %c",&ch1)){
        if(ch1=='E')break;
        scanf(" %lf %c %lf",&a,&ch2,&b);
        if(ch1=='T')t=a;
        else if(ch1=='D')d=a;
        else if(ch1=='H')h=a;
        if(ch2=='T')t=b;
        else if(ch2=='D')d=b;
        else if(ch2=='H')h=b;
        
        if(ch1+ch2=='T'+'D'){
            e = 6.11*exp(5417.7530 * ((1.0/273.16) - (1.0/(d+273.16))));
            he = (0.5555)* (e - 10.0);
            h=he+t;
        }
        else if(ch1+ch2=='T'+'H'){
            he=h-t;
            e=he/0.5555+10.0;
            d=1.0/(1.0/273.16-log(e/6.11)/5417.7530)-273.16;
        }
        else{
            e = 6.11*exp(5417.7530 * ((1.0/273.16) - (1.0/(d+273.16))));
            he = (0.5555)* (e - 10.0);
            t=h-he;
        }
        printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
    }
    return 0;
}
