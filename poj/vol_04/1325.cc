#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 105
using namespace std;
bool mat[MAXN][MAXN];
bool used[MAXN];
int matx[MAXN],maty[MAXN];
int N,M,K;
int path(int u){
    for(int v=1;v<M;v++){
        if(mat[u][v] && !used[v]){
            used[v]=true;
            if(maty[v]<0 || path(maty[v])){
                matx[u]=v;
                maty[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(){
    int cnt=0;
    memset(matx,0xff,sizeof(matx));
    memset(maty,0xff,sizeof(maty));
    for(int i=1;i<N;i++){
        if(matx[i]<0){
            memset(used,false,sizeof(used));
            cnt+=path(i);
        }
    }
    return cnt;
}
int main(){
    int a,b,c;
    while(scanf("%d",&N) &&N){
        scanf("%d%d",&M,&K);
        memset(mat,false,sizeof(mat));
        for(int i=0;i<K;i++){
            scanf("%d%d%d",&a,&b,&c);
            mat[b][c]=true;
        }
        printf("%d\n",hungary());
    }
    return 0;
}
