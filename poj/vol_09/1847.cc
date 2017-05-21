#include"iostream"
#include"queue"
#include"cstdlib"
#define MAXE 10001
#define MAXN 105
using namespace std;
struct edges{
   int u,c,next;
}e[MAXE];
int p[MAXN],dist[MAXN];
bool used[MAXN];
int N,A,B;
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
    int k,a,idx=0;
    memset(p,0xff,sizeof(p));
    scanf("%d%d%d",&N,&A,&B);
    A--;B--;
    for(int i=0;i<N;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
             scanf("%d",&a);
             a--;
             e[idx].u=a;
             if(j==0)e[idx].c=0;
             else e[idx].c=1;
             e[idx].next=p[i];
             p[i]=idx++;
        }
    }
    spfa(A);
    if(dist[B]!=INT_MAX)printf("%d\n",dist[B]);
    else printf("-1\n");
  //  system("pause");
    return 0;
}
