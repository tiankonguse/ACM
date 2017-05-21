#include"iostream"
#include"cstdlib"
using namespace std;
int add(int *a,int *b,int *c)
{
  int i;
  for(i=*a+1;i<=*a+*b+5;i++) a[i]=0;
  for(i=*b+1;i<=*a+*b+5;i++) b[i]=0;
  for(i=1;i<=(*a+*b+5);i++) c[i]=a[i]+b[i];
  for(i=1;i<=*a+*b+3;i++)
      {
       c[i+1]=c[i+1]+c[i]/10;
       c[i]=c[i]%10;
      }
  for(i=*a+*b+4;i>=1;i--)
    if (c[i]) break;
  c[0]=i;
  return i;
}
int a[400],b[400],c[400];
int main(){

    char s[400];
    b[0]=1;
    b[1]=0;
    while(scanf("%s",s)){
      int l=strlen(s);
      if(s[0]=='0' && l==1)break;
      a[0]=l;
      for(int i=0;i<l;i++){
          a[l-i]=s[i]-48;
      }
      add(a,b,c);
      memcpy(b,c,sizeof(c));
    }
    for(int i=c[0];i>=1;i--){
        printf("%d",c[i]);
    }
    printf("\n");
    //system("pause");
    return 0;
}
