#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
struct T
{
int x,y,z;	
}str[17],p;

double fun(const T & q)
{
	double x=(q.x-p.x)*10;
	double y=(q.y-p.y)*10;
	double z=(q.z-p.z)*10;

	return sqrt(x*x+y*y+z*z); 
}

int main()
{
for(int i=0;i<16;i++)
	cin>>str[i].x>>str[i].y>>str[i].z;
	int a,b,c,k;
	double min,max;
while(cin>>p.x>>p.y>>p.z,p.x+1)
{
	max=fun(str[0]);	
	k=0;
	for(int i=1;i<16;i++)
	{
		min=fun(str[i]);	
		if(max>min){max=min;k=i;}
	}
	printf("(%d,%d,%d) maps to (%d,%d,%d)\n",p.x,p.y,p.z,str[k].x,str[k].y,str[k].z);
		
}
return 0;
}
