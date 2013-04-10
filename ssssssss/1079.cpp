#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
	char str[10000];
	while(gets(str)){
		int l=0,d=0,b=0,o=0;
		for(int i=0;str[i];i++){
			if(str[i]>='a' && str[i]<='z')l++;
			else if(str[i]>='A' && str[i]<='Z')l++;
			else if(str[i]>='0' && str[i]<='9')d++;
			else if(str[i]==32)b++;
			else o++;
		}
		cout<<"Letter="<<l<<",blank="<<b<<",digit="<<d<<",other="<<o<<endl;
	}
	return 0;
}
