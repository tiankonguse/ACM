#include"iostream"
#include"queue"
#include"cstdlib"
#define MAXN 101
#define MAXE 10001
using namespace std;
struct edges{
   int u,next;
   double p;
}e[MAXE];
int N,M,p[MAXN];
double dist[MAXN];
bool used[MAXN];
queue<int>q;
void spfa(int s){
   int t,u;
   double w;
   while(!q.empty())q.pop();
   for(int i=0;i<N;i++)dist[i]=0;
   memset(used,false,sizeof(used));
   dist[s]=1;
   q.push(s);
   while(!q.empty()){
      t=q.front();
      q.pop();
      used[t]=false;
      for(int i=p[t];i!=-1;i=e[i].next){
          u=e[i].u;
          w=e[i].p;
          if(dist[t]*w>dist[u]){
             dist[u]=dist[t]*w;
             if(!used[u]){
                used[u]=true;
                q.push(u);
             }
          }
      }
   }
}
int main(){
    int a,b,idx;
    double pe;
    while(scanf("%d%d",&N,&M)&&N){
        idx=0;
        memset(p,0xff,sizeof(p));
        for(int i=0;i<M;i++){
           scanf("%d%d%lf",&a,&b,&pe);
           a--;b--;
           e[idx].u=b;
           e[idx].p=pe/100.0;
           e[idx].next=p[a];
           p[a]=idx++;
           e[idx].u=a;
           e[idx].p=pe/100.0;
           e[idx].next=p[b];
           p[b]=idx++;
        }
        spfa(0);
        printf("%.6lf percent\n",dist[N-1]*100);
    }
    return 0;
}
