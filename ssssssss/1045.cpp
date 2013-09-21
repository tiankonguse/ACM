#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
const int N=100010;
int str[N];
int main(){
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++)scanf("%d",&str[i]);
		sort(str,str+n,greater<int>());
		printf("%d",str[0]);
		for(int i=1;i<n;i++)printf(" %d",str[i]);
		printf("\n");
	}
	return 0;
}
