#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
//当x<0时，f(x)=(x+1)^2+2x+1/x 
//当x>=0时，f(x)=x的平方根 
double ok(double x){
	if(x<0)return x*x+x*4+1+1/x;
	else return sqrt(x);
	
}
int main(){
	double f;
	while(cin>>f){
		printf("f(%.2f)=%.2f\n",f,ok(f));
	}
	return 0;
}
