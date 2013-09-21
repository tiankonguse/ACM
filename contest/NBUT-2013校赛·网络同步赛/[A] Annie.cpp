/*************************************************************************
    > File Name: [A] Annie.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/18 13:50:27
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

int main() {
    int n,num,tt;
    double s,t;
    while(~scanf("%d%lf",&n,&s)){
        num = 0;
        while(n--){
            scanf("%lf",&t);
            tt = t * 1000;
            if(tt%10000 <= 5000)num++;
        }
        printf("%.1f\n",(60+0.2*s)*num);
    }

    return 0;
}
