#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 23
#define MAXB 15
#define inf 0x7f7f7f7f
using namespace std;
int N;
int dis[MAXB][MAXB];
int coor[MAXB][2];
int ab(int a){
    return a>0?a:-a;
}
int res;
bool used[MAXB];
void dfs(int p,int d,int s){
    if(d==N){
        if(res>s+dis[p][0])res=s+dis[p][0];
        return;
    }
    for(int i=1;i<=N;i++){
        if(!used[i]){
            used[i]=true;
            dfs(i,d+1,s+dis[p][i]);
            used[i]=false;
        }
    }
}
int main(){
    int T,W,H;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&W,&H);
        scanf("%d%d",&coor[0][0],&coor[0][1]);
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d%d",&coor[i][0],&coor[i][1]);
        }
        for(int i=0;i<=N;i++){
            dis[i][i]=0;
            for(int j=i+1;j<=N;j++){
                dis[i][j]=dis[j][i]=ab(coor[i][0]-coor[j][0])+ab(coor[i][1]-coor[j][1]);
            }
        }
        res=inf;
        memset(used,false,sizeof(used));
        used[0]=true;
        dfs(0,0,0);
        printf("The shortest path has length %d\n",res);
    }
    return 0;
}
