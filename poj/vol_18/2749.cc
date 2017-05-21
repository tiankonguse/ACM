#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 1005
#define MAXM 1000005
using namespace std;
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
struct edges{
    int u,next;
}e[MAXM];
int N,A,B,idx;
int p[MAXN];
int x1,y1,x2,y2,ds;
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}

int dfn[MAXN],low[MAXN],cont;
int color[MAXN],ccnt;
int stack[MAXN],stop;
bool instack[MAXN];

void tarjan(int u){
    low[u]=dfn[u]=++cont;
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
bool solve(){
    for(int i=0;i<2*N;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=0;i<2*N;i+=2){
        if(color[i]==color[i+1])return false;
    }
    return true;
}

void init(){
    idx=cont=ccnt=stop=0;
    memset(p,0xff,sizeof(p));
    memset(dfn,0,sizeof(dfn));
    memset(instack,false,sizeof(instack));
}
int ab(int a){
    return a>0?a:-a;
}
int mht(int x1,int y1,int x2,int y2){
    return ab(x1-x2)+ab(y1-y2);
}
int cow[MAXN][2];
int ha[MAXN][2];
int fr[MAXN][2];
void build(int k){
    init();
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(mht(x1,y1,cow[i][0],cow[i][1])+mht(x1,y1,cow[j][0],cow[j][1])>k){
                addedge(2*i,2*j+1);
                addedge(2*j,2*i+1);
            }
            if(mht(x1,y1,cow[i][0],cow[i][1])+mht(x2,y2,cow[j][0],cow[j][1])+ds>k){
                addedge(2*i,2*j);
                addedge(2*j+1,2*i+1);
            }
            if(mht(x2,y2,cow[i][0],cow[i][1])+mht(x1,y1,cow[j][0],cow[j][1])+ds>k){
                addedge(2*i+1,2*j+1);
                addedge(2*j,2*i);
            }
            if(mht(x2,y2,cow[i][0],cow[i][1])+mht(x2,y2,cow[j][0],cow[j][1])>k){
                addedge(2*i+1,2*j);
                addedge(2*j+1,2*i);
            }
        }
    }
    int u,v;
    for(int i=0;i<A;i++){
        u=ha[i][0];
        v=ha[i][1];
        addedge(2*u,2*v+1);
        addedge(2*v,2*u+1);
        addedge(2*u+1,2*v);
        addedge(2*v+1,2*u);
    }
    for(int i=0;i<B;i++){
        u=fr[i][0];
        v=fr[i][1];
        addedge(2*u,2*v);
        addedge(2*v+1,2*u+1);
        addedge(2*u+1,2*v+1);
        addedge(2*v,2*u);
    }
}
int main(){
    int mi,ma,d;
    while(~scanf("%d%d%d",&N,&A,&B)){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ds=mht(x1,y1,x2,y2);
        mi=0x7f7f7f7f,ma=0;
        for(int i=0;i<N;i++){
            scanf("%d%d",&cow[i][0],&cow[i][1]);
            d=mht(x1,y1,cow[i][0],cow[i][1]);
            mi=min(mi,d);ma=max(ma,d);
            d=mht(x2,y2,cow[i][0],cow[i][1]);
            mi=min(mi,d);ma=max(ma,d);
        }
        for(int i=0;i<A;i++){
            scanf("%d%d",&ha[i][0],&ha[i][1]);
            ha[i][0]--;
            ha[i][1]--;
        }
        for(int i=0;i<B;i++){
            scanf("%d%d",&fr[i][0],&fr[i][1]);
            fr[i][0]--;
            fr[i][1]--;
        }
        int l=mi*2,h=ma*2+ds,mid;
        bool flag=false;
        while(l<=h){
            mid=(l+h)>>1;
            build(mid);
            if(solve()){
              //  for(int i=0;i<2*N;i++)printf("%d ",color[i]);printf("\n");
                flag=true;
                h=mid-1;
            }
            else l=mid+1;
        }
        if(flag)printf("%d\n",l);
        else printf("-1\n");
    }
    return 0;
}
