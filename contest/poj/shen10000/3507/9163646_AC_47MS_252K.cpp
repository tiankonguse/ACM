#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
int min,max,sum,p;
while(1)
{
	cin>>p;
	sum=min=max=p;
	for(int i=1;i<6;i++)
	{
		cin>>p;
		sum+=p;
		if(max<p)max=p;
		if(min>p)min=p;
	}	
	if(sum==0)break;
	double d=sum-min-max;
	cout<<d/4<<endl;	
}
getchar();getchar();
return 0;
}
