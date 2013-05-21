/*************************************************************************
    > File Name: test.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/6 21:12:38
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
int id(int l,int r) {
    return l+r | l!=r;
}
int main() {
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        printf("%d\n",id(a,b));
    }
    return 0;
}
