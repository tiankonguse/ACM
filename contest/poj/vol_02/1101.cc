#include"iostream"
#include"cstdlib"
#include"queue"
using namespace std;
struct node{
  int x,y,t;
  node(int i,int j,int k):x(i),y(j),t(k){}
};
queue<node>q;
int N,M;
bool map[80][80],mat[80][80];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y){
   if(x>=0 && x<=N+1 && y>=0 && y<=M+1 && !mat[x][y])return true;
   else return false;
}
int bfs(int sx,int sy,int dx,int dy){
    int tx,ty,tt;
    if(sx==dx && sy==dy)return 0;
    while(!q.empty())q.pop();
    q.push(node(sx,sy,0));
    node t(0,0,0);
    while(!q.empty()){
       t=q.front();
       q.pop();
       tx=t.x;
       ty=t.y;
       tt=t.t;
       for(int i=0;i<4;i++){
           for(int j=1;;j++){
              if(tx+j*dir[i][0]==dx && ty+j*dir[i][1]==dy)return tt+1;     
              if(check(tx+j*dir[i][0],ty+j*dir[i][1])){
                  mat[tx+j*dir[i][0]][ty+j*dir[i][1]]=true;
                  q.push(node(tx+j*dir[i][0],ty+j*dir[i][1],tt+1));
              }
              else break;
           }
       }
    }
    return -1;
}
int main(){
  //  freopen("game.in","r",stdin);
  //  freopen("exp.txt","w",stdout);
    char c[100];
    int sx,sy,dx,dy,ans,cnt,cn=1;
    while(scanf("%d%d",&M,&N)){
        if(M==0 && N==0)break;
        memset(map,false,sizeof(map));
        getchar();
        for(int i=1;i<=N;i++){
           gets(c);
           for(int j=0;j<M;j++){
              if(c[j]=='X')map[i][j+1]=true;
           }
        }
       /* for(int i=0;i<=N+1;i++){
          for(int j=0;j<=M+1;j++){
            printf("%d",map[i][j]);
          }
          printf("\n");
        }*/
        cnt=1;
        printf("Board #%d:\n",cn++);
        while(scanf("%d%d%d%d",&sy,&sx,&dy,&dx)){
           memcpy(mat,map,sizeof(map));
           if(sx==0 && sy==0 && dx==0 && dy==0)break;
           ans=bfs(sx,sy,dx,dy);
           if(ans==-1){
              printf("Pair %d: impossible.\n",cnt++);
           }
           else printf("Pair %d: %d segments.\n",cnt++,ans);
        }
        printf("\n");
    }    
    return 0;
}
