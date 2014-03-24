/*************************************************************************
> File Name: 1000.cpp
> Author: tiankonguse
> Mail: i@tiankonguse.com 
> Created Time: Mon 24 Mar 2014 08:11:41 AM CST
************************************************************************/

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
    
    int t,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",i,a+b);
    }

    return 0;
}
