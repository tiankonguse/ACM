#include <iostream>
#include <string>
using namespace std;
int mul(int *a,int *b,int *c)
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
int main()
{
    #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
    #endif
    string s1,s2;
    int a[100],b[100],c[200];
    int la,lb;
    cin>>s1>>s2;
    la=s1.length();
    lb=s2.length();
    int k=0,pa=1,pb=1,p1=la-1,p2=lb-1;
    for(int i=la-1;i>=0;i--){
       if(s1[i]=='.')p1=i;
       else a[pa++]=s1[i]-48;
    }
    for(int i=lb-1;i>=0;i--){
       if(s2[i]=='.')p2=i;
       else b[pb++]=s2[i]-48;
    }
    a[0]=pa-1;
    b[0]=pb-1;
    int p=la-p1+lb-p2-2;
    int pc=mul(a,b,c);
    int en=1;
    for(int i=1;i<=p;i++){
       if(c[i]!=0)break;
       else en++;
    }
    if(p>=pc)pc=p+1;
    for(int i=pc;i>=en;i--){
       if(i==p)printf(".");
       printf("%d",c[i]);
    }
    printf("\n");

    return 0;
}
