#include"iostream"
#include"queue"
#include"cstdlib"
#include"string.h"
#include"cstdio"
#define inf 0x3f3f3f3f
#define MAXN 501
#define MAXM 250001
using namespace std;
struct edge{
    int next,u,c;
}e[MAXM];
int N,M,idx;
int p[MAXN],dist[MAXN];
bool used[MAXN];
queue<int>q;
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
void spfa(int s){
    int t,u,w;
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    for(int i=0;i<N;i++)dist[i]=inf;
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
    bool flag;
    int a,b,c,t,u,cas=1;
    double res,r;
    while(scanf("%d%d",&N,&M)&&N){
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            addedge(a,b,c);
            addedge(b,a,c);
        }
        spfa(0);
        res=0;
        flag=true;
      /*  for(int i=0;i<N;i++){
             printf("dist[%d]=%d\n",i,dist[i]);
        }*/
        for(int i=0;i<N;i++){
            for(int j=p[i];j!=-1;j=e[j].next){
                 u=e[j].u;
                 c=e[j].c;
                 if(dist[i]<=dist[u] && dist[i]+c>dist[u]){
                         flag=false;
                         r=dist[u]+1.0*(c-dist[u]+dist[i])/2.0;
                         if(r>res){
                             a=i+1;
                             b=u+1;
                             res=r;
                         }
                 }
            }
        }
        printf("System #%d\n",cas++);
        if(flag){
           a=1;
           for(int i=0;i<N;i++){
                if(dist[i]>res){
                    res=dist[i];
                    a=i+1;
                }
           }
           printf("The last domino falls after %.1lf seconds, at key domino %d.\n",res,a);
        }
        else{
             if(a>b){
                     t=a;
                     a=b;
                     b=t;
             }
             printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",
                   res,a,b);
        }
        printf("\n");
    }
    return 0;
}
