#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int sum,n;
	while(cin>>n){
		sum=0;
		if(n<=0){
			cout<<sum<<endl;
			continue;
		}
		if(n&1)sum+=n;
		while(cin>>n){
			if(n<=0)break;
			if(n&1)sum+=n;
		}
		cout<<sum<<endl;
	}
	return 0;
}
