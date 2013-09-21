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
	int a,b,c;
	while(cin>>a){
		cin>>b;
		a--;
		while(a--){
			cin>>c;
			if(c<b)b=c;
		}
		cout<<b<<endl;
	}

	return 0;
}
