#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	char str[1000];
	int sum=0,tmp;
	while(cin>>str,str[0]-'0'){
		sum=0;
		for(int i=0;str[i];i++)sum+=str[i]-'0';
		while(sum>9){
			tmp=sum%10;
			sum/=10;
			sum+=tmp;
		}
		cout<<sum<<endl;
	}
	return 0;
}
