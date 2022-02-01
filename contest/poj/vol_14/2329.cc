#include"iostream"
#include"cstdio"
#include"string.h"
#include"queue"
#define MAXN 201
using namespace std;
struct node{
    int x,y,t;     
}q[MAXN*MAXN],tmp;
int N;
int map[MAXN][MAXN],mod[MAXN][MAXN];
bool used[MAXN][MAXN];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y){
    if(x<0 || x>=N || y<0 || y>=N)return false;
    else return true;
}
int bfs(int sx,int sy){
    int tx,ty,t,d,l=0,h=1;
    q[0].x=sx;
    q[0].y=sy;
    q[0].t=0;
    bool flag=false;
    memset(used,false,sizeof(used));
    used[sx][sy]=true;
    while(l<h){
        tmp=q[l++];
        if(flag && tmp.t==t)return d;
        for(int i=0;i<4;i++){
             tx=tmp.x+dir[i][0];
             ty=tmp.y+dir[i][1];
             if(check(tx,ty) && !used[tx][ty]){
                used[tx][ty]=true;
                if(map[tx][ty]){
                    if(flag)return 0;
                    d=map[tx][ty];
                    t=tmp.t+1;
                    flag=true;
                }
                q[h].x=tx;
                q[h].y=ty;
                q[h++].t=tmp.t+1;
             }
        }
    }
    return 0;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
             scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
             if(!map[i][j]){
                  mod[i][j]=bfs(i,j);
             }
             else mod[i][j]=map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
             if(j==N-1)printf("%d\n",mod[i][j]);
             else printf("%d ",mod[i][j]);
        }
    }
    return 0;
}
