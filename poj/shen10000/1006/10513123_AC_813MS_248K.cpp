#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
int main()
{
	int x0,y0,z0,n0,i,t=1;
	while(cin>>x0>>y0>>z0>>n0,x0+1){
		for(i=n0+1;;i++){
			if((i-x0)%23)continue;
			if((i-y0)%28)continue;
			if((i-z0)%33)continue;	
			break;
		}
		cout<<"Case "<<t++<<": the next triple peak occurs in "<<i-n0<<" days."<<endl;
	}
	return 0;
}
