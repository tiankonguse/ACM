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

char table[10];

int main() {
	char c;
	int str[10];
	int k,i,j;
	while(~scanf("%d",&k)){
		memset(str,0,sizeof(str));
		k = k*2;
		bool ok = true;
		for(i=0;i<4;i++){
			scanf("%s",table);
			for(j=0;j<4;j++){
				if(table[j] != '.'){
					if(++str[table[j]-'0'] > k)ok = false;;

				}
			}
		}
		printf("%s\n",ok?"YES":"NO");
	}

    return 0;
}
