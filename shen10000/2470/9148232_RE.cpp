#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
int str[10002];
int n,i;
while(scanf("%d",&n),n)
{
	for(i=1;i<=n;i++)
		cin>>str[i];	
	bool p=true;
	for(i=1;i<=n&&p;i++)
		if(str[str[i]]!=i)
			p=false;	
	if(p)cout<<"ambiguous"<<endl;
	else cout<<"not ambiguous"<<endl;
}

return 0;
}
