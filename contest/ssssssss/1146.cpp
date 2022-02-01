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
	int str[50];
	str[0]=0;
	str[1]=1;
	for(int i=2;i<22;i++)str[i]=str[i-2]+str[i-1];
	int a;
	cin>>a;
	while(cin>>a)cout<<str[a]<<endl;
	return 0;
}
