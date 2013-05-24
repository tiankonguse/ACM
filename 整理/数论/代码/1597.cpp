#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
typedef __int64  INT ;
INT gcd(INT a,INT b){
    if (a==0) return 1;
    if (a<0) return gcd(-a,b);
    while (b){
        INT t=a%b; a=b; b=t;
    }
    return a;
}

int main()
{
	INT a,b;
	while(cin>>a>>b){
		printf("%10I64d%10I64d",a,b);
		if(gcd(a,b)==1){
			printf("    Good Choice\n\n");
		}else{
			printf("    Bad Choice\n\n");
		}
	}
	
	return 0;
}
