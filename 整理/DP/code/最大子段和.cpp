/*************************************************************************
    > File Name: 最大子段和.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/17 8:46:56
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

int MSS(int*a,int n) {
    int tmp ,sum;
    tmp = sum = a[1];
    for(i = 2; i<=n; i++) {
        if(tmp >= 0) {
            tmp += a[i];
        } else {
            tmp = a[i];
        }

        if(tmp > sum) {
            sum = tmp;
        }
    }
    return sum;
}

int main() {

    return 0;
}
