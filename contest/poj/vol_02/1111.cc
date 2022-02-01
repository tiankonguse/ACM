#include"iostream"
#include"cstdlib"
using namespace std;
char board[20][20];
bool mark[20][20];
int dir[8][2]={{-1,0},{1,0},{0,1},{0,-1},
               {-1,-1},{-1,1},{1,-1},{1,1}};
int N,M,s_x,s_y,P;
inline bool check(int x,int y){
       if(x>=0 && x<N && y>=0 && y<M)
       return true;
       else return false;
}
void dfs(int x,int y){
     int tx,ty;
     for(int i=0;i<4;i++){
          tx=x+dir[i][0];
          ty=y+dir[i][1];
          if(check(tx,ty)){
              if(board[tx][ty]=='X' && mark[tx][ty]==false){
                  mark[tx][ty]=true;
                  dfs(tx,ty);
              }
              else if(board[tx][ty]=='.')P++;
          }
          else{
              P++;
          }
     }
     for(int i=4;i<8;i++){
         tx=x+dir[i][0];
         ty=y+dir[i][1];
         if(check(tx,ty)){
              if(board[tx][ty]=='X' && mark[tx][ty]==false){
                  mark[tx][ty]=true;
                  dfs(tx,ty);
              }
         }
     }
}
int main(){
    while(scanf("%d%d%d%d",&N,&M,&s_x,&s_y) && N){
         for(int i=0;i<N;i++){
                 for(int j=0;j<M;j++){
                    scanf(" %c",&board[i][j]);
                 }
         }
         memset(mark,false,sizeof(mark));
         P=0;
         mark[s_x-1][s_y-1]=true;
         dfs(s_x-1,s_y-1);
         printf("%d\n",P);
    }
    return 0;
}
