#include"iostream"
#include"string"
using namespace std;
int main(){
    string s,t;
    while(cin>>s>>t){
         int k=0,f=0;
         for(int i=0;i<t.length();i++){
                 if(s[k]==t[i]){
                         k++;
                 }
                 if(k==s.length() && s[k-1]==t[i]){
                    f=1;
                    break;
                 }
         }
         if(f)cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
    }
    return 0;
}
