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
	__int64 ans,base;
	int a,n;
	while(cin>>a>>n){
		ans=0;
		base=1;
		for(int i=n;i;i--){
			ans+=base*a*i;
			base*=10;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
