/*************************************************************************
    > File Name: qsort_char.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/8 18:38:14
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

int char_cmp(const void *a, const void *b){
    return *((const char*)a) - *((const char*)b);
}

int main() {
    char num[100];
    int n;
    qsort(num,n,sizeof(num[0]),char_cmp);
    return 0;
}
