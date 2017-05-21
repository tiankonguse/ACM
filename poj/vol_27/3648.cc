#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define min(a,b) (a<b?a:b)
#define MAXN 150
#define MAXM 20000
using namespace std;
struct edges{
    int u,next;
}e[MAXM],es[MAXM];
int N,M,idx,idxs;
int p[MAXN],ps[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
void addedges(int u,int v){
    es[idxs].u=v;
    es[idxs].next=ps[u];
    ps[u]=idxs++;
}
int low[MAXN],dfn[MAXN],cont;
int color[MAXN],ccnt;
int stack[MAXN],stop;
bool instack[MAXN];

void tarjan(int u){
    int v,t;
    dfn[u]=low[u]=++cont;
    stack[stop++]=u;
    instack[u]=true;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        do{
            t=stack[--stop];
            instack[t]=false;
            color[t]=ccnt;
        }while(t!=u);
        ccnt++;
    }
}
int opp[MAXN];
int degree[MAXN];
int q[MAXN];
int mark[MAXN];
bool judge(){
    for(int i=0;i<N;i+=2){
        if(color[i]==color[i+1])return false;
        opp[color[i]]=color[i+1];
        opp[color[i+1]]=color[i];
    }
    return true;
}
void print(int a){
    printf("%d%c",a/4,a%4<2?'w':'h');
}
void inits(){
    idxs=0;
    memset(ps,0xff,sizeof(ps));
    memset(degree,0,sizeof(degree));
    memset(mark,0xff,sizeof(mark));
}
void init(){
    idx=cont=ccnt=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
void solve(){
    for(int i=0;i<N;i++){
        if(!dfn[i])tarjan(i);
    }
    if(!judge()){printf("bad luck\n");return;}
    int v,t;
    inits();
    for(int i=0;i<N;i++){
        for(int j=p[i];j!=-1;j=e[j].next){
            v=e[j].u;
            if(color[i]!=color[v]){
                addedges(color[v],color[i]);
                degree[color[i]]++;
            }
        }
    }
    int l=0,h=0;
    for(int i=0;i<ccnt;i++){
        if(degree[i]==0)q[h++]=i;
    }
    while(l<h){
        t=q[l++];
        degree[t]--;
        if(mark[t]==-1){
            mark[t]=0;
            mark[opp[t]]=1;
        }
        for(int i=ps[t];i!=-1;i=es[i].next){
            v=es[i].u;
            degree[v]--;
            if(degree[v]==0)q[h++]=v;
        }
    }
    //for(int i=0;i<ccnt;i++)printf("%d ",mark[i]);printf("\n");
    for(int i=4;i<N;i+=2){
        if(mark[color[i]]==0){
            print(i);
            if(i<N-4)printf(" ");
            else printf("\n");
        }
    }
}

int trans(char* s){
    int len=strlen(s);
    int r=0;
    for(int i=0;i<len-1;i++){
        r=r*10+s[i]-'0';
    }
    r*=4;
    if(s[len-1]=='h')r+=2;
    return r;
}
int main(){
    int u,v;
    char a[5],b[5];
    while(scanf("%d%d",&N,&M) && N){
        init();
        N*=4;
        for(int i=4;i<N;i+=4){
            addedge(i,i+3);
            addedge(i+2,i+1);
            addedge(i+1,i+2);
            addedge(i+3,i);
        }
        addedge(1,0);
        addedge(2,3);
        for(int i=0;i<M;i++){
            scanf(" %s %s",a,b);
            u=trans(a);
            v=trans(b);
          //  printf("%d %d\n",u,v);
            addedge(u+1,v);
            addedge(v+1,u);
        }
        solve();
   // for(int i=0;i<N;i++)printf("%d ",color[i]);printf("\n");
    }
    return 0;
}
