/*************************************************************************
    > File Name: E.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 11:01:05
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
int const N = 1100000;
int const M = 300000;

bool is[N];
int prm[M];

int getprm(){
    int e = (int)(sqrt(0.0 + N) + 1), k = 0, i, s, j;

    memset(is,1,sizeof(is));


    is[0] = is[1] = 0;

    prm[k++] = 2;

    for(i = 4; i < N; i += 2){
        is[i] = 0;
    }

    for(i = 3; i < e; i += 2){
        if(is[i]){
            prm[k++] = i;
            for(s = i + i, j = i * i; j < N; j += s){
                is[j] = 0;
            }
        }
    }


    for(;i < N; i += 2){
        if(is[i]){
            prm[k++] = i;
        }
    }

    return k;

}

int main() {

    int k = getprm();
    int n, i;
    while(scanf("%d",&n), n){
        for(i = 1; ;++i){
            if(is[n - prm[i]])break;
        }
        printf("%d = %d + %d\n",n,prm[i],n - prm[i]);
    }

    return 0;
}
