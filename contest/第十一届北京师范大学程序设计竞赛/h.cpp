/*************************************************************************
    > File Name: h.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 13:08:12
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

        int cas;
        double p;
        scanf("%d",&cas);
        while(cas--){
            scanf("%lf",&p);
            printf("%.2f\n",1/(p*(1-p)));
        }

    return 0;
}
