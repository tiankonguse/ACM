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
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

char str[100000];

int main() {
	int a,i;

	while(~scanf("%s",str)){
		if(strlen(str) == 1 && str[0] == '0'){
			break;
		}
		a = 0;
		for(i=0;str[i];i++){
			a += str[i] - '0';
		}

		while(a>9){
			a = a/10 + a%10;
		}
		printf("%d\n",a);
	}

    return 0;
}
