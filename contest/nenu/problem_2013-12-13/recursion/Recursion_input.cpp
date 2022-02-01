#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<ctime>
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
    freopen("Recursion.in","w",stdout);
    srand(time(NULL));
    int n=200;
    int _max = 1000000;
    while(n--){
    	printf("%d\n",rand()%_max + 1);
    }

    return 0;
}
