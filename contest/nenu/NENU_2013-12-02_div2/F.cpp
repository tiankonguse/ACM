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
const int N = 10000;
map<int,int>m;
int main() {
	int n,i,j,k,val;
	bool ok;
	while(~scanf("%d",&n)){
		m.clear();
		for(i=0;i<n;i++){
			scanf("%d",&val);
			m[N-val] = 1;
		}
		scanf("%d",&n);
		ok = false;
		while(n--){
			scanf("%d",&val);
			if(m[val] == 1){
				ok = true;
			}else{
				m[val] = 0;
			}
		}
		printf(ok?"YES\n":"NO\n");
	}


    return 0;
}
