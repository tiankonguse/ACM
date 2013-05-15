/*************************************************************************
    > File Name: G - Gibonacci number.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/10 19:01:16
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
LL f[40];

int main() {
    int i,j,cas;
    LL g_i,t;
    f[0] = 0;
    f[1] = 1;
    for(i=2; i<=22; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    scanf("%d",&cas);
    while(cas--) {
        scanf("%d%lld%d",&i,&g_i,&j);

        t = g_i - f[i-1];

//        printf("t=%lld\n",t);
        if(t % f[i] == 0) {
            t = t / f[i];
            if(t >=1) {
                printf("%lld\n",f[j-1] + f[j]*t);
            } else {
                printf("-1\n");
            }
        } else {
            printf("-1\n");
        }



    }




    return 0;
}
