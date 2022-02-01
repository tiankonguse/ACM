#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 1005
using namespace std;
char map[MAXN][MAXN];
int N,M;
struct node{
    int x,y,t;
    node(){}
    node(int xt,int yt,int tt){
        x=xt;y=yt;t=tt;
    }
}q[1000005],t;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool used[MAXN][MAXN];
int bfs(int sx,int sy){
    int l=0,h=1,tx,ty;
    memset(used,false,sizeof(used));
    used[sx][sy]=true;
    q[0]=node(sx,sy,0);
    while(l<h){
        t=q[l++];
        for(int i=0;i<4;i++){
            tx=t.x+dir[i][0];
            ty=t.y+dir[i][1];
            if(!used[tx][ty] && map[tx][ty]=='.'){
                used[tx][ty]=true;
                q[h++]=node(tx,ty,t.t+1);
            }
        }
    }
    l=0,h=1;
    memset(used,false,sizeof(used));
    t.t=0;
    used[t.x][t.y]=true;
    q[0]=t;
    while(l<h){
        t=q[l++];
        for(int i=0;i<4;i++){
            tx=t.x+dir[i][0];
            ty=t.y+dir[i][1];
            if(!used[tx][ty] && map[tx][ty]=='.'){
                used[tx][ty]=true;
                q[h++]=node(tx,ty,t.t+1);
            }
        }
    }
    return t.t;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&M,&N);
        for(int i=0;i<N;i++)scanf(" %s",map[i]);
        bool flag=false;
        int res=0;
        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                if(map[i][j]=='.'){
                    res=bfs(i,j);
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        printf("Maximum rope length is %d.\n",res);
    }
    return 0;
}
