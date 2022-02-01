#include"iostream"
using namespace std;
char str[10];
int a[3]={9,3,7};
int main(){
    int T,len,sum,k,h;
    scanf("%d",&T);
    for(int c=1;c<=T;c++){
        scanf("%s",str);
        len=strlen(str);
        sum=0;
        for(int i=len-1,j=0;i>=0;i--,j++){
             if(str[i]=='?'){
                k=a[j%3];
                h=i;
             }
             else{
                sum+=(str[i]-'0')*a[j%3];
             }
        }
        for(int i=0;i<=9;i++){
             if((k*i+sum)%10==0){
                 str[h]=i+'0';
                 printf("Scenario #%d:\n%s\n\n",c,str);
             }
        }
    }
   // system("pause");
    return 0;
}
