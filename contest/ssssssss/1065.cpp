#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
//interest=money*(1+rate)^year-money

double qkpower(double a,int k){
	double ans=1;
	double temp=a;
	while(k){
		if(k&1)ans*=temp;
		temp*=temp;
		k>>=1; 
	} 
	return ans; 
} 
int main(){
double money,rate;
int year;
	while(cin>>money>>year>>rate){
		printf("interest=%.2f\n",money*(qkpower(rate+1,year)-1));
	}

	return 0;
}
