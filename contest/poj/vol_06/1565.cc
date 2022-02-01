#include"iostream"
#include"string"
using namespace std;
char str[50];
int data[32];
int main(){
    int l,res;
    for(int i=0;i<32;i++){
       data[i]=1<<i;
    }
    while(scanf("%s",str)){
       if(strcmp(str,"0")==0)break;
       l=strlen(str);
       res=0;
       for(int i=0;i<l;i++){
          res+=(data[i+1]-1)*(str[l-i-1]-'0');
       }
       printf("%d\n",res);
    }
    return 0;
}
