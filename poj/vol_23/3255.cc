#include"cstdio"
#include"queue"
#include"string.h"
#define MAXN 5001
#define MAXM 200001
#define inf 0x3f3f3f3f
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
int N,M,idx;
int p[MAXN],d1[MAXN],d2[MAXN];
bool used[MAXN];
queue<int>q;
void init(){
    memset(p,0xff,sizeof(p));
    idx=0;
}
void addedge(int u,int v,int c){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].next=p[u];
    p[u]=idx++;
}
void spfa(int s,int dist[]){
    int t,u,w;
    while(!q.empty())q.pop();
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
    int a,b,c,s,res=inf,dis;
    init();
    scanf("%d%d",&N,&M);
    while(M--){
       scanf("%d%d%d",&a,&b,&c);
       a--;b--;
       addedge(a,b,c);
       addedge(b,a,c);
    }
    spfa(0,d1);
    spfa(N-1,d2);
    dis=d1[N-1];
    for(int i=0;i<N;i++){
         for(int j=p[i];j!=-1;j=e[j].next){
             s=d1[i]+e[j].c+d2[e[j].u];
             if(s>dis && s<res)res=s;
         }
    }
    printf("%d\n",res);
  //  system("pause");
    return 0;
}
