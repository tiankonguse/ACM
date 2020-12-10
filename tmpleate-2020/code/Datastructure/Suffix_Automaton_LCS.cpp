/*
这是求解多串LCS的例程
使用时先调用init(), 再依次在线调用add就可以构建出对应串的后缀自动机(注意这是个在线过程)
每次add至多加入两个点
大致来说建成的后缀自动机有这么几个性质
1、对于任意一个给定串的后缀，在上面按顺序转移，最终一定会转移到last。所以任意一个子串在上面跑，不可能遇到null边
2、既然满足1，那么显然跑到某一个状态以后，后续可接收的串的集合必然一致。
3、val表示的是能从root转移到这个状态的最长串的长度
4、而能root转移到本状态的串的长度实际是在这个区间内[this->fa->val + 1, this->val]
5、this能接收的字符串的集合是fa对应的结点能接收的字符串的集合的子集。
6、不会存在状态p，this可接收的字符串集合是p可以接收的字符串集合的子集，而且p对应集合的势比fa的要小
*/

template <class T> void checkmin(T &t,T x){if (x < t) t = x;}
template <class T> void checkmax(T &t,T x){if (x > t) t = x;}
#define foreach(it,v) for (__typeof((v).begin()) it = (v).begin();it != (v).end();it++)
const int N = 250005;

struct Node {
	Node *ch[26], *fa;
	int val;
	int len[10];
	Node(): 
		val(0), fa(NULL) { 
		memset(ch, 0, sizeof(ch));
		memset(len, 0, sizeof(len));
	}
}pool[N * 2 + 5], *last, *root;
vector <Node *> vec[N];

namespace SAM {
	int cnt;

	void init() {
		if (cnt)
			for (int i = 0; i < cnt; i++)
				pool[i] = Node();
		cnt = 1;
		root = &pool[0];
		last = root;
	}

	void add(int c) {
		Node *p = last, *np = &pool[cnt++];
		last = np;
		np->val = p->val + 1;
		for  (; p && !p->ch[c]; p = p->fa)
			p->ch[c] = np;
		if (!p) {
			np->fa = root;
		} else {
			Node *q = p->ch[c];
			if (p->val + 1 == q->val) {
				 np->fa = q;
			} else {
				Node *nq = &pool[cnt++];
				*nq = *q;
				nq->val = p->val + 1;
				q->fa = nq;
				np->fa = nq;
				for (; p && p->ch[c] == q; p = p->fa)
					p->ch[c] = nq;
			}
		}
	}
}

int m, n;
char S[N], T[N];

int main(){
	SAM::init();
	scanf("%s", S);
	m = strlen(S);
	for (int i = 0; i < m; i++)
		SAM::add(S[i] - 'a');
	int k;
	for (k = 0; scanf("%s", T) != EOF; k++) {
		Node *p = root;
		int cnt = 0;
		n = strlen(T);
		for (int i = 0; i < n; i++) {
			int c = T[i] - 'a';
			if (p->ch[c]) {
				cnt++;
				p = p->ch[c];
			} else {
				for (; p && !p->ch[c]; p = p->fa);
				if (!p) {
					p = root;
					cnt = 0;
				} else {
					cnt = p->val + 1;
					p = p->ch[c];
				}
			}
			checkmax(p->len[k], cnt);
		}
	}
	for (int i = 0; i < SAM::cnt; i++) {
		vec[pool[i].val].push_back(&pool[i]);
	}
	int ans = 0;
	for (int i = m; i >= 0; i--) {
		foreach (it, vec[i]) {
			Node *p = *it;
			int now = p->val;
			for (int j = 0; j < k; j++) {
				checkmin(now, p->len[j]);
				if (p->fa) { 
					checkmax(p->fa->len[j], p->len[j]); 
				}
			}
			checkmax(ans, now);
		}
	}
	printf("%d\n", ans);
}
