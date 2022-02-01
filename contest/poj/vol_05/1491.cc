#include"iostream"
#include"cmath"
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
    int N,a[50];
    while(cin>>N){
       if(N==0)break;
       for(int i=0;i<N;i++){
               cin>>a[i];
       }
       int k=0;
       for(int i=0;i<N;i++){
               for(int j=i+1;j<N;j++){
                       if(gcd(a[i],a[j])==1)k++;
               }
       }       
       if(k){
            printf("%.6lf\n",sqrt(6.0/(double)k*(double)(N*(N-1)/2)));
       }
       else cout<<"No estimate for this data set."<<endl;
    }
    return 0;
}
