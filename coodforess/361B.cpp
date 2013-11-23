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
const int N = 101000;
int str[N];
int main() {
    int i,n,k;
    while(~scanf("%d%d",&n,&k)) {
        for(i=1; i<=n; i++) {
            str[i] = i;
        }
        if(k >= n) {
            printf("-1\n");
        } else {
            for(i=n - k; i>1; i -= 2) {
                swap(str[i],str[i-1]);
            }
            for(i=1; i<=n; i++) {
                printf("%d ",str[i]);
            }
            puts("");
        }
    }

    return 0;
}

