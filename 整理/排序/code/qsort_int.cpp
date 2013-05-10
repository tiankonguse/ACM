/*************************************************************************
    > File Name: qsort_int.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/8 18:38:01
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


int int_cmp(const void *a, const void *b){
    return *((const int*)a) - *((const int*)b);
}

int main() {
    int num[100];
    int n;
    qsort(num,n,sizeof(num[0]),int_cmp);
    return 0;
}
