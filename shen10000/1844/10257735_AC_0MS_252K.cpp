#include<iostream>
using namespace std;
int main()
{
	int sum=0,s,i=0;
	cin>>s;
	while(sum<s||(sum-s)%2==1)
		sum+=++i;
	cout<<i;
	return 1;
}