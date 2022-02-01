#include"iostream"
#include"string"
using namespace std;
string code[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",
                 ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...",
                 "-","..-","...-",".--","-..-","-.--","--.."};
string spec[4]={"..--",".-.-","---.","----"};
int leng[26]={2,4,4,3,1,4,3,4,2,4,3,4,2,2,3,4,4,3,3,1,3,4,3,4,4,4};
int num[200];
int main(){
    int T,len,cnt,d,now;
    string s,s0,t;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
       cin>>s;
       s0="";
       cnt=now=0;
       len=s.length();
       for(int i=0;i<len;i++){
           if(s[i]=='_'){s0+=spec[0];num[cnt++]=4;}
           else if(s[i]==','){s0+=spec[1];num[cnt++]=4;}
           else if(s[i]=='.'){s0+=spec[2];num[cnt++]=4;}
           else if(s[i]=='?'){s0+=spec[3];num[cnt++]=4;}
           else{d=s[i]-'A';s0+=code[d];num[cnt++]=leng[d];}
       }
       printf("%d: ",ca);
       for(int i=cnt-1;i>=0;i--){
           t=s0.substr(now,num[i]);
           now+=num[i];
           if(t==spec[0])printf("_");
           else if(t==spec[1])printf(",");
           else if(t==spec[2])printf(".");
           else if(t==spec[3])printf("?");
           else{for(int j=0;j<26;j++)if(t==code[j]){printf("%c",j+'A');break;}}
       }
       printf("\n");
    }
    return 0;
}
