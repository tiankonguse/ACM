#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 10
using namespace std;
char map[MAXN][MAXN];
bool ux[MAXN],uy[MAXN];
int N,K,cnt;
void dfs(int x,int y,int d){
    if(d==K)cnt++;
    for(int i=x;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==x && j==0)j=y;
            if(map[i][j]=='#' && !ux[i] && !uy[j]){
                ux[i]=uy[j]=true;
                dfs(i,j,d+1);
                ux[i]=uy[j]=false;
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&N,&K)){
        if(N==-1 && K==-1)break;
        for(int i=0;i<N;i++){
            scanf(" %s",map[i]);
        }
        memset(ux,false,sizeof(ux));
        memset(uy,false,sizeof(uy));
        cnt=0;
        dfs(0,0,0);
        printf("%d\n",cnt);
    }
    return 0;
}
