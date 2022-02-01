#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAXN 1010
#define inf 0x7f7f7f7f
using namespace std;
int N;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int doors[MAXN][MAXN][2];
int mark[MAXN][MAXN][4];
struct node{
    int x,y,t,c;
    node(int q,int w,int e,int r){
        x=q,y=w,t=e,c=r;
    }
    node(){}
}path[MAXN][MAXN][4],t,tmp;
bool check(int x,int y){
    if(x>=1 && x<=N && y>=1 && y<=N)return true;
    return false;
}
queue<node>q;
int bfs(){
    int tx,ty,tt,x,y;
    while(!q.empty())q.pop();
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)for(int k=0;k<4;k++)mark[i][j][k]=inf;
    for(int i=0;i<4;i++)mark[1][1][i]=0;
    q.push(node(1,1,0,-1));
    while(!q.empty()){
        t=q.front();
        q.pop();
        x=t.x;
        y=t.y;
        tt=t.t+1;
        //cout<<x<<","<<y<<endl;//","<<t.c<<endl;
        if(x==N && y==N)return t.c;
        for(int i=0;i<4;i++){
            tx=x+dir[i][0];
            ty=y+dir[i][1];
            if(!check(tx,ty))continue;
            if(i==0 && t.c!=0){
                if(doors[x][y][1]==3 && tt<mark[tx][ty][3]){
                    mark[tx][ty][3]=tt;
                    path[tx][ty][3]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,3));
                }
                else if(doors[x][y][1]==1 && tt<mark[tx][ty][2]){
                    mark[tx][ty][2]=tt;
                    path[tx][ty][2]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,2));
                }
            }
            else if(i==1 && t.c!=1){
                if(doors[tx][ty][1]==4 && tt<mark[tx][ty][3]){
                    mark[tx][ty][3]=tt;
                    path[tx][ty][3]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,3));
                }
                else if(doors[tx][ty][1]==2 && tt<mark[tx][ty][2]){
                    mark[tx][ty][2]=tt;
                    path[tx][ty][2]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,2));
                }
            }
            else if(i==2 && t.c!=2){
                if(doors[x][y][0]==1 && tt<mark[tx][ty][1]){
                    mark[tx][ty][1]=tt;
                    path[tx][ty][1]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,1));
                }
                else if(doors[x][y][0]==3 && tt<mark[tx][ty][0]){
                    mark[tx][ty][0]=tt;
                    path[tx][ty][0]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,0));
                }
            }
            else if(i==3 && t.c!=3){
                if(doors[tx][ty][0]==2 && tt<mark[tx][ty][1]){
                    mark[tx][ty][1]=tt;
                    path[tx][ty][1]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,1));
                }
                else if(doors[tx][ty][0]==4 && tt<mark[tx][ty][0]){
                    mark[tx][ty][0]=tt;
                    path[tx][ty][0]=node(x,y,t.t,t.c);
                    q.push(node(tx,ty,tt,0));
                }
            }
        }
    }
    return -1;
}
int res[MAXN][2];
int main(){
    while(~scanf("%d",&N)){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                scanf("%d %d",&doors[i][j][0],&doors[i][j][1]);
            }
        }
        int ans=bfs();
        if(ans!=-1){
            int cnt=1,px=N,py=N;
            res[0][0]=N,res[0][1]=N;
            while(1){
                tmp=path[px][py][ans];
                px=tmp.x;
                py=tmp.y;
                ans=tmp.c;
                res[cnt][0]=px;
                res[cnt][1]=py;
                cnt++;
                if(px==1 && py==1)break;
            }
            for(int i=cnt-1;i>=0;i--){
                printf("%d %d\n",res[i][1],res[i][0]);
            }
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
