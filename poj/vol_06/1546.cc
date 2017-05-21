#include"iostream"
#include"string"
using namespace std;
string change(string s,int f,int t){
   string s1="";
   int l=s.length();
   int sum=0,a,u=1;
   char c;
   for(int i=l-1;i>=0;i--){
      if(s[i]>=65)a=s[i]-55;
      else a=s[i]-48;
      sum+=a*u;
      u*=f;
   }
   while(sum){
      a=sum%t;
      if(a>=10)c=a+55;
      else c=a+48;
      s1=c+s1;
      sum/=t;
   }
   return s1;
}
int main(){
    string s,s1;
    int f,t;
    while(cin>>s>>f>>t){
        s1=change(s,f,t);
        cout.width(7);
        if(s1.length()>7)cout<<"ERROR"<<endl;
        else{
             cout<<s1<<endl;
        }
    }
    return 0;
}
