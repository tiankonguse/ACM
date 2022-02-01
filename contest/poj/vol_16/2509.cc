#include"iostream"
using namespace std;
int main(){
    int n,k,t;
    while(cin>>n>>k){
        t=n;
        while(t>=k){
           n+=t/k;
           t=t/k+t%k;
        }
        cout<<n<<endl;
    }
    return 0;
}
