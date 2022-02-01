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

int main()
{
int n;
int sum,v,t,lt;
while(cin>>n,n+1){
	cin>>v>>t;
	sum=v*t;
	lt=t;
	for(int i=1;i<n;i++){
		cin>>v>>t;
		sum+=(t-lt)*v;
		lt=t;
	}
	cout<<sum<<" miles"<<endl;
}
return 0;
}
