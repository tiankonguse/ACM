#include"iostream"
#include"queue"
#define MAXN 1005
#define MAXM 100005
#define inf 0x3f3f3f3f
using namespace std;
struct edges{
    int u,c,next;
}e1[MAXM],e2[MAXM];
int N,M,idx1,idx2;
int S,T,K;
int p1[MAXN],p2[MAXN],dist[MAXN],cnt[MAXN];
bool used[MAXN];
//queue<int>q;
int q[MAXM];
void init(){
    idx1=idx2=0;
    memset(p1,0xff,sizeof(p1));
    memset(p2,0xff,sizeof(p2));
}
void addedge1(int u,int v,int c){
    e1[idx1].u=v;
    e1[idx1].c=c;
    e1[idx1].next=p1[u];
    p1[u]=idx1++;
}
void addedge2(int u,int v,int c){
    e2[idx2].u=v;
    e2[idx2].c=c;
    e2[idx2].next=p2[u];
    p2[u]=idx2++;
}
void spfa(int s){
    int t,u,w;
    memset(dist,0x7f,sizeof(dist));
    memset(used,false,sizeof(used));
    dist[s]=0;
 //   q.push(s);
    int l=0,h=1;
    q[0]=s;
    while(l<h){
        //t=q.front();
        //q.pop();
        t=q[l++];
        used[t]=false;
        for(int i=p2[t];i!=-1;i=e2[i].next){
            u=e2[i].u;
            w=e2[i].c;
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
struct node{
    int u,c;
    node(int u,int c):u(u),c(c){}
    friend bool operator <(node a,node b){
        return dist[a.u]+a.c>dist[b.u]+b.c;
    }
};
priority_queue<node>que;
int astar(int s){
    int t,u,l,w;
    while(!que.empty())que.pop();
    memset(cnt,0,sizeof(cnt));
    node tmp(s,0);
    que.push(tmp);
    while(!que.empty()){
        tmp=que.top();
        que.pop();
        t=tmp.u;
        l=tmp.c;
        cnt[t]++;
        if(cnt[T]==K)return l;
        for(int i=p1[t];i!=-1;i=e1[i].next){
            u=e1[i].u;
            w=e1[i].c;
            que.push(node(u,l+w));
        }
    }
    return -1; //k短路不存在 
}
int getint()                 
{
    int ret=0;
  char tmp;
    while(!isdigit(tmp=getchar()));
    do{
		ret=(ret<<3)+(ret<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return ret;
}
int main(){
    int a,b,c;
    init();
   // scanf("%d%d",&N,&M);
    N=getint();
    M=getint(); 
    for(int i=0;i<M;i++){
      //  scanf("%d%d%d",&a,&b,&c);
      //  a--;b--;
      //  addedge1(a,b,c);
      //  addedge2(b,a,c);
        a=getint()-1;
        b=getint()-1;
        c=getint();
        addedge1(a,b,c);
        addedge2(b,a,c);
    }
    //scanf("%d%d%d",&S,&T,&K);
    S=getint();
    T=getint();
    K=getint();
    S--;T--;
    if(S==T)K++;
    spfa(T);
    if(dist[S]>=inf)printf("-1\n");
    else{
        printf("%d\n",astar(S));
    }
  //  system("pause");
    return 0;
}
