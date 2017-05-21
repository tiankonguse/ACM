#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define see(x) cout<<"[DEBUG] "#x" = "<<x<<endl
#define MAXN 30
#define MAXM 1005
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,idx;
int p[MAXN];
int mark[MAXN];
bool flag;
int res;
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
void init(){
    idx=0;
    res=1;
    memset(p,0xff,sizeof(p));
    memset(mark,0,sizeof(mark));
}
void dfs(int u){
    int mask=0,ee=0,v;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        mask |= mark[v];
    }
    while(mask&1==1){
        mask>>=1;
        ee++;
    }
    mark[u]=1<<ee;
   // see(u);
   // see(mark[u]);
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(mark[v]==0)dfs(v);
    }
}
char str[55];
int main(){
    int len;
    while(scanf("%d",&N) && N){
        init();
        for(int i=0;i<N;i++){
            scanf(" %s",str);
            len=strlen(str);
            for(int i=2;i<len;i++){
                addedge(str[0]-'A',str[i]-'A');
            }
        }
        for(int i=0;i<N;i++){
            if(mark[i]==0){
                dfs(i);
            }
        }
        for(int i=0;i<N;i++)if(mark[i]>res)res=mark[i];
        int ans=1;
        while((res&1)==0){res>>=1;ans++;}
        if(ans==1)printf("1 channel needed.\n");
        else printf("%d channels needed.\n",ans);
    }
    return 0;
}
