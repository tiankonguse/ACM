#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 30
#define MAXM 100
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
bool used[MAXM];
int res=0;
void dfs(int u,int d){
    //cout<<u<<","<<d<<endl;system("pause");
    if(d>res)res=d;
    for(int j=p[u];j!=-1;j=e[j].next){
      //  printf("(%d,%d):%d\n",u,e[j].u,j);system("pause");
        if(!used[j]){
            used[j]=used[(j^1)]=true;
            dfs(e[j].u,d+1);
            used[j]=used[(j^1)]=false;
        }
    }
}

void init(){
    idx=0;
    memset(p,0xff,sizeof(p));
}
int main(){
    int a,b;
    while(~scanf("%d%d",&N,&M) && N){
        init();
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        res=0;
        for(int i=0;i<N;i++){
            memset(used,false,sizeof(used));
            dfs(i,0);
        }
        printf("%d\n",res);
    }
    return 0;
}
