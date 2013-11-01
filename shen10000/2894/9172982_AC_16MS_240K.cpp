#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
char c;
int n,m,a,b,max,min;
cin>>n;
while(n--)
{
	int str[1005]={0};
	max=0;
	min=1001;	
	cin>>m;
	while(m--)	
	{
		cin>>c>>a>>b;
		if(max<b)max=b;
		if(a<min)min=a;
		for(;a<b;a++)
			str[a]++;
	}
	for(;min<max;min++)
		if(str[min])
			printf("%c",str[min]+'A'-1);
	cout<<endl;
}	
	
return 0;	
}
