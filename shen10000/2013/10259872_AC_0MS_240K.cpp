#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;
vector<string>vec;

string s;
int main()
{
	int n,j=1;
	while(scanf("%d",&n),n){
		vec.clear();
		for(int i=0;i<n;i++){
			cin>>s;
			vec.push_back(s);

		}
		
		cout<<"SET "<<j++<<endl;
		for(int i=0;i<n;i+=2)
			cout<<vec[i]<<endl;
		for(int i=n&1?n-2:n-1;i>0;i-=2)
			cout<<vec[i]<<endl;
	}

return 0;
}
