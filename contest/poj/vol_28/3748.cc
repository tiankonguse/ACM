#include"iostream"
using namespace std;
char str[20];
int change(char a){
    int na,nb;
    if(a>='a')na=a-87;
    else na=a-'0';
    return na;
}
void print(int n){
   int num[32],cnt=0;
   while(n){
       num[cnt++]=n&1;
       n>>=1;
   }
   for(int i=cnt-1;i>=0;i--){
      printf("%d",num[i]);
   }
   printf("\n");
}
int main(){
    int n,x,y,len;
    scanf("%x,%d,%d",&n,&x,&y);
    len=strlen(str);
    n=n&(~(1<<x));
    n=n|(1<<y);
    n=n|(1<<(y-1));
    n=n&(~(1<<(y-2)));
    printf("%x\n",n);
  //  system("pause");
    return 0;
}
