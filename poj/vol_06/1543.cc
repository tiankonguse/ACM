#include"iostream"
using namespace std;
int main(){
    int a,b,c,d;
    int N;
    cin>>N;
    for(a=6;a<=N;a++){
       for(b=2;b<a;b++){
         for(c=b+1;c<a;c++){
            for(d=c+1;d<a;d++){
              if(a*a*a==b*b*b+c*c*c+d*d*d){
                printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
              }
            }
         }
       }
    }
    return 0;
}
