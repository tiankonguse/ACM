#include"iostream"
#include"queue"
#define MAXN 505
#define MAXM 2005
#define inf 0x3f3f3f3f
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
int tim[10]={inf,2520,1260,840,630,504,420,360,315,280};
int T,N,M,idx;
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
    for(int i=0;i<T;i++)dist[i]=inf;
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
    int a;
    char c;
    while(scanf("%d%d",&N,&M)&&N){
        init();
        T=(N+1)*(M+1);
        for(int i=0;i<M;i++){
            scanf("%d %c",&a,&c);
            if(a==0)continue;
            if(c=='>')addedge(i,i+1,tim[a]);
            else if(c=='<')addedge(i+1,i,tim[a]);
            else{
                addedge(i,i+1,tim[a]);
                addedge(i+1,i,tim[a]);
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<=M;j++){
                scanf("%d %c",&a,&c);
                if(a==0)continue;
                if(c=='v')addedge((i-1)*(M+1)+j,i*(M+1)+j,tim[a]);
                else if(c=='^')addedge(i*(M+1)+j,(i-1)*(M+1)+j,tim[a]);
                else{
                    addedge((i-1)*(M+1)+j,i*(M+1)+j,tim[a]);
                    addedge(i*(M+1)+j,(i-1)*(M+1)+j,tim[a]);
                }
            }
            for(int j=0;j<M;j++){
                scanf("%d %c",&a,&c);
                if(a==0)continue;
                if(c=='>')addedge(i*(M+1)+j,i*(M+1)+j+1,tim[a]);
                else if(c=='<')addedge(i*(M+1)+j+1,i*(M+1)+j,tim[a]);
                else{
                   addedge(i*(M+1)+j,i*(M+1)+j+1,tim[a]);
                   addedge(i*(M+1)+j+1,i*(M+1)+j,tim[a]);
                }
            }
        }
        spfa(0);
        if(dist[T-1]!=inf)printf("%d blips\n",dist[T-1]);
        else printf("Holiday\n");
    }
    return 0;
}
