#include<stdio.h>
int main()
{
int n,m;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
scanf("%d",&m);
printf("%d",i);
int p2=25;
int p1=m/p2;m=m-p1*p2;
printf(" %d QUARTER(S),",p1);
p2=10;
p1=m/p2;m=m-p1*p2;

printf(" %d DIME(S),",p1);
p2=5;
p1=m/p2;m=m-p1*p2;

printf(" %d NICKEL(S),",p1);
printf(" %d PENNY(S)\n",m);	
	
}

    getchar();getchar();
return 0;
}
