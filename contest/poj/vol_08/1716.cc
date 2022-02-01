#include"iostream"
#include"cstdlib"
#include"queue"
#include"string.h"
#include"cstdio"
#define inf 0x3f3f3f3f
#define MAXN 10005
using namespace std;
struct edge{
   int u,c,next;
}e[MAXN*4];
int N,idx,mx,mn;
int p[MAXN],dist[MAXN];
bool used[MAXN];
queue<int>q;
void init(){
    idx=mx=0;
    mn=inf;
    memset(p,0xff,sizeof(p));
}
void addedge(int u,int v,int c){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].next=p[u];
    p[u]=idx++;
}
void spfa(int s){
   int t,u,w;
   while(!q.empty())q.pop();
   memset(used,false,sizeof(used));
   for(int i=mn;i<=mx;i++)dist[i]=inf;
   dist[s]=0;
   q.push(s);
   while(!q.empty()){
      t=q.front();
      q.pop();
      used[t]=false;
      for(int i=p[t];i!=-1;i=e[i].next){
          u=e[i].u;
          w=e[i].c;
          if(dist[t]+w<dist[u]){
             dist[u]=dist[t]+w;
             if(!used[u]){
                used[u]=true;
                q.push(u);
             }
          }
      }
   }
}
int main(){
    int a,b;
    init();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       scanf("%d%d",&a,&b);
       if(a<mn)mn=a;
       if(b+1>mx)mx=b+1;
       addedge(b+1,a,-2);
    }
    for(int i=mn+1;i<=mx;i++){
         addedge(i-1,i,1);
         addedge(i,i-1,0);
    }
    spfa(mx);
    printf("%d\n",-dist[mn]);
   // system("pause");
    return 0;
}
