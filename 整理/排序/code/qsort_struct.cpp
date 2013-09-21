/*************************************************************************
    > File Name: qsort_struct.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/8 18:38:31
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

struct Node{
    int val;
};

int struct_cmp(const void *a, const void *b){
    return ((const Node*)a)->val - ((const Node*)b)->val;
}

int main() {
    Node num[100];
    int n;
    qsort(num,n,sizeof(num[0]),struct_cmp);
    return 0;
}
