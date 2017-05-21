#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 10005
#define MAXM 20005
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,idx;
int p[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
bool used[MAXN];
int res[MAXN];
int dfs(int u){
    used[u]=true;
    int s=1,r=0,v,d;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!used[v]){
            d=dfs(v);
            s+=d;
            if(d>r)r=d;
        }
    }
    if(N-s>r)r=N-s;
    res[u]=r;
    return s;
}
void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
    memset(used,false,sizeof(used));
}
int main(){
    int a,b;
    while(~scanf("%d",&N)){
        init();
        for(int i=1;i<N;i++){
            scanf("%d%d",&a,&b);
            a--,b--;
            addedge(a,b);
            addedge(b,a);
        }
        dfs(0);
        bool flag=false;
        int p=N/2;
        for(int i=0;i<N;i++){
            if(res[i]<=p){
                flag=true;
                printf("%d\n",i+1);
            }
        }
        if(!flag)printf("NONE\n");
    }
    return 0;
}
