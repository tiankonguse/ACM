#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int n,str[52],sum,m,k=0;
while(scanf("%d",&n),n)
{
	k++;
	sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		sum+=str[i];
	}	
	m=sum/n;
	sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=abs(m-str[i]);	
	}
	cout<<"Set #"<<k<<endl;
	cout<<"The minimum number of moves is "<<sum/2<<"."<<endl;

}

getchar();getchar();
return 0;
}
