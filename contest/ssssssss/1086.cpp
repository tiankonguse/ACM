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
	char str[100],*p;
	int sum;
	int num;
	while(cin>>str){
		p=str;
		if(p[0]=='-')p++;
		for(sum=num=0;p[num];num++)sum+=p[num]-'0';
		cout<<"Count="<<num<<",sum="<<sum<<endl;
	}

	return 0;
}
