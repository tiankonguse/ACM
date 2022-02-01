#include"iostream"
#include"queue"
#define MAXN 230
#define MAP_SIZE 80
using namespace std;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//N,W,S,E
bool path[MAXN][MAXN][4];
bool maze[MAXN][MAXN];
char map[MAP_SIZE][MAP_SIZE];
int N,M,L;
int sx,sy;
int dfs(int x,int y,int t){
    int tx,ty,d;
    maze[x][y]=false;
    for(int i=0;i<4;i++){
        if(path[x][y][i]){
            tx=x+dir[i][0];
            ty=y+dir[i][1];
            if(t>1 && tx==sx && ty==sy)return t+1;
            if(maze[tx][ty]){
                d=dfs(tx,ty,t+1);
                if(d!=-1)return d;
            }
        }
    }
    return -1;
}
int main(){
    int x1,x2,x3,x4,y1,y2,y3,y4,cas=1;
    while(scanf("%d%d",&M,&N)&&N){
        L=N+M;
        memset(path,false,sizeof(path));
        memset(maze,false,sizeof(maze));
        for(int i=0;i<N;i++){
            scanf(" %s",map[i]);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                x1=x2=i+j;
                x3=x4=i+j+1;
                y1=y3=N-i+j-1;
                y2=y4=N-i+j;
                maze[x1][y1]=maze[x2][y2]=maze[x3][y3]=maze[x4][y4]=true;
                if(map[i][j]=='\\'){
                    path[x1][y1][2]=path[x2][y2][2]=true;
                    path[x3][y1][0]=path[x4][y4][0]=true;
                }
                else{
                    path[x1][y1][3]=path[x3][y3][3]=true;
                    path[x2][y2][1]=path[x4][y4][1]=true;
                }
            }
        }
        int d,lmax=0,cnt=0;
        for(int i=0;i<L;i++){
            for(int j=0;j<L;j++){
                if(maze[i][j]){
                    sx=i;
                    sy=j;
                    d=dfs(i,j,0);
                    if(d!=-1){
                        cnt++;
                        if(d>lmax)lmax=d;
                    }
                }
            }
        }
        printf("Maze #%d:\n",cas++);
        if(cnt){
            printf("%d Cycles; the longest has length %d.\n",cnt,lmax);
        }
        else{
            printf("There are no cycles.\n");
        }
        printf("\n");
    }
    return 0;
}
