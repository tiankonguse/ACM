/*************************************************************************
    > File Name: qsort_double.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/8 18:38:22
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


int double_cmp(const void *a, const void *b){
    return *((const double*)a) > *((const double*)b) ? 1 : -1;
}

int main() {
    double num[100];
    int n;
    qsort(num,n,sizeof(num[0]),double_cmp);
    return 0;
}

