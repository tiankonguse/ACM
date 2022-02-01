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
#define MAXN 222
#define MAXL 211
#define inf 0x7f7f7f7f
using namespace std;
int mat[MAXN][MAXN][4];
int M,N;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct node{
    int x,y,t;
    node(int _x,int _y,int _t){
        x=_x, y=_y, t=_t;
    }
    node(){}
}tmp;
queue<node>q;
int mark[MAXN][MAXN];
bool check(int x,int y){
    if(x>=0 && x<MAXL && y>=0 && y<MAXL)return true;
    else return false;
}
int bfs(int dx,int dy){
    int tx,ty;
    while(!q.empty())q.pop();
    for(int i=0;i<MAXL;i++)for(int j=0;j<MAXL;j++)mark[i][j]=inf;
    mark[0][0]=0;
    q.push(node(0,0,0));
    while(!q.empty()){
        tmp=q.front();
        q.pop();
      //  printf("%d,%d:%d\n",tmp.x,tmp.y,tmp.t);system("pause");
        if(tmp.t>mark[tmp.x][tmp.y])continue;
        for(int i=0;i<4;i++){
            tx=tmp.x+dir[i][0];
            ty=tmp.y+dir[i][1];
            if(check(tx,ty)){
              //  printf("mat[%d][%d][%d]=%d\n",tmp.x,tmp.y,i,mat[tmp.x][tmp.y][i]);
                if(mat[tmp.x][tmp.y][i]==0){
                    if(tmp.t < mark[tx][ty]){
                        mark[tx][ty]=tmp.t;
                        q.push(node(tx,ty,tmp.t));
                    }
                }
                else if(mat[tmp.x][tmp.y][i]==1){
                    if(tmp.t+1 < mark[tx][ty]){
                        mark[tx][ty]=tmp.t+1;
                        q.push(node(tx,ty,tmp.t+1));
                    }
                }
            }
        }
    }
    if(mark[dx][dy]==inf)return -1;
    else return mark[dx][dy];
}
int main(){
    int x,y,d,t,tx,ty;
    double nx,ny;
    while(~scanf("%d%d",&M,&N)){
        if(M==-1 && N==-1)break;
        memset(mat,0,sizeof(mat));
        for(int i=0;i<M;i++){
            scanf("%d%d%d%d",&x,&y,&d,&t);
            if(d==1){
                for(int j=0;j<t;j++){
                    mat[x-1][y+j][0] = mat[x][y+j][2] = -1;
                }
            }
            else{
                for(int j=0;j<t;j++){
                    mat[x+j][y-1][1] = mat[x+j][y][3] = -1;
                }
            }
        }
        for(int i=0;i<N;i++){
            scanf("%d%d%d",&x,&y,&d);
            if(d==1){
                mat[x-1][y][0] = mat[x][y][2] = 1;
            }
            else{
                mat[x][y-1][1] = mat[x][y][3] = 1;
            }
        }
      //  scanf("%lf%lf",&nx,&ny);
        cin>>nx>>ny;
        tx=(int)(nx), ty=(int)(ny);
        if(!check(tx,ty))printf("0\n");
        else printf("%d\n",bfs(tx,ty));
    }
    return 0;
}
