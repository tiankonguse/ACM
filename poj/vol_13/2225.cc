#include"iostream"
#include"cstdlib"
#include"queue"
using namespace std;
struct node{
   int x,y,z,t;
   node(int i,int j,int k,int l):x(i),y(j),z(k),t(l){}
};
queue<node>q;
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
char map[11][11][11];
bool used[11][11][11];
int N;
bool check(int x,int y,int z){
    if(x>=0 && x<N && y>=0 && y<N && z>=0 && z<N && !used[x][y][z] && map[x][y][z]!='X')return true;
    else return false;
}
int bfs(int sx,int sy,int sz,int dx,int dy,int dz){
   int tx,ty,tz,tt;
   if(sx==dx && sy==dy && sz==dz)return 0;
   while(!q.empty())q.pop();
   q.push(node(sx,sy,sz,0));
   node tmp(0,0,0,0);
   used[sx][sy][sz]=true;
   while(!q.empty()){
       tmp=q.front();
       q.pop();
       tt=tmp.t;
       for(int i=0;i<6;i++){
         tx=tmp.x+dir[i][0];
         ty=tmp.y+dir[i][1];
         tz=tmp.z+dir[i][2];
         if(tx==dx && ty==dy && tz==dz)return tt+1;
         if(check(tx,ty,tz)){
          //   if(tx==dx && ty==dy && tz==dz)return tt+1;
             used[tx][ty][tz]=true;
             q.push(node(tx,ty,tz,tt+1));
         }
       }
   }
   return -1;
}
int main(){
   // freopen("i8.txt","r",stdin);
   // freopen("i8out.txt","w",stdout);
    char str[10];
    int sx,sy,sz,dx,dy,dz,ans;
    while(~scanf("%s",str)){
       scanf("%d",&N);
       memset(used,false,sizeof(used));
       for(int i=0;i<N;i++){
         for(int j=0;j<N;j++){
            scanf("%s",map[i][j]);
         }
       }
       scanf("%d%d%d%d%d%d",&sx,&sy,&sz,&dx,&dy,&dz);
       scanf("%s",str);
       ans=bfs(sz,sy,sx,dz,dy,dx);
       if(ans!=-1){
         printf("%d %d\n",N,ans);
       }
       else printf("NO ROUTE\n");
    }
    return 0;
}
