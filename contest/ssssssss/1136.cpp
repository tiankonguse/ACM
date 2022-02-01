#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int str[101];
int str0[101];
int main()
{
	int n,t,tmp,max;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>str[i];
		memset(str0,0,sizeof(str0));
		max=str0[0]=1;
		for(int i=1;i<n;i++){
			tmp=1;
			for(int j=i-1;j>=0;j--){
				if(str[i]<str[j] && tmp<=str0[j])tmp=str0[j]+1;
			}
			str0[i]=tmp;
			if(max<tmp)max=tmp;
		}
		cout<<max<<endl;
	}
	
	return 0;
}
