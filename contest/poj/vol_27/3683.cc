#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 2005
#define MAXM 4000005
#define min(a,b) (a<b?a:b)
using namespace std;
struct edges{
    int u,next;
}e[MAXM],es[MAXM];
int N,idx,idxs;
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
    dfn[u]=low[u]=++cont;
    stack[stop++]=u;
    instack[u]=true;
    int v,t;
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
    if(dfn[u]==low[u]){
        do{
            t=stack[--stop];
            color[t]=ccnt;
            instack[t]=false;
        }while(t!=u);
        ccnt++;
    }
}
int opp[MAXN];
int degree[MAXN];
int mark[MAXN];
int q[MAXN];
struct schedule{
    int s,t,d;
}sc[MAXN];

void init(){
    idx=cont=ccnt=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
void inits(){
    idxs=0;
    memset(ps,0xff,sizeof(ps));
    memset(degree,0,sizeof(degree));
    memset(mark,0xff,sizeof(mark));
}
void solve(){
    for(int i=0;i<N;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=0;i<N;i+=2){
        if(color[i]==color[i+1]){
            printf("NO\n");
            return;
        }
        opp[color[i]]=color[i+1];
        opp[color[i+1]]=color[i];
    }
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
        if(mark[t]==-1){
            mark[t]=0;
            mark[opp[t]]=1;
          //  printf("mark[%d]=0,mark[%d]=1\n",t,opp[t]);
        }
        for(int i=ps[t];i!=-1;i=es[i].next){
            v=es[i].u;
            degree[v]--;
            if(degree[v]==0)q[h++]=v;
        }
    }
    printf("YES\n");
    //for(int i=0;i<N;i++)printf("%d ",color[i]);printf("\n");
    //for(int i=0;i<N;i++)printf("%d ",mark[color[i]]);printf("\n");
    int a,b;
    for(int i=0;i<N;i++){
        if(mark[color[i]]==0){
            t=(i>>1);
            if(i&1){
                a=sc[t].t-sc[t].d;
                b=sc[t].t;
                printf("%02d:%02d %02d:%02d\n",a/60,a%60,b/60,b%60);
            }
            else{
                a=sc[t].s;
                b=sc[t].s+sc[t].d;
                printf("%02d:%02d %02d:%02d\n",a/60,a%60,b/60,b%60);
            }
        }
    }
}




int judge(int sa,int ta,int sb,int tb){
    if(ta<=sb || sa>=tb)return false;
    else return true;
}
int main(){
    int ha,ma,hb,mb;
    while(~scanf("%d",&N)){
        init();
        for(int i=0;i<N;i++){
            scanf("%d:%d %d:%d %d",&ha,&ma,&hb,&mb,&sc[i].d);
            sc[i].s=ha*60+ma;
            sc[i].t=hb*60+mb;
        }
        //build
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(judge(sc[i].s,sc[i].s+sc[i].d,sc[j].s,sc[j].s+sc[j].d)){
                    addedge(i*2,j*2+1);
                    addedge(j*2,i*2+1);
                }
                if(judge(sc[i].s,sc[i].s+sc[i].d,sc[j].t-sc[j].d,sc[j].t)){
                    addedge(i*2,j*2);
                    addedge(j*2+1,i*2+1);
                }
                if(judge(sc[i].t-sc[i].d,sc[i].t,sc[j].s,sc[j].s+sc[j].t)){
                    addedge(i*2+1,j*2+1);
                    addedge(j*2,i*2);
                }
                if(judge(sc[i].t-sc[i].d,sc[i].t,sc[j].t-sc[j].d,sc[j].t)){
                    addedge(i*2+1,j*2);
                    addedge(j*2+1,i*2);
                }
            }
        }
        N*=2;
        //solve
        solve();
    }
    return 0;
}
