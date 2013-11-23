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
using namespace std;
typedef long long LL;


LL myfun(LL x,LL y){
    return (x+y-1)/y;
}

int main()
{
    LL a,b,c;
    while(~scanf("%10lld%10lld%10lld",&a,&b,&c)){
        a=myfun(a,c);
        b=myfun(b,c);
        printf("%10lld\n",a*b);
    }

    return 0;
}
