#include"iostream"
#include"cstdlib"
#include"queue"
using namespace std;
struct node{
   int x,y,t;
   node(int i,int j,int k):x(i),y(j),t(k){}
};
bool check(int x,int y){
    if(x>=0 && y>=0 && x<8 && y<8)return true;
    else return false;
}
bool map[10][10];
int dir[8][2]={{-2,1},{-1,2},{1,2},{2,1},
               {2,-1},{1,-2},{-1,-2},{-2,-1}};
queue<node>q;
int bfs(int sx,int sy,int dx,int dy){
   int tx,ty,tt;
   if(sx==dx && sy==dy)return 0;
   while(!q.empty())q.pop();
   q.push(node(sx,sy,0));
   node tmp(0,0,0);
   map[sx][sy]=true;
   while(!q.empty()){
       tmp=q.front();
       q.pop();
       tt=tmp.t;
       for(int i=0;i<8;i++){
          tx=tmp.x+dir[i][0];
          ty=tmp.y+dir[i][1];
          if(check(tx,ty)&& !map[tx][ty]){
              map[tx][ty]=true;
              if(tx==dx && ty==dy)return tt+1;
              q.push(node(tx,ty,tt+1));
          }
       }
   }
   return -1;
}
int main(){
    int sx,sy,dx,dy,ans;
    char s[3],d[3];
    while(~scanf("%s%s",s,d)){
        sx=s[0]-'a';
        sy=s[1]-'1';
        dx=d[0]-'a';
        dy=d[1]-'1';
        memset(map,false,sizeof(map));    
        ans=bfs(sx,sy,dx,dy);
        printf("To get from %s to %s takes %d knight moves.\n",s,d,ans);
    }
    return 0;
}
