#include"iostream"
using namespace std;
int map[25][25];
bool check(int x,int y){
    if(x<=15){
        if(map[x][y]==map[x+1][y] && map[x][y]==map[x+2][y] &&
           map[x][y]==map[x+3][y] && map[x][y]==map[x+4][y] &&
           map[x][y]!=map[x-1][y] && map[x][y]!=map[x+5][y])return true;
        if(y<=15){
           if(map[x][y]==map[x+1][y+1] && map[x][y]==map[x+2][y+2] &&
              map[x][y]==map[x+3][y+3] && map[x][y]==map[x+4][y+4] &&
              map[x][y]!=map[x-1][y-1] && map[x][y]!=map[x+5][y+5])return true;
        }
    }
    if(y<=15){
        if(map[x][y]==map[x][y+1] && map[x][y]==map[x][y+2] &&
           map[x][y]==map[x][y+3] && map[x][y]==map[x][y+4] &&
           map[x][y]!=map[x][y-1] && map[x][y]!=map[x][y+5])return true;
        if(x>=5){
           if(map[x][y]==map[x-1][y+1] && map[x][y]==map[x-2][y+2] &&
              map[x][y]==map[x-3][y+3] && map[x][y]==map[x-4][y+4] &&
              map[x][y]!=map[x+1][y-1] && map[x][y]!=map[x-5][y+5])return true;
        }
    }
    return false;
}
int main(){
    int T;
    bool flag;
    for(int i=0;i<=20;i++){
       map[i][0]=-1;
       map[i][20]=-1;
       map[0][i]=-1;
       map[20][i]=-1;
    }
    scanf("%d",&T);
    while(T--){
       for(int i=1;i<=19;i++){
           for(int j=1;j<=19;j++){
               scanf("%d",&map[i][j]);
           }
       }
     /*  for(int i=0;i<=20;i++){
          for(int j=0;j<=20;j++){
             printf("%2d ",map[i][j]);
          }
          printf("\n");
       }*/
       flag=false;
       for(int i=1;i<=19;i++){
           for(int j=1;j<=19;j++){
               if(map[i][j] && check(i,j)){
                   printf("%d\n",map[i][j]);
                   printf("%d %d\n",i,j);
                   flag=true;
                   break;
               }
           }
           if(flag)break;
       }
       if(!flag)printf("0\n");
    }
 //   system("pause");
    return 0;
}
