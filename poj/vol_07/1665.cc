#include"iostream"
using namespace std;
int main(){
    double d,t,di,s,pi=3.1415927;
    int r,c=1;
    while(cin>>d>>r>>t){
       if(r==0)break;
       di=d*pi*r/63360;
       s=di/t*3600;
       printf("Trip #%d: %.2f %.2f\n",c++,di,s);
    }
}
