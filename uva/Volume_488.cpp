/*************************************************************************
    > File Name: Volume_488.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 18:28:47
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

char str[11][10]={
    "",
    "1",
    "22",
    "333",
    "4444",
    "55555",
    "666666",
    "7777777",
    "88888888",
    "999999999"};

int main() {
    int cas,n,m,i,j,k;
    scanf("%d",&cas);
    for(i=0;i<cas;i++){
        if(i)puts("");
        scanf("%d%d",&n,&m);
        for(j=0;j<m;j++){
            if(j)puts("");
            for(k=1;k<n;k++){
                puts(str[k]);
            }
            while(k){
                puts(str[k--]);
            }
        }

    }
    return 0;
}
