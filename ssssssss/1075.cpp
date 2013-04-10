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
		for(int i=1,j=1;i<=n;i++,j+=2){
			sum+=1.0/j;
		}
		printf("%.6f\n",sum);
	}

	return 0;
}
