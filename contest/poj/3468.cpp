#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;

//1.bulid();2.query(a,b)；3.update(a,b,k)
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

const int maxn = 100055;
LL sign[maxn<<2];//标记
LL sum[maxn<<2];
int n,h,m;

void PushDown(int rt) {
    for (int i=h,p; i; i--) {
        if (sign[p=rt>>i]) { // 自顶向下下放标记
            sign[p]>>=1;//b[p]为节点增加总量，子节点增加一半
            sum[p<<1]+=sign[p];
            sum[p<<1|1]+=sign[p];
            sign[p<<1]+=sign[p];
            sign[p<<1|1]+=sign[p];
            sign[p]=0;
        }
    }
}



void bulid() {
    for (m=1,h=0; m-2<n; m+=m,h++); //h为树的高度，根高度为0

    for (int i=1,j=m+1; i<=n; i++,j++) {
        scanf("%lld",&sum[j]);
        sign[j] = 0;
    }
    for (int i=m-1; i; i--) { //建树
        sum[i]=sum[i<<1]+sum[i*2+1];
        sign[i] = 0;
    }
}

void update(int l,int r, int k) {
    int ll,rr;
    PushDown(l += m-1);
    PushDown(r += m+1);
    ll=l>>1;
    rr=r>>1;

    for (; l^r^1; l>>=1,r>>=1,k<<=1) { //k为当前层每个节点需增加的数
        if (~l&1) sum[l^1]+=k,sign[l^1]+=k;//r是左儿子
        if (r&1) sum[r^1]+=k,sign[r^1]+=k;//r是右儿子
    }
    for (int i=ll; i; i>>=1) sum[i]=sum[i<<1]+sum[i*2+1]; //向上更新
    for (int i=rr; i; i>>=1) sum[i]=sum[i<<1]+sum[i*2+1];
}



LL query(int l,int r) {
    LL ans = 0;
    PushDown(l += m-1);
    PushDown(r += m+1);
    for (; l^r^1; l>>=1,r>>=1) {//判断l和r是不是左右儿子
        if (~l&1) ans+=sum[l^1];
        if (r&1) ans+=sum[r^1];
    }
    return ans;
}


int main() {
	int q,c,l,r;
	char op[3];
	while(~scanf("%d%d",&n,&q)){
		bulid();
		while(q--){
			scanf("%s",op);
			if(op[0] == 'Q'){
				scanf("%d%d",&l,&r);
				printf("%lld\n",query(l,r));
			}else{
				scanf("%d%d%d",&l,&r,&c);
				update(l,r,c);
			}
		}
	}

    return 0;
}
