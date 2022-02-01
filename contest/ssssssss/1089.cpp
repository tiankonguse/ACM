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
	double h,n,ans;
	while(cin>>h>>n){
		ans=h;
		while(n--){
			ans+=h;
			h/=2;
		}
		ans-=h;
		printf("Distance=%.3f,height=%.3f\n",ans,h);
	}
	return 0;
}
