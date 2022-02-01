#include<stdio.h>
#include<string.h>
#include<stdlib.h>
__int64 str[55][2];

int main()
{
int n,k;
str[0][1]=1;
str[0][0]=1;
for(int i=1;i<50;i++){
	str[i][1]=str[i-1][0];
	str[i][0]=str[i-1][0]+str[i-1][1];
}
scanf("%d",&n);
for(int i=1;i<=n;i++){
	scanf("%d",&k);
	printf("Scenario #%d:\n%I64d\n\n",i,str[k][0]);
}
return 0;
}
