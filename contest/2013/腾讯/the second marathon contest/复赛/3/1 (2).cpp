#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110000;

struct Edge {
    int v, next;
};

bool boo[maxn<<2], rev[maxn<<2],pure[maxn<<2];
int cnt[maxn<<2];
int begin[maxn], end[maxn],id[maxn];
int n, m,idx;
Edge edge[maxn];
int head[maxn], ec;

void addedge(int u, int v) {
    edge[ec].v = v;
    edge[ec].next = head[u];
    head[u] = ec++;
}

void dfs(int u) {
    begin[u] = id[u] = idx++;
    for(int i=head[u]; i!=-1; i=edge[i].next) {
        dfs(edge[i].v);
    }
    end[u] = idx-1;
}

void pushDown(int l,int r,int root) {
    rev[root] = false;
    if(l == r)return ;
    rev[root<<1] = !rev[root<<1];
    rev[root<<1|1] = !rev[root<<1|1];
    int m = (l+r)>>1;
    cnt[root<<1] = m - l + 1 - cnt[root<<1];
    cnt[root<<1|1] = r - m - cnt[root<<1|1];

}

void update(int b,int e,int l,int r,int root) {
    if(b<=l&&r<=e) {
        rev[root] = !rev[root];
        cnt[root] = r - l + 1 - cnt[root];
        return ;
    }
    if(rev[root]) {
        pushDown(l,r,root);
    }
    int m = (l+r)>>1;
    if(b<=m)
        update(b,e,l,m,root<<1);
    if(m<e)
        update(b,e,m+1,r,root<<1|1);
    cnt[root] = cnt[root<<1] + cnt[root<<1|1];
}

int query(int b,int e,int l,int r,int root) {
    if(b<=l&&r<=e) {
        if(rev[root]) {
            pushDown(l,r,root);
        }
        return cnt[root];
    }
    if(rev[root]) {
        pushDown(l,r,root);
    }
    int m = (l+r) >> 1,ret = 0;
    if(b<=m) {
        ret += query(b,e,l,m,root<<1);
    }
    if(m<e) {
        ret += query(b,e,m+1,r,root<<1|1);
    }
    return ret;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        int u;
        ec = 0;
        fill(head,head+n+1,-1);
        for(int i = 2; i <= n; i++) {
            scanf("%d",&u);
            addedge(u,i);
        }
        idx = 1;
        dfs(1);
//	 for(int i=1;i<=n;i++)
//	 printf("%d ",id[i]);
        fill(rev,rev+(n<<2),false);
        fill(cnt,cnt+(n<<2),0);
        char bf[12];
        for(int i=0; i<m; i++) {
            scanf("%s%d",bf,&u);
            if(bf[0] == 'o') {
//	printf("%d %d\n",begin[u],end[u]);
                update(begin[u],end[u],1,idx,1);
            } else {
                int ans = query(begin[u],end[u],1,idx,1);
                printf("%d\n",ans);
            }

        } printf("\n");
    }
    return 0;
}
// 3 2 1 1 o 2 q 1
/*
3 6
1 1
o 2
q 2
o 2
q 2
o 2
q 2
*/
