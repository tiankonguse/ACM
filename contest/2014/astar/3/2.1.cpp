#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define lson o<<1
#define rson (o<<1)|1
#define N 10001
#define pb push_back

vector<int> V[N];
int t, ct, n;
int left[N], right[N], val[N], v2[N];
int s[N<<2], l[N<<2], r[N<<2];
int id, root;
bool f[N];
int depth[N], parent[16][N];
void dfs(int x){
    left[x] = right[x] = ++id;
    v2[id] = val[x];
    for(int i=0; i<V[x].size(); i++){
        int j=V[x][i];
        if(f[j])    continue;
        f[j]=1;
        depth[j] = depth[x]+1;
        parent[0][j] = x;
        dfs(j);
        right[x] = max(right[x], right[j]);
    }
}
void maintain(int o){
    s[o] = s[lson]+s[rson];
}
void build(int o, int ll, int rr){
    l[o]=ll; r[o]=rr;
    s[o]=0;
    if(ll<rr){
        int m = (ll+rr)>>1;
        build(lson, ll, m);
        build(rson, m+1, rr);
        maintain(o);
    }
    else{
        s[o] = v2[ll];
    }
}
void update(int o, int p, int v){
    if(l[o]==p && r[o]==p){
        s[o]=v;
        return;
    }
    int m = (l[o]+r[o])>>1;
    if(p<=m)    update(lson, p, v);
    else    update(rson, p, v);
    maintain(o);
}
void init_lca(){
    for(int k=0; k<15; k++){
        for(int v=1; v<=n; v++){
            if(parent[k][v]<0)  parent[k+1][v]=-1;
            else    parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}
int lca(int u, int v){
    if(depth[u]>depth[v]){
        swap(u,v);
    }
    for(int k=0; k<16; k++){
        if((depth[v]-depth[u])>>k & 1){
            v = parent[k][v];
        }
    }
    if(u==v)    return u;
    for(int k=15; k>=0; k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
int query(int o, int ll, int rr){
    if(l[o]==ll && r[o]==rr)    return s[o];
    int m = (l[o]+r[o])>>1;
    if(rr<=m)   return query(lson, ll, rr);
    else if(ll>m)   return query(rson, ll, rr);
    else    return query(lson, ll, m)+query(rson, m+1, rr);
}
int query(int x){
    if(x==root) return s[1];
    int v = lca(root, x);
    if(v!=x){
        return query(1, left[x], right[x]);
    }
    for(int i=0; i<V[x].size(); i++){
        int j=V[x][i];
        if(depth[j]<depth[x])   continue;
        v = lca(root, j);
        if(v==j){//找到前面所说的Y
            return s[1] - query(1, left[j], right[j]);
        }
    }
    return 0;
}

inline void in(int &x){
    char c=getchar();
    x=0;
    while(c<48 || c>57) c=getchar();
    while(c>=48 && c<=57){
        x = x*10+c-48;
        c = getchar();
    }
}

int main(){
    in(t);
    for(ct=1; ct<=t; ct++){
        printf("Case #%d:\n", ct);
        in(n);
        for(int i=1; i<=n; i++) V[i].clear();
        int x, y;
        for(int i=1; i<n; i++){
            in(x); in(y);
            V[x].pb(y);
            V[y].pb(x);
        }
        for(int i=1; i<=n; i++){
            in(val[i]);
        }
        memset(f,0,sizeof(f));
        memset(parent,-1,sizeof(parent));
        f[1]=1;
        id = 0;
        depth[1]=1;
        dfs(1);
        init_lca();
        build(1, 1, n);
        int q;
        char op[10];
        in(q);
        root=1;
        while(q--){
            scanf("%s", op);
            in(x);
            if(op[0]=='Q'){
                printf("%d\n", query(x));
            }
            else if(op[0]=='C'){
                in(y);
                update(1, left[x], y);
            }
            else{
                root = x;
            }
        }
    }
    return 0;
}
