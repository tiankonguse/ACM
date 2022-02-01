#include<stdio.h>
#include<string.h>
bool map[100];
int str[30];
int next[60];
int num[60];

int find(int j)
{
	int sum=1;
	int i=j;
	j--;
	while(map[j])
	{
		sum+=num[j];
		j=next[j]-1;
	}
	next[i]=j;
	num[i]=sum;
	return sum;
}

int main()
{
int n,now,l,r;
scanf("%d",&n);

while(scanf("%d",&n)!=EOF)
{
	memset(num,0,sizeof(num));
	memset(next,0,sizeof(next));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&str[i]);
	}
	now=0;
	int j=0;
	for(int i=1;i<=n;i++)
	{
		while(now<str[i])
		{
			map[j++]=false;
			now++;
		}
		map[j++]=true;
	}
	n=n+n;
	bool yes=false;
	for(int j=0;j<n;j++)
	{
		if(map[j])
		{
			if(yes)printf(" ");
			printf("%d",find(j));
			yes=true;
		}
	}
	printf("\n");
}
return 0;	
}
