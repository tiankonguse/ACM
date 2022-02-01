#include"iostream"
using namespace std;
char dat[100]="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
int main(){
    int len;
    char str[100];
    while(gets(str)){
        len=strlen(str);
        for(int i=0;i<len;i++){
            if(str[i]==' ')printf(" ");
            else{
                for(int j=0;j<47;j++){
                   if(str[i]==dat[j]){
                        printf("%c",dat[j-1]);
                        break;
                   }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
