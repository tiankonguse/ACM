#include"iostream"
#define MAXN 101
using namespace std;
char map[MAXN][MAXN];
bool used[MAXN][MAXN],flag;
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
int N,M,tx,ty,sx,sy;
bool check(int x,int y){
     if(x<0 || x>=N || y<0 || y>=M)return false;
     else return true;
}
bool judge(int x,int y){
     if(check(x-1,y) && check(x+1,y) && map[x-1][y]=='#' && map[x+1][y]=='#')return true;
     if(check(x,y-1) && check(x,y+1) && map[x][y-1]=='#' && map[x][y+1]=='#')return true;
     return false;
}
bool dfs(int x,int y){
     used[x][y]=true;
     for(int i=0;i<4;i++){
         tx=x+dir[i][0];
         ty=y+dir[i][1];
         if(check(tx,ty) && !used[tx][ty] && map[tx][ty]=='.'){
              if(judge(tx,ty)){
                   sx=tx;
                   sy=ty;
                   return true;
              }
              if(dfs(tx,ty))return true;
         }
     }
     return false;
}
int dire(int x,int y){
     for(int i=0;i<4;i++){
          tx=x+dir[i][0];
          ty=y+dir[i][1];
          if(map[tx][ty]=='.' && !used[tx][ty]){
             return i;//w,n,r,s 
          }
     }
}
bool yon(int x,int y){
    if(map[x-1][y]=='.' && map[x-1][y-1]=='.' && map[x][y-1]=='.')return true;
    if(map[x-1][y]=='.' && map[x-1][y+1]=='.' && map[x][y+1]=='.')return true;
    if(map[x+1][y]=='.' && map[x+1][y-1]=='.' && map[x][y-1]=='.')return true;
    if(map[x+1][y]=='.' && map[x+1][y+1]=='.' && map[x][y+1]=='.')return true;
    return false;
}
int go(int x,int y,int d){
     if(map[x+dir[(d+3)%4][0]][y+dir[(d+3)%4][1]]=='.')return (d+3)%4;
     if(map[x+dir[d][0]][y+dir[d][1]]=='.')return d;
     if(map[x+dir[(d+1)%4][0]][y+dir[(d+1)%4][1]]=='.')return (d+1)%4;
     if(map[x+dir[(d+2)%4][0]][y+dir[(d+2)%4][1]]=='.')return (d+2)%4;
}
bool solve(){
     int d=dire(sx,sy);
     int x=sx+dir[d][0];
     int y=sy+dir[d][1];
     while(1){
          if(x==sx && y==sy)return false;
          if(yon(x,y))return true;
          d=go(x,y,d);
          x=x+dir[d][0];
          y=y+dir[d][1];
        /*  map[x][y]='x';
           for(int i=0;i<N;i++)printf("%s\n",map[i]);
           map[x][y]='.';
           system("pause");*/
     }
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)scanf("%s",map[i]);
    if(dfs(0,0)){
         if(solve())printf("YES\n");
         else printf("NO\n");
    }
    else printf("NO\n");
 //   system("pause");
    return 0;
}
