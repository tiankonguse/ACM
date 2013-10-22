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
	for(int i=head[u];i!=-1;i=edge[i].next){
		dfs(edge[i].v);
	}
	end[u] = idx-1;
}

void pushDown(int l,int r,int root){
    if(rev[root]){
        rev[root] = false;
        cnt[root] = r - l + 1 - cnt[root];
        rev[root<<1] = !rev[root<<1];
        rev[root<<1|1] = !rev[root<<1|1];
    }
}

void getNum(int l,int r,int root){
    if(l > r)return 0;
    return rev[root] ? r - l + 1 - cnt[root] : cnt[root];
}

void PushUp(int l,int r,int root){
    int m = (l+r)>>1;
    cnt[root] = getNum(l,m,root<<1) + getNum(m+1,r,root<<1|1);
}

//规定，当前节点标记，若标记为true，当前子树已更新，儿子未更新
void update(int b,int e,int l,int r,int root){
	if(b<=l&&r<=e){
		rev[root] = !rev[root];
		//cnt[root] = r - l + 1 - cnt[root];
		return ;
	}
	pushDown(l,r,root);

	int m = (l+r)>>1;
	if(b<=m)
		update(b,e,l,m,root<<1);
	if(m<e)
		update(b,e,m+1,r,root<<1|1);

    PushUp(l,r,root);
	//cnt[root] = cnt[root<<1] + cnt[root<<1|1];
}

int query(int b,int e,int l,int r,int root){

    if(l>r)return 0;

	if(b<=l&&r<=e){
		return cnt[root];
	}
	pushDown(l,r,root);

	int m = (l+r) >> 1;

	return query(b,e,l,m,root<<1) + query(b,e,m+1,r,root<<1|1);
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
		idx--;
//		printf("%d\n",idx);

//		for(int i=1;i<=n;i++)
//			printf("%d ",id[i]);
		fill(rev,rev+(n<<2),false);
		fill(cnt,cnt+(n<<2),0);
		char bf[12];
		for(int i=0;i<m;i++){
			scanf("%s%d",bf,&u);
			if(bf[0] == 'o'){
			//	printf("%d %d\n",begin[u],end[u]);
				update(begin[u],end[u],1,idx,1);
			}else{
				int ans = query(begin[u],end[u],1,idx,1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
// 3 2 1 1 o 2 q 1
/*
7 3
1 1 2 2 3 3
o 2
o 3
q 1

8 4
1 2 2 3 3 4 4
o 3
o 4
q 2

*/
