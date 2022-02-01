#include"iostream"
using namespace std;
char map[11][11],tou[11][11];
int res[11][11];
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,-1},{1,1}};
int main(){
    int N,d,tx,ty;
    bool flag;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf(" %s",map[i]);
    }
    for(int i=0;i<N;i++){
        scanf(" %s",tou[i]);
    }
    memset(res,0xff,sizeof(res));
    flag=false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]=='*')res[i][j]=-2;
            if(tou[i][j]=='x'){
               if(map[i][j]=='*'){
                    flag=true;
               }
               else{
                    d=0;
                    for(int k=0;k<8;k++){
                       tx=i+dir[k][0];
                       ty=j+dir[k][1];
                       if(tx>=0 && tx<N && ty>=0 && ty<N && map[tx][ty]=='*'){
                           d++;
                       }
                    }
                    res[i][j]=d;    
               }
            }
        }
    }
     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(res[i][j]==-1)printf(".");
            else if(res[i][j]==-2){
                if(flag) printf("*");
                else printf(".");
            }
            else printf("%d",res[i][j]);
        }
        printf("\n");
     }
    
  //  system("pause");
    return 0;
}
