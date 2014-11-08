/* XVIII Championship of Ural
 * Problem E - Expression
 * by yxdb
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct foo {
	int v, x;
	bool operator<(const foo& rhs) const {
		return x < rhs.x;
	}
} a[100];

int n;
LL pre, cur;

void swap(char t, int u, int v) {
	cout << t << ' ' << u << ' ' << v << '\n';
	cout.flush();
	pre = cur;
	cin >> cur;
	u = (u - 1) * 2 + (t == 'O');
	v = (v - 1) * 2 + (t == 'O');
	swap(a[u], a[v]);
}

int value(char t, int u) {
	u = (u - 1) * 2 + (t == 'O');
	return a[u].v;
}

void assign(char t, int u, int v) {
	u = (u - 1) * 2 + (t == 'O');
	a[u].v = v;
}

int main() {
	cin >> n >> cur;
	for (int i = 0; i < n+n-1; ++i) a[i] = (foo){0, i};
	// find a '+' or '-' and put it at the last position
	swap('N', n-1, n);
	for (int i = 1; cur == pre && i < n-2; ++i) {
		swap('O', n-2, i);
		swap('N', n-1, n);
	}
	if (cur == pre) { // if last operator is  '*'
		swap('O', n-2, n-1);
		swap('N', n-1, n  );
		for (int i = 1; cur == pre && i < n-2; ++i) {
			swap('O', n-1, i);
			swap('N', n-1, n);
		}
	}
	// find a '-' and put it at the first position
	swap('O', n-1, 2);
	swap('N',   1, 2);
	for (int i = 3; cur == pre && i < n; ++i) {
		swap('O', 1, i);
		swap('N', 1, 2);
	}
	if (cur == pre) swap('O', 1, 2);
	// find all '+'
	swap('O', n-2, 1);
	swap('N', n-1, n);
	if (cur != pre) assign('O', n-1, '+');
	for (int i = 1; i < n-2; ++i) {
		swap('O', n-1, i);
		swap('N', n-1, n);
		if (cur != pre) assign('O', n-1, '+');
	}
	// find all '-'
	for (int i = 1; i < n; ++i) {
		if (value('O', i) == '+') {
			if (i != 2) swap('O', i, 2);
			break;
		}
	}
	swap('N', 1, 2);
	if (cur != pre) assign('O', 1, '-');
	for (int i = 3; i < n; ++i) {
		swap('O', i, 1);
		swap('N', 1, 2);
		if (cur != pre) assign('O', 1, '-');
	}
	// now all undetermined operators are '*'
	for (int i = 1; i < n; ++i) {
		if (!value('O', i)) assign('O', i, '*');
	}
	// determine all numbers now
	// find the one
	for (int i = 2; i < n; ++i) {
		if (value('O', i) == '-') {
			swap('O', 1, i);
			break;
		}
	}
	for (int i = 3; i < n; ++i) {
		if (value('O', i) == '+') {
			swap('O', 2, i);
			break;
		}
	}
	// keep the smaller number at the first position
	for (int i = 2; i <= n; ++i) {
		if (i != 2) swap('N', 2, i);
		swap('N', 1, 2);
		if (pre < cur) swap('N', 1, 2);
	}
	assign('N', 1, 1);
	for (int i = 2; i <= n; ++i) {
		if (i != 2) swap('N', 2, i);
		swap('N', 1, 2);
		assign('N', 1, (cur - pre) / 2 + 1);
		swap('N', 1, 2);
	}
	sort(a, a+n+n-1);
	cout << "A ";
	for (int i = 0; i < n+n-1; ++i) {
		if (i % 2) cout << (char)a[i].v;
		else cout << a[i].v;
	}
	cout << '\n';
	cout.flush();
}
