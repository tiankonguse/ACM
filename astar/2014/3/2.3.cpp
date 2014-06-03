#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

//1.bulid();2.query(a,b);3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef int LL;
const int maxn = 30000;
LL min[maxn<<2],num[maxn<<2];
int n;

const int N=maxn;
const int M=maxn;
int fir[N],toV[M],len[M],next[M],cnt;

int val[maxn], left[maxn], right[maxn], posToId[maxn], idToPos[maxn], pre[maxn],sum[maxn];
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

/* begin segment tree */
LL operate(LL a,LL b) {
    return a<b?a:b;//根据题意做相关修改,询问时的操作
}

void PushUp(int rt) {
	min[rt]=operate(min[rt<<1],min[rt<<1|1]);
}

void bulid(int l=1,int r=id,int rt=1) {
    if(l==r) { // 据题意做相关修改
        min[rt] = idToPos[l];
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}


int query(int L,int R,int l=1,int r=id,int rt=1) {
    if(L<=l && r<=R) {
        return min[rt];
    }
    int m=(l+r)>>1;
    int ret=id;
    if(L<=m)ret=operate(ret,query(L,R,lson));
    if(R> m)ret=operate(ret,query(L,R,rson));
    return ret;
}
/* end segment tree */


void dfs(int now, int p) {
    left[now] = ++id;
    posToId[now] = id;
    idToPos[id] = now;
    pre[now] = p;
    sum[now] = val[now];

    for(int t=fir[now]; t!= -1; t = next[t]) {
        if(toV[t] == p)continue;
		idToPos[++id] = now;
        dfs(toV[t], now);
        sum[now] += sum[toV[t]];
    }
    right[now] = id;
}

/* begin op  */
void update(int x, int v){
	int add = v - val[x];
	val[x] = v;
	while(x!= -1){
		sum[x] += add;
		x = pre[x];
	}
}

int query(int x) {
    int center = left[root];
    // x is root
    if(x == root){
		return sum[1];
    }

    // root is same as 1.
    if(center < left[x] || center > right[x])return sum[x];

	int l = left[x] + 1, r = center - 1, mid;
	while(l < r){
		mid = (l + r)/2;
		if(query(mid + 1, r) == x){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	return sum[1] - sum[idToPos[l+1]];
}
/* end op  */

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
                update(x, y);
            } else {
                root = x;
            }
        }
    }
    return 0;
}
