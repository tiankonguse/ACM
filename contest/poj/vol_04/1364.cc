#include"iostream"
#include"queue"
#define MAXN 105
#define MAXM 1000
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
    for(int i=0;i<N;i++){
            dist[i]=0;
            q.push(i);
    }
    memset(used,false,sizeof(used));
    memset(cnt,0,sizeof(cnt));
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
    int M,a,b,c;
    char dir[3];
    while(scanf("%d",&N)&&N){
        N+=2;
        init();
        scanf("%d",&M);
        while(M--){
           scanf("%d %d %s %d",&a,&b,dir,&c);
           if(dir[0]=='g'){
               addedge(a+b,a-1,-c-1);
           }
           else{
               addedge(a-1,a+b,c-1);
           }
        }
        if(spfa(0)==-1)printf("successful conspiracy\n");
        else printf("lamentable kingdom\n");
    }
   // system("pause");
    return 0;
}
