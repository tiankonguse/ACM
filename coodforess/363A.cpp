#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;

char str[12][100] = {
	"O-|-OOOO",
	"O-|O-OOO",
	"O-|OO-OO",
	"O-|OOO-O",
	"O-|OOOO-",
	"-O|-OOOO",
	"-O|O-OOO",
	"-O|OO-OO",
	"-O|OOO-O",
	"-O|OOOO-"
};



int main() {
	int n;
	while(~scanf("%d",&n)){
		if(n < 10){
			puts(str[n]);
		}else{
			while(n){
				puts(str[n%10]);
				n/=10;
			}
		}
	}


    return 0;
}
