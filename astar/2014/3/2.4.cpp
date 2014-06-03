#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

//1.bulid();2.query(a,b);3.update(a,b)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef int LL;
const int maxn = 30000;
LL min[maxn<<2],sum[maxn<<2], tmpVal[maxn<<2];
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

/* begin segment tree */
LL operateMin(LL a,LL b) {
    return a<b?a:b;//根据题意做相关修改,询问时的操作
}
LL operateSum(LL a,LL b) {
    return a+b;//根据题意做相关修改,询问时的操作
}


void PushUp(int rt) {
	min[rt]=operateMin(min[rt<<1],min[rt<<1|1]);
	sum[rt] = operateSum(sum[rt<<1], sum[rt<<1|1]);
}

void bulid(int l=1,int r=id,int rt=1) {
    if(l==r) { // 据题意做相关修改
        min[rt] = idToPos[l];
        sum[rt] = tmpVal[l];
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}

void update(int p,int add,int l=1,int r=id,int rt=1) {
    if(l==r) { // 据题意做相关修改
        sum[rt]=add;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,add,lson);
    else update(p,add,rson);
    PushUp(rt);
}

int queryMin(int L,int R,int l=1,int r=id,int rt=1) {
    if(L<=l && r<=R) {
        return min[rt];
    }
    int m=(l+r)>>1;
    int ret=id;
    if(L<=m)ret=operateMin(ret,queryMin(L,R,lson));
    if(R> m)ret=operateMin(ret,queryMin(L,R,rson));
    return ret;
}
int querySum(int L,int R,int l=1,int r=id,int rt=1) {
    if(L<=l && r<=R) {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ret=0;
    if(L<=m)ret=operateSum(ret,querySum(L,R,lson));
    if(R> m)ret=operateSum(ret,querySum(L,R,rson));
    return ret;
}

/* end segment tree */


void dfs(int now, int p) {
    left[now] = ++id;
    posToId[now] = id;
    idToPos[id] = now;
    pre[now] = p;
    tmpVal[id] = val[now];

    for(int t=fir[now]; t!= -1; t = next[t]) {
        if(toV[t] == p)continue;
		idToPos[++id] = now;
		tmpVal[id] = 0;
        dfs(toV[t], now);
    }
    right[now] = id;
}

/* begin op  */

int query(int x) {
    int center = left[root];
    // x is root
    if(x == root){
		return querySum(left[1], right[1]);
    }

    // root is same as 1.
    if(center < left[x] || center > right[x])return querySum(left[x], right[x]);

	int l = left[x] + 1, r = center - 1, mid;
	while(l < r){
		mid = (l + r)/2;
		if(queryMin(mid + 1, r) == x){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	int pos = idToPos[l+1];
	return querySum(left[1], right[1]) - querySum(left[pos], right[pos]);
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
                update(posToId[x], y);
            } else {
                root = x;
            }
        }
    }
    return 0;
}
