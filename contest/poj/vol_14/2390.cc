#include"iostream"
#include"cmath"
using namespace std;
int main(){
    double a,b,n;
    cin>>a>>b>>n;
    cout<<(int)(pow(a/100.0+1,n)*b)<<endl;
    return 0;
}
