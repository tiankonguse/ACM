#include"iostream"
#include"string"
using namespace std;
int main(){
    string s;
    int l=0;
    while(cin>>s){
        if(l==0)l+=s.length();
        else
        l+=s.length()+1;
        if(l>80){
                 cout<<endl;
                 l=s.length();
        }
        if(s=="<br>"){cout<<endl;l=0;}
        else if(s=="<hr>"){
          if(l!=4)
          cout<<endl;
          for(int i=0;i<80;i++){
                  printf("-");
          }
          cout<<endl;
          l=0;
        }
        else{
             if(l==s.length())cout<<s;
             else cout<<" "<<s;
        }
          
    }
    cout<<endl;
    return 0;
}
