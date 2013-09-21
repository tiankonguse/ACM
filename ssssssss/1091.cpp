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
	int n=9;
	double e=1;
	double tmp=1;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	cout<<"0 1"<<endl;
	for(int i=1;i<=9;i++){
		tmp/=i;
		e+=tmp;
		printf("%d %.8g\n",i,e);
	}
	
	return 0;
}
