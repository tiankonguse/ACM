#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
__int64 str[101];
__int64 str0[101][101];
__int64 str1[101][101][101];

__int64 min(__int64 a,__int64 b)
{
if(a>b)return b;
return a;	
}

__int64 fun(int k1,int k2)
{
if(str0[k1][k2]!=-1)return str0[k1][k2];
if(k1==k2){return str0[k1][k2]=0;}	
if(k1+1==k2)
{
	if(str1[k1][k2][k2+1]==-1)str1[k1][k2][k2+1]=str[k1]*str[k2]*str[k2+1];
	return str0[k1][k2]=str1[k1][k2][k2+1];
}

__int64 _min=0;

for(int i=k1;i<k2;i++)
{
	if(i==k1)
	{
		if(str1[k1][k1+1][k2+1]==-1)str1[k1][k1+1][k2+1]=str[k1]*str[k1+1]*str[k2+1];
		if(str0[i+1][k2]==-1)fun(i+1,k2);
		_min=str0[i+1][k2]+str1[k1][k1+1][k2+1];
		continue;
	}
	if(str1[k1][i+1][k2+1]==-1)str1[k1][i+1][k2+1]=str[k1]*str[i+1]*str[k2+1];
	
	if(str0[k1][i]==-1)fun(k1,i);
	if(str0[i+1][k2]==-1)fun(i+1,k2);
	_min=min(_min,str0[k1][i]+str0[i+1][k2]+str1[k1][i+1][k2+1]);	
}
return str0[k1][k2]=_min;
}

int main(int argc, char *argv[])
{
int n;

scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%I64d",&str[i]);
memset(str0,-1,sizeof(str0));
memset(str1,-1,sizeof(str1));
printf("%I64d\n",fun(0,n-2));
getchar();getchar();
return 0;

}

