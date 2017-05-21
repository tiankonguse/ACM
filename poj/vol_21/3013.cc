#include"iostream"
#include"queue"
#define MAXN 50005
#define MAXM 100005
#define inf 0x7FFFFFFFFFFFFFFFLL
using namespace std;
struct edges{
    int u,c,next;
}e[MAXM];
int N,M,idx;
int p[MAXN];
__int64 dist[MAXN];
bool used[MAXN];
int q[MAXM*2];
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
void spfa(int s){
    int t,u,w,l=0,h=1;
    memset(used,false,sizeof(used));
    for(int i=0;i<N;i++)dist[i]=inf;
    dist[s]=0;
    q[0]=s;
    while(l<h){
        t=q[l++];
        used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            w=e[i].c;
            if(dist[t]+w<dist[u]){
                dist[u]=dist[t]+w;
                if(!used[u]){
                    used[u]=true;
                    q[h++]=u;
                }
            }
        }
    }
}
int node[MAXN];
int main(){
    int T,a,b,c;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)scanf("%d",&node[i]);
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            addedge(a-1,b-1,c);
            addedge(b-1,a-1,c);
        }
        spfa(0);
        __int64 res=0;
        bool flag=true;
        for(int i=1;i<N;i++){
            if(dist[i]==inf){
                printf("No Answer\n");
                flag=false;
                break;
            }
            res+=dist[i]*node[i];
        }
        if(flag)printf("%I64d\n",res);
    }
   // system("pause");
    return 0;
}
