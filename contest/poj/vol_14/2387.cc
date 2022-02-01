#include"iostream"
#include"cstdlib"
#include"queue"
#define MAXE 4002
#define MAXN 1002
using namespace std;
struct edges{
   int u,c,next;
}e[MAXE];
int T,N;
int p[MAXN],used[MAXN],dist[MAXN];
void spfa(int s){
   int t,w,u;
   for(int i=0;i<N;i++)dist[i]=INT_MAX;
   queue<int>q;
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
              }
          }
       }
   }
}
int main(){
    int a,b,c;
    memset(p,0xff,sizeof(p));
    scanf("%d%d",&T,&N);
    for(int i=0;i<T;i++){
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        e[i*2].u=b;
        e[i*2].c=c;
        e[i*2].next=p[a];
        p[a]=i*2;
        e[i*2+1].u=a;
        e[i*2+1].c=c;
        e[i*2+1].next=p[b];
        p[b]=i*2+1;
    }
    spfa(0);
    printf("%d\n",dist[N-1]);
  //  system("pause");
    return 0;
}
