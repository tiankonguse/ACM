#include"iostream"
#include"cstdlib"
using namespace std;
int gjd_mul(int *a,int *b,int *c)
{
  int i,j;
  for(i=*a+1;i<=*a+*b+5;i++) a[i]=0;
  for(i=*b+1;i<=*a+*b+5;i++) b[i]=0;
  for(i=0;i<=*a+*b+5;i++) c[i]=0;
  for(i=1;i<=*a;i++)
   for(j=1;j<=*b;j++)
     c[i+j-1]+=a[i]*b[j];
   for(i=1;i<=*a+*b+5;i++)
   {
      c[i+1]=c[i+1]+c[i]/10;
       c[i]=c[i]%10;
   }
   for(i=*a+*b+5;i>=1;i--)
        if (c[i]) break;
  c[0]=i;
  return i;
}
char num[100];
int a[100],b[100],c[100];
int main(){
    int len,lc;
    bool flag;
    while(~scanf("%s",num)){
       len=strlen(num);
       a[0]=len;
       for(int i=1;i<=len;i++){
          a[i]=num[len-i]-'0';
       }
       if(len<9){
          b[0]=1;
          b[1]=len+1;
       }
       else{
          b[0]=2;
          b[1]=(len+1)%10;
          b[2]=(len+1)/10;
       }
       lc=gjd_mul(a,b,c);
       flag=true;
       for(int i=lc;i>=1;i--){   
          if(c[i]!=9){flag=false;break;}
       }
       if(flag)printf("%s is cyclic\n",num);
       else printf("%s is not cyclic\n",num);
    }
    return 0;
}
