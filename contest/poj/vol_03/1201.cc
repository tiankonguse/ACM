#include"iostream"
#include"cstdlib"
#include"queue"
#include"cstdio"
#include"string.h"
#define MAXN 50001
#define inf 0x3f3f3f3f
using namespace std;
struct edge{
    int u,c,next;
}e[MAXN*3];
int idx,mx,mn;
int p[MAXN],dist[MAXN];
bool used[MAXN];
//queue<int>q;
int q[1000005];
void init(){
    memset(p,0xff,sizeof(p));
    idx=mx=0;
    mn=inf;
}
void addedge(int u,int v,int c){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].next=p[u];
    p[u]=idx++;
}
void spfa(int s){
    int t,u,w;
    //while(!q.empty())q.pop();
    //memset(used,false,sizeof(used));
    for(int i=mn;i<=mx;i++)dist[i]=inf;
    dist[s]=0;
    int l=0,h=1;
    q[0]=s;
    //q.push(s);
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
                  //q.push(u);
                  q[h++]=u;
               }
           }
        }
    }
}
int main(){
    int N,a,b,c;
    init();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       scanf("%d%d%d",&a,&b,&c);
       if(a<mn)mn=a;
       if(b+1>mx)mx=b+1;
       addedge(b+1,a,-c);
    }
    for(int i=mn;i<=mx;i++){
       addedge(i-1,i,1);
       addedge(i,i-1,0);
    }
    spfa(mx);
    printf("%d\n",-dist[mn]);
   // system("pause");
    return 0;
}
