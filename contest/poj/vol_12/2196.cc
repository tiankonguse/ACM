#include"iostream"
using namespace std;
int dgs(int n,int d){
   int sum=0;
   while(n){
       sum+=n%d;
       n/=d;
   }
   return sum;
}
int main(){
    int d1,d2,d3;
    for(int i=2992;i<=9999;i++){
        d1=dgs(i,10);
        d2=dgs(i,12);
        d3=dgs(i,16);
        if(d1==d2 && d1==d3)printf("%d\n",i);
    }
    return 0;
}
