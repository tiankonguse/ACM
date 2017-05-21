#include"iostream"
using namespace std;
bool map[101][101];
bool used[101][101];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int N,M;
bool check(int x,int y){
   if(x>=0 && x<N && y>=0 && y<M)return true;
   else return false;
}
int mx,cnt;
void dfs(int x,int y){
    int tx,ty;
    cnt++;
    used[x][y]=true;
    for(int i=0;i<4;i++){
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(check(tx,ty) && !used[tx][ty] && map[tx][ty]){
             dfs(tx,ty);
        }
    }
}
int main(){
    int K,r,c;
    scanf("%d%d%d",&N,&M,&K);
    while(K--){
        scanf("%d%d",&r,&c);
        map[r-1][c-1]=true;
    }
    mx=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
          if(map[i][j] && !used[i][j]){
              cnt=0;
              dfs(i,j);
              if(cnt>mx)mx=cnt;
          }
        }
    }
    printf("%d\n",mx);
  //  system("pause");
    return 0;
}
