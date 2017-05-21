#include"iostream"
using namespace std;
int inverse(char* s,int len){
    int sum=0;
    for(int i=len-1;i>=0;i--){
       sum=sum*10+(s[i]-'0');
    }
    return sum;
}
char str[50],a[10],b[10],c[10];
int main(){
    int len,f,l1,l2,l3;
    while(~scanf("%s",str)){
       len=strlen(str);
       f=l1=l2=l3=0;
       for(int i=0;i<len;i++){
           if(f==0){
               if(str[i]=='+'){
                  f=1;
               }
               else a[l1++]=str[i];
           }
           else if(f==1){
               if(str[i]=='='){
                  f=2;
               }
               else b[l2++]=str[i];
           }
           else c[l3++]=str[i];
       }
       if(inverse(a,l1)+inverse(b,l2)==inverse(c,l3)){
          printf("True\n");
       }
       else printf("False\n");
    }
    return 0;
}
