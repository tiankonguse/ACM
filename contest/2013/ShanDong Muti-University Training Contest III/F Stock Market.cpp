/*************************************************************************
    > File Name: F Stock Market.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 18:28:36
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
    LL sum,ans,tmp;
    int n,pi,cas,l,r,i,tmp_l;
    scanf("%d",&cas);

    while(cas--){
        scanf("%d",&n);

        scanf("%d",&pi);
        tmp = sum = pi;
        l = r = tmp_l = 1;
        for(i = 2; i<=n; i++){
            scanf("%d",&pi);
            if(tmp >= 0){
                tmp += pi;
            }else{
                tmp = pi;
                tmp_l = i;
            }

            if(tmp > sum){
                sum = tmp;;
                l = tmp_l;
                r = i;
            }

        }
        printf("%d %d\n",l,r);



    }



    return 0;
}
