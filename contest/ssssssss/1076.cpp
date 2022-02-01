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
	int n;
	while(cin>>n){
		double sum=0;
		for(int i=1,j=1;i<=n;i++,j+=3){
			if(i&1)sum+=1.0/j;
			else sum-=1.0/j;
		}
		printf("%.5f\n",sum);
	}

	return 0;
}
