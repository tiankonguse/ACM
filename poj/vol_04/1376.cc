#include"iostream"
#include"cstdlib"
#include"queue"
using namespace std;
struct node{
   int x,y,d,t;
   node(int i,int j,int k,int l):x(i),y(j),d(k),t(l){}
};
int N,M;
bool map[55][55];
bool state[55][55][4];//n,e,s,w
int dire[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
queue<node>q;
int bfs(int sx,int sy,int dx,int dy,int dir){
    int tx,ty,td;
    if(sx==dx && sy==dy)return 0;
    while(!q.empty())q.pop();
    state[sx][sy][dir]=true;
    node t(0,0,0,0);
    q.push(node(sx,sy,dir,0));
    while(!q.empty()){
        t=q.front();
        q.pop();
        tx=t.x;
        ty=t.y;
        td=t.d;
      //  printf("%d %d %d %d\n",t.x,t.y,t.d,t.t);
     //   system("pause");
        if(tx==dx && ty==dy)return t.t;
        if(!state[tx][ty][(td+1)%4]){
            state[tx][ty][(td+1)%4]=true;
            q.push(node(tx,ty,(td+1)%4,t.t+1));
        }
        if(!state[tx][ty][(td+3)%4]){
            state[tx][ty][(td+3)%4]=true;
            q.push(node(tx,ty,(td+3)%4,t.t+1));
        }
        for(int i=1;i<=3;i++){
           if(!map[tx+dire[td][0]*i][ty+dire[td][1]*i]){
              if(!state[tx+dire[td][0]*i][ty+dire[td][1]*i][td]){
               state[tx+dire[td][0]*i][ty+dire[td][1]*i][td]=true;
               q.push(node(tx+dire[td][0]*i,ty+dire[td][1]*i,td,t.t+1));
              }
           }
           else break;
        }
    }
    return -1;
}
int main(){
   // freopen("robot.txt","r",stdin);
   // freopen("rt.txt","w",stdout);
    int a,sx,sy,dx,dy,dir,ans;
    char str[10];
    while(scanf("%d%d",&N,&M)&&N){
       memset(map,false,sizeof(map));
       memset(state,false,sizeof(state));
       for(int i=0;i<=N;i++){
          map[i][0]=true;
          map[i][M]=true;
       }
       for(int j=0;j<=M;j++){
          map[0][j]=true;
          map[N][j]=true;
       }
       for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
              scanf("%d",&a);
              if(a){
                 map[i][j]=map[i+1][j]=map[i][j+1]=map[i+1][j+1]=true;
              }
          }
       }
     /*  for(int i=0;i<=N;i++){
          for(int j=0;j<=M;j++){
              printf("%d ",map[i][j]);
          }
          printf("\n");
       }*/
       scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
       scanf("%s",str);
       if(str[0]=='n')dir=0;
       else if(str[0]=='w')dir=1;
       else if(str[0]=='s')dir=2;
       else dir=3;
       ans=bfs(sx,sy,dx,dy,dir);
       printf("%d\n",ans);
    }
    return 0;
}
