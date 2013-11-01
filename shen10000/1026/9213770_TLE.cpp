#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
char str0[220],str2[220];
int str1[220];
bool map[220];	
int n,m;
while(cin>>n,n)
{
	memset(str0,' ',sizeof(str0));
	str0[n+1]='\0';
	for(int i=0;i<n;i++)
	{
		cin>>str1[i];
		str1[i]--;
	}
	str1[n]=n;
	
	while(cin>>m,m)
	{
		getchar();
		gets(str0);
		int l=strlen(str0);
		for(int i=l;i<n;i++)
		{
			str0[i]=' ';
		}
		str0[n]='\0';
		while(m--)
		{
			for(int i=0;i<=n;i++)
			{
				str2[str1[i]]=str0[i];
			}
			strcpy(str0,str2);
		}
		cout<<str0<<endl;
	}
	
	
}
return 0;
}
