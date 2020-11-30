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

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;

int main() {

    int n;
    int pre;
    int ans ;
    int now;
    int tmp;

    scanf("%d",&n);


    now = 0;
    pre = 123456;
    ans = 0;

    while(n--) {
        scanf("%d", &tmp);
        if(tmp >= pre) {
            now = now + 1;
        } else {
            now = 1;
        }

        if(now > ans) {
            ans = now;
        }

        pre = tmp;
    }

    printf("%d\n",ans);


    return 0;
}
