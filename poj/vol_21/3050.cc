#include"iostream"
using namespace std;
int map[5][5],res;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool used[1000000];
void dfs(int x,int y,int d,int num){
     if(d==6){
            
          if(!used[num]){

               used[num]=true;
               res++;
          }
          return;
     }
     int tx,ty;
     for(int i=0;i<4;i++){
         tx=x+dir[i][0];
         ty=y+dir[i][1];
         if(tx>=0 && tx<5 && ty>=0 && ty<5){
             dfs(tx,ty,d+1,num*10+map[tx][ty]);
         }
     }
}
int main(){
    res=0;
        memset(used,false,sizeof(used));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
          dfs(i,j,1,map[i][j]);
       } 
    }
    printf("%d\n",res);
    return 0;
}
