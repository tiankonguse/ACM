#include"iostream"
#include"map"
#include"string"
using namespace std;
map<string,string>mp;
int main(){
    int L,N,len;
    string s0,s1;
    char c,c2;
    cin>>L>>N;
    for(int i=0;i<L;i++){
       cin>>s0>>s1;
       mp[s0]=s1;
    }
    for(int i=0;i<N;i++){
       cin>>s0;
       len=s0.length();
       if(mp.find(s0)!=mp.end()){
          cout<<mp[s0]<<endl;
       }
       else{
          if(len==1){
                     c=s0[len-1];
                     if(c=='o' || c=='s' || c=='x')cout<<s0<<"es"<<endl;
                     else cout<<s0<<"s"<<endl;
          }
          else{
               c=s0[len-1];
               c2=s0[len-2];
               if(c=='y'){
                   if(c2!='a' && c2!='e' && c2!='i' && c2!='o' && c2!='u'){
                      for(int j=0;j<len-1;j++)cout<<s0[j];
                      cout<<"ies"<<endl;
                   }
                   else cout<<s0<<"s"<<endl;
               }
               else if(c=='o' || c=='s' || c=='x' ||(c=='h' && (c2=='c' || c2=='s'))){
                    cout<<s0<<"es"<<endl;
               }
               else cout<<s0<<"s"<<endl;
          }
       }
    }
   // system("pause");
    return 0;
}
