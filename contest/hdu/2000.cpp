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

char str[10000];


int main() {
	int len;
	while(~scanf("%s",str)){
		len = strlen(str);
		sort(str,str+len);
		len = 0;
		printf("%c",str[0]);
		for(int i=1;str[i];i++){
			printf(" %c",str[i]);
		}
		puts("");
	}

    return 0;
}
