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
const int N = 1000;
int ans[266]= {1,5,6,3,6,3,7,4,7,8,4,5,4,5,4,1,6,3,7,4,7,4,9,7,8,8,7,5,7,5,7,4,7,8,4,5,8,8,7,5,8,9,5,6,8,8,5,5,4,5,4,1,7,5,7,4,8,8,5,5,5,7,6,4,7,8,8,8,4,5,7,5,8,9,8,8,5,6,5,5,4,5,7,5,4,1,7,4,8,8,5,7,5,5,6,4,8,9,8,8,8,8,5,7,11,9,8,9,8,9,8,8,5,6,5,5,5,5,6,4,8,9,8,8,8,8,8,7,8,9,9,9,9,9,10,9,5,7,6,6,6,6,7,6,9,9,10,9,10,9,10,10,7,6,7,7,7,7,9,7,5,7,6,6,7,6,7,7,5,6,2,3,6,6,4,3,6,6,7,6,7,7,9,7,6,6,4,3,7,7,7,6,5,7,7,6,6,6,7,7,5,6,6,6,2,3,4,3,6,6,7,7,7,6,9,7,6,6,7,7,4,3,7,6,5,6,6,6,6,6,7,7,8,9,5,6,5,6,2,5,2,3,4,3,4,3,7,6,5,6,2,5,2,5,4,1};

int toUchar(const char*  str) {
    int ans = 0;
    while(*str) {
        ans = (ans<<1) | (*str++ -'0');
    }
    return ans;
}
int main() {
    char input[10];
    scanf("%s",input);
    while(~scanf("%s",input)) {
        printf("%d\n",ans[toUchar(input)]);
    }
    return 0;
}
