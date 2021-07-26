/*************************************************************************
    > File Name: C Serial Numbers003.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 22:48:25
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 110000
using namespace std;

int str[maxn];
int mod[maxn];
int m;
int dfs(int let,int use,int now){
    int tmp;
    if(let==0){
        return use;
    }
    for(int i=now;i>0;i--){
        if(str[i]){
            str[i]--;
            if(tmp=dfs((let-i+m)%m,use+1,i))return tmp;
            str[i]++;
        }
    }
    return -1;
}
int main(){
    int cas,n,i,j,k,tmp,sm;
    scanf("%d",&cas);
    while(cas--){

        scanf("%d%d",&n,&m);
        memset(str,0,sizeof(str));
        sm=0;

        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            str[tmp%m]++;
            sm+=tmp%m;
        }


        sm%=m;

        tmp=dfs(sm,0,m-1);
        if(tmp==-1){
            printf("0\n");
        }else{
            printf("%d\n",n-tmp);
        }
    }
    return 0;
}
