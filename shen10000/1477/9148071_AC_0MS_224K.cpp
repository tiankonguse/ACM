#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int n,str[520],sum,m,k=0;
while(cin>>n,n)
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
	sum/=2;
	cout<<"Set #"<<k<<endl;
	cout<<"The minimum number of moves is "<<sum<<"."<<endl<<endl;

}

getchar();getchar();
return 0;
}
