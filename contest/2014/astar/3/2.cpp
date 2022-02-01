#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

//1.bulid();2.query(a,b);3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef int LL;
const int maxn = 21000;
LL sum[maxn<<2];
int n;

const int N=maxn;
const int M=maxn;
int fir[N],toV[M],len[M],next[M],cnt;

int val[maxn], left[maxn], right[maxn], posToId[maxn], idToPos[maxn], pre[maxn];
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

LL operate(LL a,LL b) {
    return a+b;//根据题意做相关修改,询问时的操作
}
void PushUp(int rt) {
    sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}

void bulid(int l=1,int r=n,int rt=1) {
    if(l==r) { // 据题意做相关修改
        sum[rt] = val[idToPos[l]];
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}

void update(int p,int add,int l=1,int r=n,int rt=1) {
    if(l==r) { // 据题意做相关修改
        sum[rt]=add;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,add,lson);
    else update(p,add,rson);
    PushUp(rt);
}


int query(int L,int R,int l=1,int r=n,int rt=1) {
    if(L<=l && r<=R) {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret=operate(ret,query(L,R,lson));
    if(R> m)ret=operate(ret,query(L,R,rson));
    return ret;
}


void dfs(int now, int p) {
    left[now] = ++id;
    posToId[now] = id;
    idToPos[id] = now;
    pre[now] = p;

    for(int t=fir[now]; t!= -1; t = next[t]) {
        if(toV[t] == p)continue;
        dfs(toV[t], now);
    }
    right[now] = id;
}

int query(int x) {
    int center = left[root];
    if(x == root){
		return query(1,n);
    }
    if(center < left[x] || center > right[x])return query(left[x],right[x]);
    for(int t=fir[x]; t!= -1; t = next[t]) {
        if(toV[t] == pre[x])continue;
        if(center >= left[toV[t]] && center <= right[toV[t]]) {
            return query(1,n) - query(left[toV[t]],right[toV[t]]);
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
//        puts("");
//        for(i=1; i<=n; i++) {
//			printf("pos=%d id=%d l=%d r=%d p=%d\n",i, posToId[i], left[i], right[i], pre[i]);
//        }
//        puts("");
        bulid();

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
                update(posToId[x], y);
            } else {
                root = x;
            }
        }



    }
    return 0;
}
