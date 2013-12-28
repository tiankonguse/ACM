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

vector<int>edge[111];
int d[111];
bool have[111];


int main() {

	int n,i,val,j,k;
	while(~scanf("%d",&n)){
		memset(d,0,sizeof(d));
		memset(have,1,sizeof(have));
		for(i=1;i<=n;i++){
			while(scanf("%d",&val),val){
				d[val]++;
				edge[i].push_back(val);
			}
		}

		for(i=0;i<n;i++){
			for(j=1;j<=n;j++){
				if(d[j] == 0 && have[j]){
					break;
				}
			}
			have[j] = 0;
			for(k=0;k<edge[j].size();k++){
				d[edge[j][k]]--;
			}
			printf(i?" %d":"%d",j);
		}
		puts("");

	}

    return 0;
}
