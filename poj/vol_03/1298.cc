#include"iostream"
#include"string"
using namespace std;
int main(){
    string s;
    int d;
    while(getline(cin,s)){
       if(s=="ENDOFINPUT")break;
       getline(cin,s);
       for(int i=0;i<s.length();i++){
               d=s[i];
               if(d>=65 && d<=69) s[i]+=21;
               else if(d>=69 && d<=90) s[i]-=5;      
       }
       cout<<s<<endl;
       getline(cin,s);
    }
    return 0;
}
