#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
int main()
{
	int n,i,res,tmp;
	while(scanf("%d",&n),res=n)
	{
		tmp= (int)(sqrt(n*1.0))+1;
		for(i=2;i<tmp;i++)	
			if(n%i==0){
			res=(res/i)*(i-1);
			while(n%i==0)n/=i;
		}
	
	
		if(n>1)res=(res/n)*(n-1);
		printf("%d\n",res);
	}	
	return 0;
}
