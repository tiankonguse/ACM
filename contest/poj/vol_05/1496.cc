#include"iostream"
using namespace std;
int c[27][27];
void init(){
   for(int i=0;i<=26;i++){
       c[i][0]=1;
   }
   for(int i=1;i<=26;i++){
       for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
       }
   }
}
char str[11];
int main(){
    bool flag;
    int len,res,ch;
    init();
    while(~scanf("%s",str)){
        res=0;
        flag=false;
        len=strlen(str);
        for(int i=1;i<len;i++){
            if(str[i]<=str[i-1]){
               printf("0\n");
               flag=true;
               break;
            }
        }
        if(flag)continue;
        
        for(int i=0;i<len;i++){
            res+=c[26][i];
        }
        int t=-1;
        for(int i=1;i<=len;i++){
            ch=str[i-1]-'a';
            for(int j=t+1;j<ch;j++){
                res+=c[26-j-1][len-i];
            }
            t=ch;
        }
        printf("%d\n",res);
    }
    return 0;
}
