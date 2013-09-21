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
	while(cin>>a>>b>>c){
		printf("math=%d,eng=%d,comp=%d,average=%.0f\n",a,b,c,(a+b+c)/3.0);
	}
	return 0;
}
