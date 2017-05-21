#include"iostream"
#include"string"
using namespace std;
int main(){
    string s;
    while(cin>>s){
                   if(s=="end")break;
       int l=s.length();
       int orr,opp,ss=0,f1=0,f2=1,f3=1;
       for(int i=0;i<l;i++){
               switch(s[i]){
                            case 'a':orr=1;f1=1;break;
                            case 'e':orr=1;f1=1;break;
                            case 'i':orr=1;f1=1;break;
                            case 'o':orr=1;f1=1;break;
                            case 'u':orr=1;f1=1;break;
                            default:orr=-1;break;
               }
                                 
               if(i==0){
                    opp=orr;    
                    ss=orr;
               }
               else{
                    
                    if(s[i]==s[i-1] && s[i]!='e' && s[i]!='o'){
                                    f2=0;
                                    break;
                    }
                    
                    
                    if(opp==orr){
                               ss+=orr;
                               if(ss<=-3 || ss>=3){
                                         f2=0;
                                         break;
                               }
                    }
                    else{
                         opp=orr;
                         ss=orr;
                    }
               }
       }
       if(f1 && f2 && f3){
             cout<<"<"<<s<<"> is acceptable."<<endl;
       }
       else{
            cout<<"<"<<s<<"> is not acceptable."<<endl;
       }
       
      
    }
    return 0;
}
