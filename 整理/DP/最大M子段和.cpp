/*************************************************************************
    > File Name: 最大M子段和.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/1 13:24:53
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

const int N = 1000100,INF = 0x3fffffff;;


int g[N];
int max_m_sum(int* str,int n,int m){
    memset(g,0,sizeof(g));
    int i,j,_max,tmp;

    for(i=1;i<=m;i++){
        _max = g[i-1];
        for(j=i;j<=n;j++){
            tmp = _max;
            _max = max(_max,g[j]);
            g[j] = max(g[j-1],tmp) + str[j];
        }
    }
    _max = g[m];
    for(i=m;i<=n;i++){
        _max = max(_max,g[i]);
    }
    return _max;
}


int main() {
int str[N];
    int n,m,i;

    while(~scanf("%d%d",&m,&n)){
        for(i=1;i<=n;i++){
            scanf("%d",&str[i]);
        }
        printf("%d\n",max_m_sum(str,n,m));

    }
    return 0;
}
