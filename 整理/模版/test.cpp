/*************************************************************************
    > File Name: test.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/6/3 9:57:54
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
LL f(int *p, int i, int final){
    if(i == 0){
        return 0;
    }else if(p[i] == final){
        return f(p,i-1,final);
    }else{
        return f(p,i-1,6-p[i]-final) + (1LL<<(i-1));
    }
}

LL getAns(int *start, int *finish,int n){
    LL ans = 0;
    int k = n;
    while(k>=1 && start[k] == finish[k])k--;
    if(k>=1){
        int tmp = 6 - start[k] - finish[k];
        ans = f(start, k-1,tmp) + f(finish,k-1,tmp) + 1;
    }
    return ans;
}

int main() {

    return 0;
}
