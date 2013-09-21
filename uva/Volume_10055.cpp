/*************************************************************************
    > File Name: Volume_10000_100_10055.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/14 20:15:42
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL a,b;
    while(~scanf("%lld%lld",&a,&b)){
        if(a<b)printf("%lld\n",b-a);
        else printf("%lld\n",a-b);
    }
    return 0;
}
