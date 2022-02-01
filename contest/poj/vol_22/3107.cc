#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 50005
#define MAXM 100005
#define max(a,b) (a>b?a:b)
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
    res[u]=r;
    if(r<mar)mar=r;
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
        mar=inf;
        dfs(0);
        int cnt=0;
        for(int i=0;i<N;i++){
            if(res[i]==mar){
                printf("%d ",i+1);
                cnt++;
                if(cnt>=2)break;
            }
        }
        printf("\n");
    }
    return 0;
}
