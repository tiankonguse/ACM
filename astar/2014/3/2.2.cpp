#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;
const int maxn = 30000;
const int N=maxn;
const int M=maxn;
int fir[N],toV[M],len[M],next[M],cnt;

int val[maxn], left[maxn], right[maxn], posToId[maxn], idToPos[maxn], pre[maxn], sum[maxn];
int id;
int root;
int x,y;

void addedge(int u, int v, int w) {
    toV[cnt] = v;
    len[cnt] = w;
    next[cnt] = fir[u];
    fir[u] = cnt++;
}
void init() {
    memset(fir, -1, sizeof(fir));
    cnt=0;
}

void update(int x, int v){
	int add = v - val[x];
	val[x] = v;
	while(x!= -1){
		sum[x] += add;
		x = pre[x];
	}
}

void dfs(int now, int p) {
    left[now] = ++id;
    posToId[now] = id;
    idToPos[id] = now;
    pre[now] = p;
    sum[now] = val[now];

    for(int t=fir[now]; t!= -1; t = next[t]) {
        if(toV[t] == p)continue;
        dfs(toV[t], now);
        sum[now] += sum[toV[t]];
    }
    right[now] = id;
}

int query(int x) {
    int center = left[root];
    if(x == root){
		return sum[1];
    }
    if(center < left[x] || center > right[x])return sum[x];
    for(int t=fir[x]; t!= -1; t = next[t]) {
        if(toV[t] == pre[x])continue;
        if(center >= left[toV[t]] && center <= right[toV[t]]) {
            return sum[1] - sum[toV[t]];
        }
    }
    return 0;
}

int main() {
    int ca,cas,q;
    int u,v,i;
    char op[20];

    scanf("%d",&cas);
    for(ca=1; ca<=cas; ca++) {
        scanf("%d",&n);
        init();
        for (i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v, 0); // 不加下面的为有向图
            addedge(v, u, 0); // 加下面额为无向图
        }
        for(i=1; i<=n; i++) {
            scanf("%d",&val[i]);
        }
        id = 0;
        dfs(1,-1);

        root = 1;
        printf("Case #%d:\n", ca);
        scanf("%d",&q);
        while(q--) {
            scanf("%s",op);
            scanf("%d",&x);
            if(op[0]=='Q') {
                printf("%d\n", query(x));
            } else if(op[0]=='C') {
                scanf("%d",&y);
                update(x, y);
            } else {
                root = x;
            }
        }
    }
    return 0;
}
