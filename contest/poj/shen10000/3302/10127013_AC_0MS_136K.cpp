#include<stdio.h>
#include<string.h>

void rever(char*p)
{
	int len=strlen(p)-1;	
	for(int i=0;i<len;i++,len--)
	{
		p[i]^=p[len];
		p[len]^=p[i];
		p[i]^=p[len];	
	}
}

bool yes(char *p,char *q)
{
	int i,j;
	for(j=i=0;p[i] && q[j];i++)
	{
		if(p[i]==q[j])j++;	
	}
	if(!q[j])return true;
	rever(q);
	for(j=i=0;p[i] && q[j];i++)
	{
		if(p[i]==q[j])j++;	
	}
	if(!q[j])return true;
	
	return false;	
}

int main()
{
	char str1[1000],str2[1000];
	int n;
	scanf("%d",&n);
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		printf("%s\n",yes(str1,str2)?"YES":"NO");	
	}
	return 0;	
}
