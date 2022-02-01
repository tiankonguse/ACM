#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 100005
#define MAXM 1000005
using namespace std;
struct edges{
    int u,next;
}e[MAXM];
int N,M,idx;
int p[MAXN];
long long sum;
long long num[MAXN];
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
long long ab(long long a){
    return a>0?a:-a;
}
bool used[MAXN];
long long res[MAXN];
long long dfs(int u){
    used[u]=true;
    long long s=num[u];
    int v;
    for(int i=p[u];i!=-1;i=e[i].next){
        v=e[i].u;
        if(!used[v]){
            s+=dfs(v);
        }
    }
    res[u]=ab(sum-s-s);
    return s;
}
void init(){
    idx=sum=0;
    memset(p,0xff,sizeof(p));
    memset(used,false,sizeof(used));
}
int main(){
    int a,b,ca=1;
    while(scanf("%d%d",&N,&M)&&N){
        init();
        for(int i=0;i<N;i++){
            scanf("%lld",&num[i]);
            sum+=num[i];
        }
        for(int i=0;i<M;i++){
            scanf("%d%d",&a,&b);
            a--,b--;
            addedge(a,b);
            addedge(b,a);
        }
        dfs(0);
        long long ans=0x7FFFFFFFFFFFFFFFLL;
        for(int i=0;i<N;i++){
            if(res[i]<ans)ans=res[i];
        }
        printf("Case %d: %lld\n",ca++,ans);
    }
    return 0;
}
