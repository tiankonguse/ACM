#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	int a,str[4],ans,t;
	while(cin>>a){
		str[2]=a%10;a/=10;
		str[3]=a%10;a/=10;
		str[0]=a%10;a/=10;
		str[1]=a%10;a/=10;
		ans=0;
		t=1;
		for(int i=0;i<4;i++){
			ans+=t*((str[i]+9)%10);
			t*=10;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
