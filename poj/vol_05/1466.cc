#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstring>
#define MAXN 505
#define MAXM 250005
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,M,idx;
int p[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
}

int matx[MAXN],maty[MAXN];
bool used[MAXN];
int path(int u){
    int v;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!used[v]){
            used[v]=true;
            if(maty[v]==-1 || path(maty[v])){
                matx[u]=v;
                maty[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(){
    memset(matx,0xff,sizeof(matx));
    memset(maty,0xff,sizeof(maty));
    int res=0;
    for(int i=0;i<N;i++){
        if(matx[i]==-1){
            memset(used,false,sizeof(used));
            res+=path(i);
        }
    }
    return res;
}
int main(){
    int a,k,b;
    while(~scanf("%d",&N)){
        init();
        for(int i=0;i<N;i++){
            scanf("%d: (%d)",&a,&k);
            for(int j=0;j<k;j++){
                scanf("%d",&b);
                addedge(a,b);
            }
        }
        printf("%d\n",N-hungary()/2);
    }
    return 0;
}
