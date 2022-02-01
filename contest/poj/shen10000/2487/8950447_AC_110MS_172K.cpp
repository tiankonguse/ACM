#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str[1002];
int cmp(void const *a,void const *b)
{
return (*(int*)b-*(int*)a);	
}
int main()
{
int n,j,i,num,p;
scanf("%d",&n);
for(i=0;i<n;i++)
{printf("Scenario #%d:\n",i+1);
	scanf("%d%d",&num,&p);	
	for(j=0;j<p;j++)scanf("%d",&str[j]);	
	qsort(str,p,sizeof(int),cmp);
	for(j=0;j<p;j++)
	{
	num-=str[j];
	if(num<=0)break;	
	}
	if(j>=p)printf("impossible\n\n");
	else printf("%d\n\n",j+1);	
}
    getchar();getchar();
return 0;
}
