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

int str[20];
double ans[20];

int main() {
    int i,j,k;
    str[0] = 1;
    ans[0] = 1;

    for(i=1; i<10; i++) {
        str[i] = i*str[i-1];
        ans[i] = ans[i-1] + 1.0/str[i];
    }
    printf("n e\n- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
    for(i=3; i<10; i++) {
        printf("%d %.9f\n",i,ans[i]);
    }
    return 0;
}
