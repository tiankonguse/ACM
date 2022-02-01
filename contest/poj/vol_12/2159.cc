#include"iostream"
#include"algorithm"
#include"cstdlib"
#include"string"
using namespace std;
int a1[26],a2[26];
int main(){
    char s1[101],s2[101];
    while(~scanf("%s%s",s1,s2)){
       int len=strlen(s1);
       for(int i=0;i<len;i++){
          a1[s1[i]-'A']++;
          a2[s2[i]-'A']++;
       }
       sort(a1,a1+26);
       sort(a2,a2+26);
       bool flag=true;
       for(int i=0;i<26;i++){
          if(a1[i]!=a2[i]){
              flag=false;
              break;
          }
       }
       if(flag)printf("YES\n");
       else printf("NO\n");
    }
    return 0;
}
