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
const int N = 201000;
char str[N];
char ans[N];


int main() {
	int i,j,k;
	int len;
	bool pre;
	bool now;
	while(~scanf("%s",str)){
		pre = false;
		now = false;
		ans[0] = str[0];
		for(len = i = 1;str[i];i++){
			if(pre){
				if(now){
					if(ans[len-1] == str[i]){

					}else{
						now = false;
						pre = false;
						ans[len++] = str[i];
					}
				}else{
					if(ans[len -1] == str[i]){
						continue;
					}
					now = true;
					ans[len++] = str[i];

				}
			}else{
				if(ans[len-1] == str[i]){
					pre = true;
				}
				ans[len++] = str[i];
			}
		}
		ans[len] = '\0';
		puts(ans);
	}

    return 0;
}
