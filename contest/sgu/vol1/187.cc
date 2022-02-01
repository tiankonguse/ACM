#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
typedef long long ll;
int const maxn = 130005;
struct node {
	int key, ch[2], pre, size; bool rev;
	void reverse() {
		if (size == 0) return;
		rev ^= 1;
		swap(ch[0], ch[1]);
	}
	void init(int v) {
		key = v;
		rev = 0;
		size = 1;
		pre = ch[0] = ch[1] = -1;
	}
} p[maxn];
void pushDown(int x) {
	if (p[x].rev) {
		if (~p[x].ch[0]) p[p[x].ch[0]].reverse();
		if (~p[x].ch[1]) p[p[x].ch[1]].reverse();
		p[x].rev = 0;
	}
}
void pushUp(int x) {
	p[x].size = p[p[x].ch[0]].size + p[p[x].ch[1]].size + 1;
}
int root, idx;

void init() {
	root = idx = 0;
	p[idx].init(inf); ++idx;
	p[idx].init(inf); ++idx;
	p[0].ch[1] = 1;
	p[1].pre = 0;
	pushUp(root);
}
int build(int l, int r) {
	if (l > r) return -1;
	int mid = (l + r) >> 1;
	int now = idx;
	p[idx++].init(mid);
	p[now].ch[0] = build(l, mid - 1);
	p[now].ch[1] = build(mid + 1, r);
	if (~p[now].ch[0]) p[p[now].ch[0]].pre = now;
	if (~p[now].ch[1]) p[p[now].ch[1]].pre = now;
	pushUp(now);
	return now;
}
void rotate(int x, int c) {
	int y = p[x].pre;
	pushDown(y);
	pushDown(x);
	p[y].ch[!c] = p[x].ch[c];
	if (~p[x].ch[c]) p[p[x].ch[c]].pre = y;
	p[x].pre = p[y].pre;
	if (~p[y].pre) p[p[y].pre].ch[y == p[p[y].pre].ch[1]] = x;
	p[x].ch[c] = y;
	p[y].pre = x;
	pushUp(y);
	if (y == root) root = x;
}
void splay(int x, int f) {
	pushDown(x);
	int y, z, c;
	while (p[x].pre != f) {
		if (p[p[x].pre].pre == f) {
			rotate(x, p[p[x].pre].ch[0] == x);
			break;
		}
		y = p[x].pre;
		z = p[y].pre;
		c = (y == p[z].ch[0]);
		if (p[y].ch[c] == x) {
			rotate(x, !c), rotate(x, c);
		}
		else {
			rotate(y, c), rotate(x, c);
		}
	}
	pushUp(x);
}
void select(int k, int x) {
	int now = root, tmp;
	while (1) {
		pushDown(now);
		tmp = p[p[now].ch[0]].size;
		if (tmp == k) break;
		else if (tmp < k) {
			k -= tmp + 1;
			now = p[now].ch[1];
		}
		else now = p[now].ch[0];
	}
	splay(now, x);
}
#define keytree p[p[root].ch[1]].ch[0]
void reverse(int a, int b) {
	select(a - 1, -1);
	select(b + 1, root);
	p[keytree].reverse();
	splay(keytree, -1);
}
int n, m, cc;
void vis(int x) {
	if (x == -1) return;
	pushDown(x);
	vis(p[x].ch[0]);
	++cc;
	if (cc == n + 1) {
		printf("%d\n", p[x].key);
		return;
	}
	else if (cc > 1 && cc < n + 1) printf("%d ", p[x].key);
	vis(p[x].ch[1]);
}
int main() {
	int a, b;
	scanf("%d%d", &n, &m);
	init();
	if (n > 0) {
		int tr = build(1, n);
		keytree = tr;
		p[tr].pre = p[root].ch[1];
		splay(tr, -1);
	}
	while (m--) {
		scanf("%d%d", &a, &b);
		reverse(a, b);
	}
	vis(root);
	return 0;
}
