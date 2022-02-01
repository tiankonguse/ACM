#include"iostream"
#include"cstdlib"
using namespace std;
int num[251][501];
int gjd_add(int *a,int *b,int *c)
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
int gjd_min(int *a,int *b)
{
  int i;
  for(i=1;i<=*b;i++)
     a[i]=a[i]-b[i];
  for(i=1;i<=*a;i++)
      if (a[i]<0)
      {
        a[i+1]--;
        a[i]+=10;
      }
  for(i=*a;i>=1;i--)
    if (a[i]) break;
  a[0]=i;
  return i;
}
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
int main(){
    num[0][0]=1;
    num[0][1]=1;
    num[1][0]=1;
    num[1][1]=1;
    int temp1[501],temp2[501];
    temp1[0]=1;
    temp1[1]=2;
    for(int i=2;i<=250;i++){
       gjd_mul(num[i-2],temp1,temp2);
       gjd_add(num[i-1],temp2,num[i]);
    }
    int n;
    while(scanf("%d",&n)!=EOF){
       for(int i=num[n][0];i>=1;i--){
         printf("%d",num[n][i]);
       }
       printf("\n");
    }
    return 0;
}
