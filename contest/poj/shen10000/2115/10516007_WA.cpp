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
//模线性方程
//a*x=b(%n) 
//对于 a*x=b(%n)，则存在整数y,使a*x - n*y = b.
//如果有解，则有d个解，设最小正数解为x0,则解为x0+d*i,i=0,1,2,…d-1.
//返回最小正数解 
__int64 modeq(__int64 a,__int64 b,__int64 n){

	__int64 d,x,y;
	d=extgcd(a,n,x,y);
	if(b%d)return -1;
	return (b/d*x + n)%(n/d);
	
}

int main()
{
	__int64 a,b,c,k,ans;
	while(cin>>a>>b>>c>>k,k){
		ans=modeq(c,b-a,1LL<<k);
		if(ans==-1)cout<<"FOREVER"<<endl;
		else cout<<ans<<endl; 
	}
	return 0;
}
