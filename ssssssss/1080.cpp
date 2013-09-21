#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
//A£¨90-100£©¡¢B£¨80-89£©¡¢C£¨70-79£©¡¢D£¨60-69£©ºÍE£¨0-59£©¡£

int ok(int a){
	if(a>=90)return 0;
	if(a>=80)return 1;
	if(a>=70)return 2;
	if(a>=60)return 3;
	return 4;
}

int main()
{
	char s[5][100]={
		"The number of A(90~100):",
		"The number of B(80~89):",
		"The number of C(70~79):",
		"The number of D(60~69):",
		"The number of E(0~59):"
		};
	int n,p;
	while(cin>>n){
		int str[6]={0,0,0,0,0};
		while(n--){
			cin>>p;
			str[ok(p)]++;
		}	
		for(int i=0;i<5;i++){
			cout<<s[i]<<str[i]<<endl;
		}	
	}

	return 0;
}
