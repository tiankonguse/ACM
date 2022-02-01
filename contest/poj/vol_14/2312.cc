#include"iostream"
#include"queue"
#define MAXN 301
using namespace std;
char map[MAXN][MAXN];
bool mark[MAXN][MAXN];
int M,N;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct tank{
    int x,y,t;
    tank(int x,int y,int t):x(x),y(y),t(t){}
    bool operator <(const tank &a) const
   {
      return t>a.t;
   }
};
priority_queue<tank>q;
bool check(int x,int y){
    if(x<0 || x>=M || y<0 || y>=N)return false;
    else return true;
}
int bfs(int sx,int sy,int dx,int dy){
    if(sx==dx && sy==dy)return 0;
    int tx,ty;
    tank tk(0,0,0);
    while(!q.empty())q.pop();
    memset(mark,false,sizeof(mark));
    mark[sx][sy]=true;
    q.push(tank(sx,sy,0));
    while(!q.empty()){
        tk=q.top();
        q.pop();
        for(int i=0;i<4;i++){
            tx=tk.x+dir[i][0];
            ty=tk.y+dir[i][1];
            if(!mark[tx][ty]){
                mark[tx][ty]=true;
                if(map[tx][ty]=='T')return tk.t+1;
                else if(map[tx][ty]=='E'){
                    q.push(tank(tx,ty,tk.t+1));
                }
                else if(map[tx][ty]=='B'){
                    q.push(tank(tx,ty,tk.t+2));
                }
            }
        }
    }
    return -1;
}
int main(){
    int sx,sy,dx,dy;
    while(scanf("%d%d",&M,&N)&&M){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                scanf(" %c",&map[i][j]);
                if(map[i][j]=='Y'){
                    sx=i;
                    sy=j;
                }
                else if(map[i][j]=='T'){
                    dx=i;
                    dy=j;
                }
            }
        }
        printf("%d\n",bfs(sx,sy,dx,dy));
    }
    return 0;
}
