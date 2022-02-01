#include"iostream"
#include"cstdlib"
using namespace std;
int W,H,sum;
char map[21][21];
bool used[21][21];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool check(int x,int y){
     if(x>=0 && x<H && y>=0 && y<W && map[x][y]!='#')return true;
     else return false;
}
void dfs(int x,int y){
     sum++;
     used[x][y]=true;
     for(int i=0;i<4;i++){
         if(check(x+dir[i][0],y+dir[i][1]) && !used[x+dir[i][0]][y+dir[i][1]]){
              dfs(x+dir[i][0],y+dir[i][1]);
         }
     }
}
int main(){
    int sx,sy;
    while(scanf("%d%d",&W,&H)&&W&&H){
       memset(used,false,sizeof(used));
       for(int i=0;i<H;i++){
               for(int j=0;j<W;j++){
                   scanf(" %c",&map[i][j]);   
                   if(map[i][j]=='@'){
                        sx=i;
                        sy=j;
                   }       
               }
       }
       sum=0;
       dfs(sx,sy);
       printf("%d\n",sum);
    }
    return 0;
}
