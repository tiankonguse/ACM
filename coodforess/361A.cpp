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
	int i,j,n,k;
	while(~scanf("%d%d",&n,&k)){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d ",i==j?k:0);
			}
			printf("\n");
		}
	}

    return 0;
}

