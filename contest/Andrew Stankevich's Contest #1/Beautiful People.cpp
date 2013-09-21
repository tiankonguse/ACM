/*************************************************************************
    > File Name: Beautiful People.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 20:22:12
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
const int N=100100;
struct T{
    int num;
    int s,b;
}str[N],c[N];

bool cmp(const T &a, const T&b){

    if(a.s < b.s)return true;
    if(a.s > b.s)return false;

    if(a.b < b.b)return true;
    if(a.b > b.b)return false;

    return false;
}

int next[N];

int binary_search(int len,int i){
    int left = 1,right = len,mid;
    while(left <= right){
        mid = (left + right)>>1;
        if(str[i].b > c[mid].b && str[i].s > c[mid].s)left = mid+1;
        else if(str[i].b < c[mid].b && str[i].s < c[mid].s)right = mid -1;
        else return mid;
    }
    return left;
}

int LIS(int n){
    int len = 1;
    c[0].b = c[0].s = -1;
    c[1] = str[0];
    next[0] = -1;
    for(int i=1;i<n;++i){
        int j = binary_search(len,i);
        if(j != 0){

        }
        c[j] = str[i];
        if(j>len)len=j;
    }
    return len;
}

int main() {
    int cas;
    int n;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d%d",&str[i].s,&str[i].b);
            str[i].num = i+1;
        }
        sort(str,str+n,cmp);
//        for(int i=0;i<n;i++){
//            printf("%d %d\n",str[i].s,str[i].b);
//        }


        printf("%d\n",LIS(n));

        if(cas)puts("");
    }
    return 0;
}
