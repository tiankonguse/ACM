#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
typedef __int64 INT;
INT n;
INT fun(INT i){
	return (n+i-1)/i;
}

int main()
{
	INT d,sum,now,next,val;
	while(cin>>n>>d,n){
		sum=0;
		now=1;
		val=n;

		if(n<=d){
			while(now<n){
				val=fun(now);
				next=fun(val-1);
				sum+=(next-now)*val;
				now=next;
			}
			sum+=(d-n+1);
		}else{
			while(now<=d){
				val=fun(now);
				next=fun(val-1);
				sum+=(next-now)*val;
				now=next;
			}
//			cout<<"now="<<now<<endl;
//			cout<<"sum="<<sum<<endl;
//			cout<<"val="<<val<<endl;
			sum-=(now-d-1)*val;
		}
		cout<<sum<<endl;
	}
	return 0;
}
