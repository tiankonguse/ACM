#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
int min,max,sum,p,n;
while(cin>>n,n)
{
	cin>>p;
	sum=min=max=p;
	for(int i=1;i<n;i++)
	{
		cin>>p;
		sum+=p;
		if(max<p)max=p;
		if(min>p)min=p;
	}	
	if(sum==0)break;
	max+=min;
	sum-=max;
	
	cout<<sum/(n-2)<<endl;	
}

return 0;
}
