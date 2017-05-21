#include"iostream"
#include"stack"
#include"string"
using namespace std;
stack<string>st1,st2;
int main(){
    string s,s1,s2;
    s1="http://www.acm.org/";
    while(cin>>s){
       if(s=="QUIT")break;
       if(s=="VISIT"){
           st1.push(s1);
           while(!st2.empty())st2.pop();
           cin>>s1;
           cout<<s1<<endl;
       }
       else if(s=="BACK"){
           if(st1.empty())cout<<"Ignored"<<endl;
           else{
              st2.push(s1);
              s1=st1.top();
              st1.pop();
              cout<<s1<<endl;
           }
       }
       else if(s=="FORWARD"){
           if(st2.empty())cout<<"Ignored"<<endl;
           else{
              st1.push(s1);
              s1=st2.top();
              st2.pop();
              cout<<s1<<endl;
           }
       }
       
    }
    return 0;
}
