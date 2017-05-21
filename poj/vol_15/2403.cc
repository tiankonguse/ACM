#include"iostream"
#include"string"
#include"map"
using namespace std;
int main(){
    int N,M,a,sum;
    string s;
    map<string,int> ma;
    cin>>N>>M;
    while(N--){
       cin>>s>>a;
       ma[s]=a;
    }
    while(M--){
       sum=0;
       while(cin>>s){
          if(s==".")break;
          sum+=ma[s];
       }
       cout<<sum<<endl;
    }
   // system("pause");
    return 0;
}
