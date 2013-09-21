/*************************************************************************
    > File Name: Volume_10000_103_10300.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/14 20:44:53
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
    LL sum,squ,degree;
    int n;

    scanf("%d",&n);
    while(~scanf("%d",&n)){
        sum=0;
        while(n--){
            scanf("%lld%*lld%lld",&squ,&degree);
            sum += squ * degree;
        }
        printf("%lld\n",sum);
    }


    return 0;
}
