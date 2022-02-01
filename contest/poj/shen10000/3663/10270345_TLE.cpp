#include<string>
#include<iostream>
using namespace std;
int str[20010];
int main()
{
int n,l;
while(~scanf("%d%d",&n,&l)){
	for(int i=0;i<n;){
		scanf("%d",&str[i]);
		if(str[i]>=l)n--;
		else i++;
	}
	int sum=0;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++){
		if(str[i]+str[j]<=l)sum++;
	}
	printf("%d\n",sum);
}
return 0;
}
