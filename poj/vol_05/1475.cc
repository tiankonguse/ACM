#include"iostream"
#include"queue"
#include"string"
#define MAXN 21
using namespace std;
int N,M;
struct node{
    int x,y,t,sx,sy;
    node(int x,int y,int t,int sx,int sy):x(x),y(y),t(t),sx(sx),sy(sy){}
};
queue<node>q;
char map[MAXN][MAXN];
int used[MAXN][MAXN];
int push[MAXN][MAXN];
string path[MAXN][MAXN];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char dire[4]={'e','w','s','n'};
char direu[4]={'E','W','S','N'};
bool check(int x,int y){
    if(x<0 || x>=N || y<0 || y>=M || map[x][y]=='#')return false;
    return true;
}
struct man{
    int x,y,t;
    man(int x,int y,int t):x(x),y(y),t(t){}
};
queue<man>qm;
bool mark[MAXN][MAXN];
int pre[MAXN][MAXN];
string bfs_man(int sx,int sy,int dx,int dy,int bx,int by){
    string s="";
    if(sx==dx && sy==dy)return s;
    int tx,ty,d;
    bool find=false;
    while(!qm.empty())qm.pop();
    memset(mark,false,sizeof(mark));
    mark[sx][sy]=true;
    man cur(sx,sy,0);
    qm.push(cur);
    while(!qm.empty()){
        cur=qm.front();
        qm.pop();
        for(int i=0;i<4;i++){
            tx=cur.x+dir[i][0];
            ty=cur.y+dir[i][1];
            if(check(tx,ty) && !mark[tx][ty]){
                if(tx==bx && ty==by)continue;
                if(tx==dx && ty==dy){
                    pre[tx][ty]=i;
                    find=true;
                    break;
                }
                mark[tx][ty]=true;
                pre[tx][ty]=i;
                qm.push(man(tx,ty,cur.t+1));
            }
        }
        if(find)break;
    }
    if(!find)return ".";
    while(!(dx==sx && dy==sy)){
        d=pre[dx][dy];
        s=dire[d]+s;
        dx=dx-dir[d][0];
        dy=dy-dir[d][1];
    }
    return s;
}
void bfs(int sx,int sy,int bx,int by){
    int tx,ty,dx,dy,len;
    string s;
    while(!q.empty())q.pop();
    memset(used,0x3f,sizeof(used));
    memset(push,0x3f,sizeof(push));
    used[bx][by]=0;
    push[bx][by]=0;
    path[bx][by]="";
    node tmp(bx,by,0,sx,sy);
    q.push(tmp);
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            tx=tmp.x+dir[i][0];
            ty=tmp.y+dir[i][1];
            dx=tmp.x-dir[i][0];
            dy=tmp.y-dir[i][1];
          //  printf("%d %d to %d %d\n",tmp.x,tmp.y,tx,ty);
          //  system("pause");
            if(check(tx,ty) && check(dx,dy)){
             //   printf("bfsman(%d,%d,%d,%d,%d,%d)\n",tmp.sx,tmp.sy,dx,dy,tmp.x,tmp.y);
             //   system("pause");
                s=bfs_man(tmp.sx,tmp.sy,dx,dy,tmp.x,tmp.y);
                if(s==".")continue;
            /*   if(map[tx][ty]=='T'){
                    path[tx][ty]=path[tmp.x][tmp.y]+s+direu[i];
                    return;
                }*/
                len=s.length();
                if(tmp.t+1<=push[tx][ty] &&len+used[tmp.x][tmp.y]<used[tx][ty]){
                    push[tx][ty]=tmp.t+1;
                    used[tx][ty]=len+used[tmp.x][tmp.y];
                    path[tx][ty]=path[tmp.x][tmp.y]+s+direu[i];
                    q.push(node(tx,ty,tmp.t+1,tmp.x,tmp.y));
                 //   printf("push (%d,%d) to (%d,%d)\n",tmp.x,tmp.y,tx,ty);
                 //   cout<<path[tx][ty]<<endl;
                 //   system("pause");
                }
            }
        }
    }
}
int main(){
    int s_x,s_y,b_x,b_y,t_x,t_y,cnt=1;
    ios::sync_with_stdio(false);
    while(cin>>N>>M &&N){
        for(int i=0;i<N;i++){
           cin>>map[i];
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]=='S'){
                    s_x=i;
                    s_y=j;
                }
                else if(map[i][j]=='B'){
                    b_x=i;
                    b_y=j;
                }
                else if(map[i][j]=='T'){
                    t_x=i;
                    t_y=j;
                }
            }
        }
        path[t_x][t_y]="-";
        bfs(s_x,s_y,b_x,b_y);
        cout<<"Maze #"<<cnt++<<endl;
        if(path[t_x][t_y]=="-")cout<<"Impossible."<<endl<<endl;
        else cout<<path[t_x][t_y]<<endl<<endl;
    }
    return 0;
}
