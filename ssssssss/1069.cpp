#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
void print(int t){
	printf("The train journey time is");
	if(t/60){
		printf(" %d hours",t/60);
	}
	if(t%60){
		printf(" %d minutes",t%60);
	}
	printf(".\n");
}
int main(){
	int t1,t2; 	
	while(cin>>t1>>t2){
		if(t1<=t2){
			print((t2/100)*60+(t2%100) - (t1/100)*60 - (t1%100));
		}else{
			print(24*60+(t1/100)*60+(t1%100) - (t2/100)*60 - (t2%100));
		}
	}

	return 0;
}
