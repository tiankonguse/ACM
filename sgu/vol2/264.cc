#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 801;
int const M = 11;
struct Trie_Node {
	int id;
	Trie_Node *next[52];
	void init() {
		id = -1;
		memset(next, 0, sizeof next);
	}
} trie[N * M], root;
int tidx, cnt;
int insert(char* s) {
	int i, j;
	Trie_Node *p = &root;
	for (i = 0; s[i]; ++i) {
		if (s[i] <= 'Z') j = s[i] - 'A';
		else j = s[i] - 'a' + 26;
		if (p -> next[j] == NULL) {
			trie[tidx].init();
			p -> next[j] = &trie[tidx++];
		}
		p = p -> next[j];
	}
	if (p -> id == -1) p -> id = cnt++;
	return p -> id;
}

void init() {
	root.init();
	tidx = cnt = 0;
}

char s[N*2][N][11];
int wp[N][N];
int mg[N][N];
int mm[N], mw[N];
int stack[N], top;
int cc[N];
bool vis[N][N];

int main() {
	int n; scanf("%d", &n);
	init();
	rep(i, n * 2) {
		rep(j, n + 1) {
			scanf(" %s", s[i][j]);
		}
		insert(s[i][0]);
	}
	rep(i, n) {
		Rep(j, n) {
			int t = insert(s[i][j]);
			mg[i][j - 1] = t - n;
		}
	}
	for (int i = n; i < n + n; ++i) {
		Rep(j, n) {
			int t = insert(s[i][j]);
			wp[i - n][t] = j;
		}
	}
	clr(mm, 0xff), clr(mw, 0xff);
	rep(i, n) stack[++top] = i;
	while (top > 0) {
		int m = stack[top--];
		int w = 0;
		while (vis[m][w]) ++w;
		vis[m][w] = 1;
		w = mg[m][w];
		if (mw[w] == -1) {
			mw[w] = m;
		} else {
			int m1 = mw[w];
			if (wp[w][m1] < wp[w][m]) {
				stack[++top] = m;
			}
			else {
				mw[w] = m;
				stack[++top] = m1;
			}
		}
	}
	puts("YES");
	rep(i, n) {
		printf("%s %s\n", s[mw[i]][0], s[i + n][0]);
	}
	return 0;
}

