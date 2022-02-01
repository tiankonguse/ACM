#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
void fun(int a,int b,char c){
	switch(c){
		case '+':	printf("%d + %d = %d\n",a,b,a+b);
		break;
		case '-':printf("%d - %d = %d\n",a,b,a-b);
		break;
		case '*':printf("%d * %d = %d\n",a,b,a*b);
		break;
		case '/':printf("%d / %d = %d\n",a,b,a/b);
		break;
		case '%':printf("%d %% %d = %d\n",a,b,a%b);
	}
	
}
int main(){
	int a,b;
	char c;
	while(cin>>a>>b>>c){
		fun(a,b,c);
	}

	return 0;
}
/*
5 + 3 = 8
5 - 3 = 2
5 * 3 = 15
5 / 3 = 1
5 % 3 = 2
*/
