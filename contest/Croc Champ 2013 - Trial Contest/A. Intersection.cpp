/*************************************************************************
    > File Name: A. Intersection.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 17:49:51
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
    long long a1,b1,c1,a2,b2,c2;
    while(~scanf("%lld%lld%lld",&a1,&b1,&c1)){
        scanf("%lld%lld%lld",&a2,&b2,&c2);
        if(a1*b2 != a2*b1){
            puts("1");
        }else{
            if(a1*b2 == a2*b1 && a1*c2 == a2*c1){
                puts("-1");
            }else{
                puts("0");
            }
        }
    }
    return 0;
}
