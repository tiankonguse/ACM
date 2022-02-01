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
int const N = 1010, M = 1013;
int c, m, n, ret;
char s[N][11];
int id[128], ans[128];

struct Trie_Node {
    int id; bool f;
    Trie_Node *next[26];
    void init() {
		f = 1;
		id = -1;
		clr(next, NULL);
    }
} trie[N * 15], root;
int tidx, cnt, t;
int insert(char* s) {
    int i, j;
    Trie_Node *p = &root;
    for (i = 0; s[i]; ++i) {
        j = id[s[i]];
        if (p -> next[j] == NULL) {
            trie[tidx].init();
            p -> next[j] = &trie[tidx++];
        }
        p = p -> next[j];
    }
    if (p -> id == -1) ++t, p -> id = cnt++;
	else if (p -> f) --t, p -> f = 0;
    return p -> id;
}
void init() {
    root.init();
    tidx = cnt = 0;
}


void dfs(int cur, int idx) {
	if (cur == m - 1) {
		for (int i = idx; i < n; ++i) id[i + 'A'] = cur + 1;
		init();
		t = 0;
		rep(i, c) {
			if (t + c - i < ret) break;
			insert(s[i]);
		}
		if (t >= ret) {
			ret = t;
			rep(i, n) ans[i] = id[i + 'A'];
		}
		return;
	}
	for (int i = 0; n - idx - i >= m - cur; ++i) {
		id[idx + i + 'A'] = cur + 1;
		dfs(cur + 1, idx + i + 1);
	}
}
int main() {
	scanf("%d%d%d", &m, &n, &c);
	rep(i, c) scanf(" %s", s[i]);
	dfs(0, 0);
	printf("%d\n", ret);
	Rep(i, m) {
		rep(j, n) if (ans[j] == i) putchar(j + 'A');
		puts("");
	}
	return 0;
}

