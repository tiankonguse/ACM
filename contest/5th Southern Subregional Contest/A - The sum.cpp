/*************************************************************************
    > File Name: A - The sum.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/5 19:09:54
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

LL str[50];
LL ans[50];

void get(){
    int i;
    str[1]=str[2]=1;
    ans[1] = 1;
    ans[2] = 2;
    for(i=3;i<41;i++){
        str[i] = str[i-1] + str[i-2];
        ans[i] = ans[i-1] + str[i];
//        printf("%d  %lld  %lld\n",i,str[i],ans[i]);
    }

}

int main() {
    get();

    int k;
    while(~scanf("%d",&k)){
        printf("%lld\n",ans[k]);
    }

    return 0;
}
