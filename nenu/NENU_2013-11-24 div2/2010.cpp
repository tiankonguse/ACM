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

int cube(int val){
	return val*val*val;
}

bool is(int val){
	return val == cube(val%10) + cube(val/100) + cube((val/10)%10);
}

int main() {
	int L,R;
	bool have;

	while(~scanf("%d%d",&L,&R)){
		have = false;
		for(;L<=R;L++){
			if(is(L)){
				printf(have?" %d":"%d",L);
				have = true;
			}
		}
		printf(have?"\n":"no\n");
	}

    return 0;
}
