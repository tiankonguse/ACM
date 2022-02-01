#include"iostream"
using namespace std;
char str[1024];
int main(){
    int len;
    while(gets(str)){
        len=strlen(str);
        for(int i=0;i<=len-3;i++){
            if(str[i]=='y' && str[i+1]=='o' && str[i+2]=='u'){
                str[i]='w';
                str[i+1]='e';
                str[i+2]=0;
            }
        }
        for(int i=0;i<len;i++){
            if(str[i]!=0)printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
