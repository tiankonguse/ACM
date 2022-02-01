#include"iostream"
#include"string"
using namespace std;
int main(){
    string s,s0;
    char c,tmp[10];
    int T,cnt,len;
    cin>>T;
    while(T--){
       cin>>s;
       s0="";
       c='.';
       cnt=0;
       len=s.length();
       for(int i=0;i<len;i++){
           if(s[i]==c)cnt++;
           else {
              if(cnt!=0){
                sprintf(tmp,"%d",cnt);
                s0+=tmp;
                s0+=c;
              }
              cnt=1;
              c=s[i];
           }
       }
       if(cnt!=0){
                sprintf(tmp,"%d",cnt);
                s0+=tmp;
                s0+=c;
       }
       cout<<s0<<endl;
    }
    return 0;
}
