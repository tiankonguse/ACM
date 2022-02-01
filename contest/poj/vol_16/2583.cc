#include"iostream"
using namespace std;
int main(){
    int a,b,c,f0,f1,f2;
    while(cin>>f0>>f1>>f2){
       c=f0;
       a=(f2-2*f1+f0)/2;
       b=f1-f0-a;
       cout<<a*9+b*3+c<<" "<<a*16+b*4+c<<" "<<a*25+b*5+c<<endl;
    }
    return 0;
}
