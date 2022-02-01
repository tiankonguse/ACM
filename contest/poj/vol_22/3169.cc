#include"iostream"
#include"queue"
#define MAXN 1001
#define MAXM 30005
#define inf 0x3f3f3f3f
using namespace std;
struct edge{
    int u,c,next;
}e[MAXM];
queue<int>q;
int N,idx;
int p[MAXN],dist[MAXN],cnt[MAXN];
bool used[MAXN];
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
int spfa(int s){
    int t,u,w;
    while(!q.empty())q.pop();
    for(int i=0;i<N;i++)dist[i]=inf;
    memset(used,false,sizeof(used));
    memset(cnt,0,sizeof(cnt));
    cnt[s]=1;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        t=q.front();
        q.pop();
        used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
             w=e[i].c;
             u=e[i].u;
             if(dist[t]+w<dist[u]){
                  dist[u]=dist[t]+w;
                  if(!used[u]){
                     used[u]=true;
                     q.push(u);
                     cnt[u]++;
                     if(cnt[u]>N)return -1;
                  }
             }
        }
    }
    if(dist[N-1]==inf)return -2;
    else return dist[N-1];
} 
int main(){
    int ML,MD,a,b,c;
    init();
    scanf("%d%d%d",&N,&ML,&MD);
    for(int i=0;i<ML;i++){
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        addedge(a,b,c);
    }
    for(int i=0;i<MD;i++){
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        addedge(b,a,-c);
    }
    for(int i=1;i<N;i++){
        addedge(i,i-1,0);
    }
    printf("%d\n",spfa(0));
   // system("pause");
    return 0;
}
