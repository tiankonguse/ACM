//1.bulid();2.query(a,b)；3.update(a,b)

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef long long LL;
const int maxn = 100055;
LL sign[maxn<<2];//标记
LL sum[maxn<<2];
int n;
LL operate(LL a,LL b){
	return a+b;//根据题意做相关修改，询问时的操作 
}
void PushUp(int rt){
	sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void PushDown(int rt,int m) {
	if (sign[rt]) {
		sign[rt<<1]   += sign[rt];
		sign[rt<<1|1] += sign[rt];
		sum[rt<<1] += (m - (m >> 1)) * sign[rt];
		sum[rt<<1|1] += (m >> 1) * sign[rt];
		sign[rt] = 0;
	}
}
void bulid(int l=1,int r=n,int rt=1){
	sign[rt] = 0;
	if(l==r){// 据题意做相关修改
		scanf("%lld",&sum[rt]);return ;
	}
	int m=(l+r)>>1;
	bulid(lson);
	bulid(rson);
	PushUp(rt);
}
void update(int L,int R,int add,int l=1,int r=n,int rt=1){
	if(L<=l && r<=R){// 据题意做相关修改
		sign[rt]+=add;
		sum[rt]+=(LL)add*(r-l+1);return ;
	}
	PushDown(rt,r-l+1);
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , add , lson);
	if (R > m) update(L , R , add , rson);
	PushUp(rt);
}

LL query(int L,int R,int l=1,int r=n,int rt=1) {
	if (L <= l && r <= R) {
		return sum[rt];
	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	LL ret = 0;
	if (L <= m) ret += query(L , R , lson);
	if (m < R) ret += query(L , R , rson);
	return ret;
}
