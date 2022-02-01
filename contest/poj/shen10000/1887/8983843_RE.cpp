#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int str[603];
int map[603];
int max(int a,int b)
{
if(a>=b)return a;
return 	b;
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int n,k=0,i=0,_max,p;
while(p=scanf("%d",&n),p!=EOF)
{
	if(n==-1)continue;
	k++;
	
	
	str[0]=n;
	i=1;

	
	while(scanf("%d",&n),n!=-1)
	    str[i++]=n;	
	
	n=i;
	
	for(i=0;i<=n;i++)map[i]=-1;
	
	_max=-1;
	str[n]=-1;
	map[n]=0;
	
		for(i=n-1;i>=0;i--)
		{
			for(int j=n;j>i;j--)
			{
			    if(str[i]>=str[j]){map[i]=max(map[j]+1,map[i]);}	
			}
			_max=max(_max,map[i]);
	    }
	if(k!=1)putchar('\n');
	printf("Test #%d:\n  maximum possible interceptions: ",k);
	printf("%d\n",_max);
		
}

//getchar();getchar();
return 0;
}
