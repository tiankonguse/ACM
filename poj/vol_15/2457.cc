#include"iostream"
#include"cstdlib"
#include"queue"
#include"stack"
#define MAXN 1001
#define MAXE 50001
using namespace std;
struct edges{
   int u,c,next;
}e[MAXE];
int N,M;
int dist[MAXN],p[MAXN],pre[MAXN];
bool used[MAXN];
queue<int>q;
stack<int>path;
void spfa(int s){
    int t,u,w;
    while(!q.empty())q.pop();
    for(int i=0;i<N;i++)dist[i]=INT_MAX;
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
                pre[u]=t;
                if(!used[u]){
                    used[u]=true;
                    q.push(u);
                }
            }
        }
    }
}
int main(){
    int a,b,pr;
    memset(p,0xff,sizeof(p));
    scanf("%d%d",&M,&N);
    for(int i=0;i<M;i++){
       scanf("%d%d",&a,&b);
       a--;b--;
       e[i].u=b;e[i].c=1;e[i].next=p[a];p[a]=i;
    }
    spfa(0);
    if(dist[N-1]==INT_MAX)printf("-1\n");
    else{
        pr=N-1;
        while(pr!=0){
           path.push(pr);
           pr=pre[pr];
        }
        path.push(0);
        printf("%d\n",dist[N-1]+1);
        for(int i=0;i<=dist[N-1];i++){
           printf("%d\n",path.top()+1);
           path.pop();
        }
    }
   // system("pause");
    return 0;
}
