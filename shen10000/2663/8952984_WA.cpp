#include<stdio.h>
int str[16]={1,3,11,41,153,571,2131,7953,29681,110771,413403,1542841,5757961,21489003,80198051,299303201};
int n;
int main()
{
while(scanf("%d",&n),n+1)
{
if(n&1){printf("0\n");continue;}
printf("%d\n",str[n]);
}
return 0;
}
