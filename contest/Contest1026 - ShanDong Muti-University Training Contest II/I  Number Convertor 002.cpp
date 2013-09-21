/*************************************************************************
    > File Name:  Number Convertor.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 16:41:30
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
const int inf = 0x0f3f;
const int N = 100001;
int f[N],v[N];
const int _MAX = 1061109567;
int b;

int get(int op,int a,int b){

    if(op == 0){
        return a+b;
    }
    if(op == 1){
        return a-b;
    }
    if(op == 2){
        return a*b;
    }
    if(op == 3){
        return a/b;
    }
}

void CompletePack(int op,int cost, int val){
    int tmp,tmpCost;
    for(int i=0;i<N;i++){
        if(f[i] >= _MAX){
            continue;
        }

        tmp = get(op,i,val);
        if(tmp < 0 || tmp >= N){
            continue;
        }

        tmpCost = f[i] + cost;
        if(f[tmp] > tmpCost){
            f[tmp] = tmpCost;
        }
    }
}

int main() {

    int val[20];
    int cas,a,n,i,j,cost;
    scanf("%d",&cas);
    while(cas--){
        memset(f,inf,sizeof(f));
        scanf("%d%d%d",&a,&b,&n);
        for(i=0;i<n;i++){
            scanf("%d",&val[i]);
        }

        f[a] = 0;
        for(i=0;i<n;i++){
            for(j=0;j<4;j++){
                scanf("%d",&cost);
                CompletePack(j,cost,val[i]);
            }
        }
        if(f[b] == _MAX){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n",f[b]);
        }
    }

    return 0;
}
