#include"iostream"
using namespace std;
int main(){
    char s[100];
    while(gets(s)){
       if(s[0]=='#')break;
       for(int i=0;i<strlen(s);i++){
          if(s[i]==' ')printf("%%20");
          else if(s[i]=='!')printf("%%21");
          else if(s[i]=='$')printf("%%24");
          else if(s[i]=='%')printf("%%25");
          else if(s[i]=='(')printf("%%28");
          else if(s[i]==')')printf("%%29");
          else if(s[i]=='*')printf("%%2a");
          else printf("%c",s[i]);
       }
       printf("\n");
    }
    return 0;
}
