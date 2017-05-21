#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 10005
#define MAXM 100005
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int p[MAXN],idx;
int N,M;
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
int path[MAXM];
bool used[MAXM];
void dfs(int u,int d){
    for(int i=p[u];i!=-1;i=e[i].next){
        int v=e[i].u;
        if(!used[i]){
            used[i]=true;
            dfs(v,d+1);
        }
    }
    printf("%d\n",u+1);
}

void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
    memset(used,false,sizeof(used));
}
int main(){
    int a,b,cnt;
    while(~scanf("%d%d",&N,&M)){
        init();
        cnt=0;
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            addedge(a,b);
            addedge(b,a);
        }
        M<<=1;
        dfs(0,0);
    }
    return 0;
}
