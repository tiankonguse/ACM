#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 20005
#define MAXM 40005
#define inf 0x7f7f7f7f
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
int mar;
int dfs(int u){
    used[u]=true;
    int s=1,r=0,d,v;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!used[v]){
            d=dfs(v);
            s+=d;
            if(d>r)r=d;
        }
    }
    if(N-s>r)r=N-s;
    if(r<mar)mar=r;
    res[u]=r;
    return s;
}
void init(){
    idx=0;
    mar=inf;
    memset(p,0xff,sizeof(p));
    memset(used,false,sizeof(used));
}
int main(){
    int T,a,b;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d",&N);
        for(int i=1;i<N;i++){
            scanf("%d%d",&a,&b);
            a--,b--;
            addedge(a,b);
            addedge(b,a);
        }
        dfs(0);
        for(int i=0;i<N;i++){
            if(res[i]==mar){
                printf("%d %d\n",i+1,mar);
                break;
            }
        }
    }
    return 0;
}
