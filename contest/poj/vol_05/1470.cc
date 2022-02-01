#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1005
#define MAXM 2005
#define MAXK 500005
using namespace std;
struct edges{
    int u,next;
}e1[MAXM],e2[MAXK];
int p1[MAXN],p2[MAXN];
int N,K,idx1,idx2;
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
bool used[MAXN];
int parents[MAXN];
int cnt[MAXN];
int find(int a){
    if(parents[a]==-1)return a;
    else return parents[a]=find(parents[a]);
}
void dfs(int u){
    int v;
    used[u]=true;
    for(int i=p2[u];i!=-1;i=e2[i].next){
        v=e2[i].u;
        if(used[v]){
            cnt[find(v)]++;
        }
    }
    for(int i=p1[u];i!=-1;i=e1[i].next){
        v=e1[i].u;
        if(!used[v]){
            dfs(v);
            parents[v]=u;
        }
    }
}

void init(){
    idx1=idx2=0;
    memset(p1,0xff,sizeof(p1));
    memset(p2,0xff,sizeof(p2));
    memset(used,false,sizeof(used));
    memset(parents,0xff,sizeof(parents));
    memset(cnt,0,sizeof(cnt));
}
int main(){
    int num,a,b,root;
    while(~scanf("%d",&N)){
        init();
        for(int i=0;i<N;i++){
            scanf("%d:(%d)",&a,&num);
            a--;
            for(int j=0;j<num;j++){
                scanf("%d",&b);
                b--;
                addedge1(a,b);
                addedge1(b,a);
                used[b]=true;
            }
        }
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf(" (%d %d)",&a,&b);
            a--;b--;
            addedge2(a,b);
            addedge2(b,a);
        }
        for(int i=0;i<N;i++){
            if(!used[i]){
                root=i;
                break;
            }
        }
        memset(used,false,sizeof(used));
        dfs(root);
        for(int i=0;i<N;i++){
            if(cnt[i]!=0){
                printf("%d:%d\n",i+1,cnt[i]);
            }
        }
    }
    return 0;
}
