#include"iostream"
#include"cstdio"
#include"string"
#include"string.h"
#include"queue"
#define MAXN 21
using namespace std;
int N,M,L;
struct node{
    int s,x,y,t;
    node(int s,int x,int y,int t):s(s),x(x),y(y),t(t){}
};
queue<node>q;
bool maze[MAXN][MAXN];
bool hash[MAXN][MAXN][60000];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int axis[10][2];

int cal(int x1,int y1,int x2,int y2){
    if(x1-x2==-1)return 0;
    else if(x1-x2==1)return 1;
    else if(y1-y2==-1)return 2;
    else return 3;
}
bool check(int x,int y){
    if(x<0 || x>=N || y<0 || y>=M || maze[x][y])return false;
    return true;
}
bool solve(node t){
    int sx,sy,tx,ty,x,y;
    sx=t.x;
    sy=t.y;
    int s,ts=t.s;
    axis[0][0]=sx;
    axis[0][1]=sy;
    for(int i=1;i<L;i++){
        axis[i][0]=axis[i-1][0]+dir[ts%4][0];
        axis[i][1]=axis[i-1][1]+dir[ts%4][1];
        ts/=4;    
    }
    bool flag;
    for(int i=0;i<4;i++){
        tx=sx+dir[i][0];
        ty=sy+dir[i][1];
        flag=true;
        if(check(tx,ty)){
            for(int j=1;j<L;j++){
                if(tx==axis[j][0] && ty==axis[j][1]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                if(tx==0 && ty==0)return true;
                s=cal(tx,ty,sx,sy);
                int d=4;
                for(int j=1;j<L-1;j++){
                    s+=d*cal(axis[j-1][0],axis[j-1][1],axis[j][0],axis[j][1]);
                    d*=4;
                }
                if(!hash[tx][ty][s]){
                    hash[tx][ty][s]=true;
                    q.push(node(s,tx,ty,t.t+1));
                }
            }
        }
    }
    return false;
}
int bfs(int sx,int sy,int s){
    if(sx==0 && sy==0)return 0;
    while(!q.empty())q.pop();
    memset(hash,false,sizeof(hash));
    node tmp(s,sx,sy,0);
    hash[sx][sy][s]=true;
    q.push(tmp);
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        if(solve(tmp)){
            return tmp.t+1;
        }
    }
    return -1;
}

int main(){
    int x,y,k,sx,sy,tx,ty,cnt=1,s,d;
    while(scanf("%d%d%d",&N,&M,&L)){
        if(N==0 && M==0 && L==0)break;
        memset(maze,false,sizeof(maze));
        d=1;
        s=0;
        for(int i=0;i<L;i++){
            scanf("%d%d",&x,&y);
            x--;y--;
            if(i==0){
                sx=x;
                sy=y;
                tx=x;
                ty=y;
            }
            else{
                s+=d*cal(tx,ty,x,y);
                tx=x;
                ty=y;
                d*=4;
            }
        }
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&x,&y);
            x--;y--;
            maze[x][y]=true;
        }
        printf("Case %d: %d\n",cnt++,bfs(sx,sy,s));
    }
    return 0;
}
