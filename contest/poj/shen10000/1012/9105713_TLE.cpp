#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	int k,m;
	while(scanf("%d",&k),k)
	{
	m=k;
	while(1)
	{
		m++;
		int now=1,mod=k+k;
		while(1)
		{
			now=(now+m-2)%mod+1;
			if(now>k)
			{
				if(now==mod)now=1;
				mod--;	
			}
			else break;	
		}	
		if(mod==k)break;		
	}	
		printf("%d\n",m);		
	}

return 0;
}
