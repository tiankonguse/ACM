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
	double f;
	while(cin>>f){
		if(f<0.00001 && f>-0.00001)printf("f(0.00)=0.00\n");
		else printf("f(%.2f)=%.2f\n",f,1/f);
	}
	return 0;
}
