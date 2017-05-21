#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 105
#define MAXM 10005
using namespace std;
int T,N,sc,sm;
struct edges{
    int u,next;
}e1[MAXM],e2[MAXM];
int p1[MAXN],p2[MAXN],idx1,idx2;
bool mark1[MAXN],mark2[MAXN];
bool flag1,flag2;
void addedge1(int u,int v){
    e1[idx1].u=v;
    e1[idx1].next=p1[u];
    p1[u]=idx1++;
}
void addedge2(int u,int v){
    e2[idx2].u=v;
    e2[idx2].next=p2[u];
    p2[u]=idx2++;
}
void init(){
    idx1=idx2=0;
    flag1=flag2=false;
    memset(p1,0xff,sizeof(p1));
    memset(p2,0xff,sizeof(p2));
    memset(mark1,false,sizeof(mark1));
    memset(mark2,false,sizeof(mark2));
}
void dfs1(int s){
    int u;
    mark1[s]=true;
    for(int i=p1[s];i!=-1;i=e1[i].next){
        u=e1[i].u;
        if(!mark1[u])dfs1(u);
    }
}
void dfs2(int s){
    int u;
    mark2[s]=true;
    for(int i=p2[s];i!=-1;i=e2[i].next){
        u=e2[i].u;
        if(!mark2[u])dfs2(u);
    }
}
bool dfs3(int s){
    int u;
    if(mark1[s])return false;
    mark2[s]=true;
    for(int i=p2[s];i!=-1;i=e2[i].next){
        u=e2[i].u;
        if(u==sm || dfs3(u))return true;
    }
    return false;
}
int main(){
    int a,b;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d%d",&N,&sc,&sm);
        while(scanf("%d%d",&a,&b)){
            if(a==-1 && b==-1)break;
            addedge1(a,b);
        }
        while(scanf("%d%d",&a,&b)){
            if(a==-1 && b==-1)break;
            addedge2(a,b);
        }
        dfs1(sc);
        dfs2(sm);

        for(int i=1;i<=N;i++){
            if(mark1[i]&&mark2[i]){
                flag1=true;
                break;
            }
        }
        memset(mark2,false,sizeof(mark2));
        if(dfs3(sm))flag2=true;
        printf("%c %c\n",flag1?'Y':'N',flag2?'Y':'N');
    }
    return 0;
}
