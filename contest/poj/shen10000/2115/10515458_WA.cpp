#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
int extgcd(int a,int b,int &x,int &y){
	if(b==0){x=1,y=0;return a;}
	int d=extgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return d;
}
int modeq(int a,int b,int n){
	if(b==0)return 0;
	if(a==0)return -1;
	if(b<0)b+=n;
	int d,x,y;
	d=extgcd(a,n,x,y);
	if(b%d)return -1;
	int ans=(x*b/d)%n;
	if(ans<0)ans+=n;
	return ans;
	
}

int main()
{
	int a,b,c,k,ans;
	while(cin>>a>>b>>c>>k,k){
		ans=modeq(c,b-a,1<<k);
		if(ans==-1)cout<<"FOREVER"<<endl;
		else cout<<ans<<endl; 
	}
	return 0;
}
