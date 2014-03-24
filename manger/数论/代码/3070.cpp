#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
const int N=15000;
int str[N+1];
int main()
{
	
	str[0]=0;
	str[1]=1;
	for(int i=2;i<15001;i++){
		str[i]=(str[i-1]+str[i-2])%10000;
	}
	__int64 n;
	int p;
	while(cin>>n,n+1){
		p=n%N;
		cout<<str[p]<<endl;
		
	}
	return 0;
}
