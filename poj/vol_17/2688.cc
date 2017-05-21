#include"iostream"
#include"queue"
#include"algorithm"
#define MAXN 21
#define inf 0x3f3f3f3f
using namespace std;
int N,M;
struct node{
    int x,y,t;
    node(int x,int y,int t):x(x),y(y),t(t){}
};
queue<node>q;
char map[MAXN][MAXN];
bool used[MAXN][MAXN];
int axis[20][2];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dist[MAXN][MAXN];
int num[11];
bool check(int x,int y){
    if(x<0 || x>=N || y<0 || y>=M || map[x][y]=='x')return false;
    return true;
}
int bfs(int sx,int sy,int dx,int dy){
    int tx,ty;
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    used[sx][sy]=true;
    node tmp(sx,sy,0);
    q.push(tmp);
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            tx=tmp.x+dir[i][0];
            ty=tmp.y+dir[i][1];
            if(check(tx,ty) && !used[tx][ty]){
                if(tx==dx && ty==dy)return tmp.t+1;
                used[tx][ty]=true;
                q.push(node(tx,ty,tmp.t+1));
            }
        }
    }
    return -1;
}
int main(){
    int idx;
    while(scanf("%d%d",&M,&N)&&M){
        for(int i=0;i<N;i++){
            scanf(" %s",map[i]);
        }
        idx=1;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]=='o'){
                    axis[0][0]=i;
                    axis[0][1]=j;
                }
                else if(map[i][j]=='*'){
                    axis[idx][0]=i;
                    axis[idx++][1]=j;
                }
            }
        }
        int d;
        bool flag=true;
        for(int i=0;i<idx;i++){
            for(int j=i+1;j<idx;j++){
                d=bfs(axis[i][0],axis[i][1],axis[j][0],axis[j][1]);
                if(d==-1){
                    flag=false;
                    break;
                }
                else dist[i][j]=dist[j][i]=d;
            }
            if(!flag)break;
        }
   /*     for(int i=0;i<idx;i++){
            for(int j=0;j<idx;j++){
                printf("%d ",dist[i][j]);
            }
            printf("\n");
        }*/
        if(!flag){
            printf("-1\n");
            continue;
        }
        for(int i=1;i<idx;i++){
            num[i]=i;
        }
        int s,r=inf;
        do{
            s=0;
            for(int i=1;i<idx;i++){
                //printf("%d ",num[i-1]);
                s+=dist[num[i-1]][num[i]];
            }
           // printf("\n%d\n",s);
            if(s<r)r=s;
        }
        while(next_permutation(num+1,num+idx));
        printf("%d\n",r);
    }
    return 0;
}
