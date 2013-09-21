#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
typedef __int64 INT;
INT str[1000];

INT fun(int n){
	if(str[n])return str[n];
	return str[n]=fun(n-1)+fun(n-2);
}

int main()
{
	memset(str,0,sizeof(str));
	str[1]=str[0]=1;
	int n;
	while(cin>>n){
		cout<<fun(n)<<endl;
	}
	return 0;
}
