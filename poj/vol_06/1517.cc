#include"iostream"
#include"string"
using namespace std;
int main(){
    double s=0;
    int factorial(int);
    cout<<"n e"<<endl<<"- -----------"<<endl;

    for(int n=0;n<=9;n++){
        s+=(double)1/factorial(n);
        if(n<3){
                cout<<n<<" "<<s<<endl;
        }
        else{
             printf("%d %.9f\n",n,s);
        }
      
    }
    return 0;
}

int factorial(int n){
    if(n==0) return 1;
    else{
         return n*factorial(n-1);
    }
}
