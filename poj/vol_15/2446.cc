#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define MAXN 1050
using namespace std;
vector<int> mat[MAXN];
int matx[MAXN],maty[MAXN];
bool fy[MAXN];
int N,M;
int path(int u){
    int size=mat[u].size();
    for(int i=0;i<size;i++){
        int v=mat[u][i];
        if(!fy[v]){
            fy[v]=true;
            if(maty[v]==-1 || path(maty[v])){
                matx[u]=v;
                maty[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary(){
   int res=0;
   memset(matx,0xff,sizeof(matx));
   memset(maty,0xff,sizeof(maty));
   for(int i=1;i<=N;i++){
       if(matx[i]<0){
           memset(fy,false,sizeof(fy));
           res+=path(i);
       }
   }
   return res;
}
bool board[35][35];
int r,c,k,x,y,tx,ty;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
bool check(int x,int y){
    if(x>=1 && x<=r && y>=1 && y<=c && !board[x][y])return true;
    else return false;
}
int main(){
    while(~scanf("%d%d%d",&r,&c,&k)){
        memset(board,false,sizeof(board));
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            board[y][x]=true;
        }
        int s=r*c;
        int t=s-k;
        if(t%2==1){puts("NO");continue;}
        t/=2;
        N=M=s;
        for(int i=1;i<=s;i++)mat[i].clear();
        for(int i=1;i<=s;i++){
            x=(i-1)/c+1;
            y=i%c; if(y==0) y=c;
            if(board[x][y] || (x+y)%2==1)continue;
            for(int j=0;j<4;j++){
                tx=x+dir[j][0];
                ty=y+dir[j][1];
             //   printf("%d %d -> %d %d : check=%d\n",x,y,tx,ty,check(tx,ty));
                if(check(tx,ty))mat[i].push_back((tx-1)*c+ty);
            }
        }
      /*  for(int i=1;i<=s;i++){
            for(int j=1;j<=s;j++){
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }*/
        puts(hungary()==t?"YES":"NO");
    }
    return 0;
}
