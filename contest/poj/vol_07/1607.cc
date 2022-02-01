#include"iostream"
using namespace std;
int main(){
    int N;
    double s;
    cout<<"Cards  Overhang"<<endl;
    while(cin>>N){
       s=0;
       for(double i=2;i<2*N+1;i+=2){
         s+=1.0/i;        
       }
       printf("%5d     %.3f\n",N,s);
    }
    return 0;
}
