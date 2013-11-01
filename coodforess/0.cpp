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


int main() {
	
	
for(int a;~scanf("%d",&a);){
	while(a--){
		a += 10;
		int b = a%10;
		a /= 10;
		a *= 10;
		a += b;
		a -= 10;
		for(int i=0;i<a;i++){
			int b = 32;
			b *= b;
			b /= b;
		}
	}
	printf("%d\n",a);
}

    return 0;
}

