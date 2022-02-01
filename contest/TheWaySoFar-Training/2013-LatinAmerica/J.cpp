#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;
#define N 100005

int n , m , K;
int a[N],b[N],f[N],g[N],fa[N],t[N];
int first[N],next[N*2],end[N*2];
int tot;

void add_edge(int x,int y){
    next[++tot]=first[x];
    first[x]=tot;
    end[tot]=y;
}

void dfs(int x,int ff){
    fa[x]=ff;
    for (int k=first[x]; k; k=next[k]){
        if (end[k]==ff) continue;
        dfs(end[k],x);
        f[x]=max(f[x],f[end[k]]+1);
    }
}

void calc(int x,int M){
    g[x]=0;
    for (int k=first[x]; k; k=next[k]){
        if (end[k]==M) continue;
        if (end[k]==fa[x]) g[x]=max(g[x],g[end[k]]+1);
        else g[x]=max(g[x],f[end[k]]+1);
    }
}

void dfs1(int x,int ff){
    calc(ff,x);
    calc(x,0);
    t[x]=g[x];
    for (int k=first[x]; k; k=next[k]){
        if (end[k]==ff) continue;
        dfs1(end[k],x);
    }
}

void init(int n,int a[]){
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    tot=0;
    memset(first,0,sizeof(first));
    for (int i=1; i<n; ++i){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(1,0);
    dfs1(1,0);
    memcpy(a,t,sizeof(t));
}

LL sum[N];

double work(int n,int m){
    LL ans=0;
    int len=0;
    for (int i=1; i<=n; ++i) len=max(len,a[i]);
    for (int i=1; i<=m; ++i) len=max(len,b[i]);
    sort(a+1,a+1+n);
    memset(sum,0,sizeof(sum));
    for (int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
    sum[n+1]=sum[n];
    for (int i=1; i<=m; ++i){
        int p=len-1-b[i];
        int t=upper_bound(a+1,a+1+n,p)-a;
        ans+=(LL)(t-1)*len;
        ans+=(LL)(sum[n]-sum[t-1])+(LL)(n-t+1)*(b[i]+1);
    }
    return ((double)ans)/n/m;
}

int main() {
    while (scanf("%d%d",&n,&m)==2){
        init(n,a);
        init(m,b);
        printf("%.3f\n",work(n,m));
    }
    return 0;
}
