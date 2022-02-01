#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;

__int64 extgcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
	if(b==0){x=1,y=0;return a;}
	__int64 d=extgcd(b,a%b,x,y);
	__int64 t=x;x=y;y=t-a/b*y;
	return d;
}
__int64 modeq(__int64 a,__int64 b,__int64 n){

	__int64 d,x,y;
	d=extgcd(a,n,x,y);
	if(b%d)return -1;
	__int64 ans=(x*b/d)%n;
//	__int64 min=n,ans;
//	for(int i=0;i<d;i++){
//		ans=(tmp+i*(n/d))%n;
//		if(ans>=0 && ans<min)min=ans;
//	}
	//while(ans<0)ans+=n;
	ans=(ans%(n/d)+n/d)%(n/d);
	return ans;
	
}

int main()
{
	__int64 a,b,c,k,ans;
	while(cin>>a>>b>>c>>k,k){
		if(a==b){
			cout<<0<<endl;continue;
		}
		if(c==0){
			cout<<"FOREVER"<<endl;
			continue;
		}
		ans=modeq(c,b-a,(__int64)1<<k);
		if(ans==-1)cout<<"FOREVER"<<endl;
		else cout<<ans<<endl; 
	}
	return 0;
}
