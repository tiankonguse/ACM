#include"iostream"
#include"string"
using namespace std;
char str[201];
int main(){
    int len;
    char t;
    while(gets(str)){
       if(strcmp(str,"ENDOFINPUT")==0)break;
       gets(str);
       len=strlen(str);
       for(int i=0;i<len;i++){
          if(str[i]>='A' && str[i]<='Z'){
             t=str[i]-5;
             if(t<'A')t+=26;
             printf("%c",t);  
          }
          else printf("%c",str[i]);
       }
       printf("\n");
       gets(str);
    }
    return 0;
}
