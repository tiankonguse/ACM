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
	int n,i,ans;
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		ans = 0;
		for(i=0;str[i];i++){
			if(str[i]>='0' && str[i] <='9'){
				ans++;
			}
		}
		printf("%d\n",ans);
	}


    return 0;
}
