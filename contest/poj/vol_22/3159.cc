#include"iostream"
#include"cstdio"
#include"string.h"
#include"stack"
#define inf 0x7fffffff
#define MAXN 30010
#define MAXM 150010
using namespace std;
struct edges{
    int next,u,c;
}e[MAXM];
int p[MAXN],dist[MAXN];
bool used[MAXN];
int N,idx;
int q[MAXM+1];
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
int spfa(int s){
    int t,u,w;
    for(int i=0;i<N;i++)dist[i]=inf;
  //  memset(used,false,sizeof(used));
    dist[s]=0;
    int l=1;
    q[0]=s;
    while(l>0){
        t=q[--l];
        used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            w=e[i].c;
            if(dist[t]+w<dist[u]){
                dist[u]=dist[t]+w;
                if(!used[u]){
                    used[u]=true;
                    q[l++]=u;
                }
            }
        }
    }
    return dist[N-1];
}
int main(){
    int M,a,b,c;
    scanf("%d%d",&N,&M);
    init();
    for(int i=0;i<M;i++){
       scanf("%d%d%d",&a,&b,&c);
       addedge(a-1,b-1,c);
    }
    printf("%d\n",spfa(0));
    //system("pause");
    return 0;
}
