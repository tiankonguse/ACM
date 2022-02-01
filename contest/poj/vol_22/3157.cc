#include"iostream"
using namespace std;
char str[105];
int main(){
    int len;
    bool java,cpp;
    while(~scanf("%s",str)){
       len=strlen(str);
       java=cpp=true;
       if(!(str[0]>='a' && str[0]<='z'))printf("Error!\n");
       else{
          for(int i=0;i<len;i++){
              if(str[i]=='_'){
                  java=false;
                  if(i==len-1 || str[i+1]=='_')cpp=false;
              }
              if(str[i]>='A' && str[i]<='Z')cpp=false;
          }
          if(!java && !cpp) printf("Error!\n");
          else if(cpp){
                 for(int i=0;i<len;i++){
                    if(str[i]=='_')str[i+1]-=32;
                    else printf("%c",str[i]);
                 } 
                 printf("\n");
          }
          else{
                 for(int i=0;i<len;i++){
                    if(str[i]>='A' && str[i]<='Z'){
                        str[i]+=32;
                        printf("_");
                    }
                    printf("%c",str[i]);
                 }
                 printf("\n");
          }
       }
    }
    return 0;
}
