#include<stdio.h>
#include<string.h>
int str[31];
int n;

int fun(int n)
{
if(str[n]!=-1)return str[n];
return str[n]=4*fun(n-2)-fun(n-4);		
}

int main()
{
memset(str,-1,sizeof(str));
str[0]=1;
str[1]=0;
str[2]=3;
str[3]=0;
while(scanf("%d",&n),n+1)
{
if(n&1){printf("0\n");continue;}
printf("%d\n",fun(n));
}
return 0;
}
/*
//int str[16]={1,3,11,41,153,571,2131,7953,29681,110771,413403,1542841,5757961,21489003,80198051,299303201};
while(scanf("%d",&n),n+1)
{
if(n&1){printf("0\n");continue;}
printf("%d\n",str[n>>1]);
}



*/
