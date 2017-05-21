#include"iostream"
#include"queue"
using namespace std;
int T,M,N,tim;
int s_x,s_y,e_x,e_y,dire;
char maze[40][40];
bool mark[40][40];
int dir[4][2]={-1,0,0,-1,1,0,0,1};
struct node{
    int x,y,t;
    node(int x,int y,int t):x(x),y(y),t(t){}
};
bool check(int x,int y){
     if(x>=0 && x<N && y>=0 && y<M && maze[x][y]!='#')
     return true;
     else return false;
}
void find(int x,int y,int d){
   int dirn=dire,dn;
   while(1){
       if(x==e_x && y==e_y)return;
       dn=d;
       while(1){
          if(check(x+dir[(dirn+dn)%4][0],y+dir[(dirn+dn)%4][1])){
              x+=dir[(dirn+dn)%4][0],y+=dir[(dirn+dn)%4][1];
              dirn=(dirn+dn)%4;
              tim++;
              break;
          }
          if(d==1) dn=(dn+3)%4;
          else dn++;
       }
   }
}
void bfs(int x,int y){
    queue<node> q;
    node cur(x,y,1);
    q.push(cur);
    while(!q.empty()){
       cur=q.front();
       q.pop();
       for(int i=0;i<4;i++){
           if(check(cur.x+dir[i][0],cur.y+dir[i][1])){
              if(maze[cur.x+dir[i][0]][cur.y+dir[i][1]]=='E'){
                  tim=cur.t+1;
                  return;
              }
              maze[cur.x+dir[i][0]][cur.y+dir[i][1]]='#';
              q.push(node(cur.x+dir[i][0],cur.y+dir[i][1],cur.t+1));
           }
       }
    }
}
int main(){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&M,&N);
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                scanf(" %c",&maze[j][k]);
                if(maze[j][k]=='S'){
                   s_x=j,s_y=k;
                }
                else if(maze[j][k]=='E'){
                   e_x=j,e_y=k;
                }
            }
        }
        for(int i=0;i<4;i++){
                if(maze[s_x+dir[i][0]][s_y+dir[i][1]]=='.'){
                    dire=i;
                    break;
                }
        }
        tim=1;
        find(s_x,s_y,1);
        printf("%d ",tim);
        tim=1;
        find(s_x,s_y,3);
        printf("%d ",tim);
        bfs(s_x,s_y);
        printf("%d\n",tim);
        
    }
    return 0;
} 
