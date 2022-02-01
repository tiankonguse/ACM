#include"iostream"
#include"string.h"
#include"queue"
#include"cstdio"
#define inf 0x3f3f3f3f
#define MAXN 105
#define MAXM 10005
using namespace std;
struct edges{
     int u,c,next;
}e[MAXM];
queue<int>q;
bool map[MAXN][MAXN];
int p[MAXN],dist[MAXN],cnt[MAXN];
bool used[MAXN];
int N,idx;
void init(){
     idx=0;
     memset(p,0xff,sizeof(p));
}
void addedge(int u,int v,int c){
     e[idx].u=v;
     e[idx].c=c;
     e[idx].next=p[u];
     p[u]=idx++;
}
bool spfa(int s){
     int i,t,u,w;
     while(!q.empty())q.pop();
     for(i=0;i<N;i++)dist[i]=inf;
     memset(used,false,sizeof(used));
     memset(cnt,0,sizeof(cnt));
     cnt[s]=1;
     dist[s]=-100;
     q.push(s);
     while(!q.empty()){ 
         t=q.front();
         if(t==N-1 && dist[t]<0)return true;
         q.pop();
         used[t]=false;
         for(i=p[t];i!=-1;i=e[i].next){
             u=e[i].u;
             w=e[i].c;
             if(dist[t]+w<0 && dist[t]+w<dist[u]){
                 dist[u]=dist[t]+w;
                 if(!used[u]){
                      used[u]=true;
                      cnt[u]++;
                      if(cnt[u]>=N){
                          dist[u]=-inf;
                          if(cnt[u]==N)q.push(u);
                      }        
                      else q.push(u);
                 }
             }
         }
     }
     if(dist[N-1]<0)return true;
     else return false;
}
/*void floyd(){
    int i,j,k;
    for(k=0;k<N;k++){
       for(i=0;i<N;i++){
           for(int j=0;j<N;j++){
               if(map[i][k] && map[k][j])map[i][j]=true;
           }
       }
    }
}*/
int main(){
    int a,b,c;
    while(scanf("%d",&N)){
        if(N==-1)break;
        init();
        memset(map,false,sizeof(map));
        for(int i=0;i<N;i++){
            scanf("%d%d",&c,&a);
            while(a--){
                scanf("%d",&b);
                addedge(i,b-1,-c);
                map[i][b-1]=true;
            }
        }
       // floyd();
        if(spfa(0))printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}
