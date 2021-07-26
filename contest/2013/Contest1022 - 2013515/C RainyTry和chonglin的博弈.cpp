/*************************************************************************
    > File Name: C RainyTry和chonglin的博弈.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 18:03:43
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

int main() {
    int sum,n,tmp,i;

    while(~scanf("%d",&n)){
        sum = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&tmp);
            sum += tmp/i;
        }
        printf("%s\n",sum&1?"YES":"NO");
    }

    return 0;
}
