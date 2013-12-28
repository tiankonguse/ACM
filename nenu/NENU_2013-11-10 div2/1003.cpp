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

const int N = 1000010;

int str[N];

int getStep(int val) {
    int ans = 1;
    while(val != 1) {
        if(val%2 == 0) {
            val /= 2;
        } else {
            val = val*3+1;
        }
        ans++;
    }
    return ans;
}


int main() {
    memset(str,-1,sizeof(str));
    str[1] = str[0] = 1;
    int a,b,i;
    int ans,tmp;

    while(~scanf("%d%d",&a,&b)) {
        printf("%d %d ",a,b);
        if(a>b) {
            a^=b,b^=a,a^=b;
        }
        ans = 1;
        for(i=a; i<=b; i++) {
            if(str[i] == -1) {
                str[i] = getStep(i);
            }
            if(ans < str[i]){
				ans = str[i];
            }

        }
        printf("%d\n",ans);

    }

    return 0;
}
