

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
const int N = 5000;
int str_a[N],str_b[N],str_c[N];
int str_null[N],str_full[N];
    //a both null
    //b one null
    //c both full
int main() {
    int n;

    while(~scanf("%d",&n)) {
        for(int i=0; i<n; i++) {
            scanf("%d",&str_a[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d",&str_b[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d",&str_c[i]);
        }

        str_null[0] = str_a[0];
        str_full[0] = str_b[0];
        for(int i=1; i<n; i++) {
            str_null[i] = max(str_null[i-1] + str_b[i], str_full[i-1]+str_a[i]);
            str_full[i] = max(str_null[i-1] + str_c[i], str_full[i-1]+str_b[i]);

        }

        printf("%d\n",str_null[n-1]);
    }
    return 0;
}










