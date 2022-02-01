#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool map[1002];
int sum=0;

void fun(int d,int f)
{
if(map[d]==f)return;
map[d]=f;
sum++;
if(d==1){return;}

if(d==2){fun(1,1);return;}	

	fun(d-1,1);

	for(int i=d-2;i>=1;i--)
		fun(i,0);	
}

int main()
{

	int n,m,p;
	while(scanf("%d",&n)!=EOF)
	{
	p=sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		map[i]=m;
		if(m)p=i;
	}
	for(int i=p;i>=1;i--)
    {
		if(map[i])fun(i,0);		
	}
	printf("%d\n",sum);
} 
return 0;    
}
