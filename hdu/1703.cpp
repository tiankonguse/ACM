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
int main() {
	int n;
	while(scanf("%d", &n), n){
        int ans = 0;
        if(n == 1){
            ans = 0;
        }else if(n <= 3){
            ans = 5 * (n * 2 - 3);
        }else{
            ans = 5 * (n * 2 - 4);
        }
        printf("%d\n", ans);


	}


    return 0;
}
