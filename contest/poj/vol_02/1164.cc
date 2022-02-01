#include"iostream"
using namespace std;
char map[102][102];
bool used[102][102];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int maxc,cnt;
void dfs(int x,int y){
    int tx,ty;
    if(map[x][y]=='.')cnt++;
    used[x][y]=true;
    for(int i=0;i<4;i++){
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(!used[tx][ty] && map[tx][ty]!='#'){
            dfs(tx,ty);
        }
    }
}
int main(){
    int N,M,a;
    scanf("%d%d",&N,&M);
    for(int i=1;i<N*2;i+=2){
        for(int j=1;j<M*2;j+=2){
             scanf("%d",&a);
             map[i][j]='.';
             if(a&1){
                map[i-1][j-1]=map[i][j-1]=map[i+1][j-1]='#';
             }
             if(a>>1&1){
                map[i-1][j-1]=map[i-1][j]=map[i-1][j+1]='#';
             }
             if(a>>2&1){
                map[i-1][j+1]=map[i][j+1]=map[i+1][j+1]='#';
             }
             if(a>>3&1){
                map[i+1][j-1]=map[i+1][j]=map[i+1][j+1]='#';
             }
        }
    }
    maxc=0;
    int cnt2=0;
    for(int i=1;i<2*N;i++){
        for(int j=1;j<2*M;j++){
            if(map[i][j]!='#' && !used[i][j]){
                 cnt=0;
                 dfs(i,j);  
                 if(cnt>maxc)maxc=cnt;
                 cnt2++;  
            }
        }
    }
    printf("%d\n%d\n",cnt2,maxc);
    
  /*  for(int i=0;i<=N*2;i++){
       for(int j=0;j<=M*2;j++){
          printf("%c",map[i][j]);
       }
       printf("\n");
    }*/
   // system("pause");
    return 0;
}
