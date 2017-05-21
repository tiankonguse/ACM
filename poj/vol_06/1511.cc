#include"iostream"
#include"cstdlib"
#include"queue"
#define MAXN 1000005
using namespace std;
struct edges{
   int u,c,next;
}e1[MAXN],e2[MAXN];
int N,M;
int dist[MAXN],p1[MAXN],p2[MAXN];
bool used[MAXN];
//queue<int>q;
int q[MAXN];
void spfa(int s,edges e[],int p[]){
    int t,u,w;
    //while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    for(int i=0;i<N;i++)dist[i]=INT_MAX;
    dist[s]=0;
    //q.push(s);
    int l=0,h=1;
    q[0]=s;
   // while(!q.empty()){
    while(l<h){
       // t=q.front();
       // q.pop();
       t=q[l++];
       used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
             u=e[i].u;
             w=e[i].c;
             if(dist[t]+w<dist[u]){
                 dist[u]=dist[t]+w;
                 if(!used[u]){
                    used[u]=true;
                 //   q.push(u);
                    q[h++]=u;
                 }
             }
        }
         
    }
}

int main(){
    int T,a,b,c;
    __int64 ans;
    scanf("%d",&T);
    while(T--){
        memset(p1,0xff,sizeof(p1));
        memset(p2,0xff,sizeof(p2));
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            e1[i].u=b;e1[i].c=c;e1[i].next=p1[a];p1[a]=i;
            e2[i].u=a;e2[i].c=c;e2[i].next=p2[b];p2[b]=i;
        }
        ans=0;
        spfa(0,e1,p1);
        for(int i=0;i<N;i++)ans+=dist[i];
        spfa(0,e2,p2);
        for(int i=0;i<N;i++)ans+=dist[i];
        printf("%I64d\n",ans);
    }
  //  system("pause");
    return 0;
}
