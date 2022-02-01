#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str[1003];
int map[1003];
int max(int a,int b)
{
if(a>=b)return a;
return 	b;
}

int main()
{
int n,i,j,_max=-1;;
memset(str,-1,sizeof(str));
memset(map,-1,sizeof(map));
scanf("%d",&n);

for(i=1;i<=n;i++)scanf("%d",&str[i]);

str[0]=-1;
map[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
		    if(str[i]>str[j]){map[i]=max(map[j]+1,map[i]);}	
		}
		_max=max(_max,map[i]);
    }


printf("%d\n",_max);

    getchar();getchar();
return 0;
}
