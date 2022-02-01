/*
    Author : zzugzx
    Lang : C++
    Blog : blog.csdn.net/qq_43756519
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define SZ(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
//const int mod = 998244353;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int N = 1e2 + 10;
const ll inf = 0x3f3f3f3f;
const ll oo = 8e18;
const int dir[][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
ll c[maxn], n, m;
ll a[maxn], b[maxn];
int lowbit(int x)
{
	return x&(-x);
}
ll query(int x)
{
	ll s=0;
	while(x>0)
	{
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void add(int x,ll v)
{
	while(x<=n)
	{
		c[x]+=v;
		x+=lowbit(x);
	}
}
//维护最大值
struct node{
	int l,r;
	ll val,add;
}t[maxn];
void build(int p,int l,int r){//区间编号p
	t[p].l = l; t[p].r = r; t[p].add = 0;
	if(l==r){//叶子结点直接赋值
		t[p].val = a[l] - query(l);
		return ;
	}
	int mid = l+r >>1;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	t[p].val = max(t[p*2].val,t[p*2+1].val);//维护区间和
}
void spread(int x)
{
    if(t[x].add){
        t[2*x].val+=t[x].add;
        t[2*x+1].val+=t[x].add;
        t[2*x].add+=t[x].add;
        t[2*x+1].add+=t[x].add;
        t[x].add=0;
    }
}
void update(int x,int l,int r,ll add)
{
	if(l>r) return;
    if(t[x].l>=l&&t[x].r<=r){
        t[x].val+=add;
        t[x].add+=add;
        return;
    }
    spread(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid) update(2*x,l,r,add);
    if(r>mid) update(2*x+1,l,r,add);
    t[x].val=max(t[2*x].val,t[2*x+1].val);
}
ll qry(int p,int l,int r){
	if(l<=t[p].l&&r>=t[p].r){//被覆盖 返回值
		return t[p].val;
	}
	spread(p);
	ll ans = 0;
	int mid = t[p].r+t[p].l>>1;
	if(l<=mid)ans=max(ans,qry(p*2,l,r));
	if(r>mid)ans=max(ans,qry(p*2+1,l,r));
	return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            c[i] = 0;
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            add(i, b[i]);
        }
        if (query(0) != 0 || a[0] != 0) cout << "111";
        build(1, 0, n);
        while (m--) {
            int op;
            cin >> op;
            if (op == 1) {
                int x, y;
                cin >> x >> y;
                update(1, x, x, y - a[x]);
                a[x] = y;
            }
            else if (op == 2) {
                int x, y;
                cin >> x >> y;
                add(x, y - b[x]);
                update(1, x, n, -y + b[x]);
                b[x] = y;
            }
            else {
                int x;
                cin >> x;
                cout << max(a[x], query(x) + qry(1, 0, x)) << endl;
            }
        }
    }
    return 0;
}


