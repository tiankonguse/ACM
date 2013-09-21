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
		for(int i=1;i<=n;i++){
			sum+=1.0/i;
		}
		printf("%.4f\n",sum);
	}

	return 0;
}
