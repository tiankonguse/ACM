#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 100005;
int n;
int id[N + N];
int a[N + N];
int where[N + N], color[N + N];
vector <int> E[N + N];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

void dfs(int u, int c) {
	if (color[u] == -1) {
		color[u] = c;
	} else {
		return;
	}
	for (int v : E[u]) {
		dfs(v, c ^ 1);
	}
}

int main() {
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d%d", &a[i * 2], &a[i * 2 + 1]);
		a[i * 2 + 1]++;
		id[i * 2] = i * 2;
		id[i * 2 + 1] = i * 2 + 1;
	}
	sort(id, id + n + n, cmp);
	rep (i, n + n) {
		where[id[i]] = i;
	}
	rep (i, n) {
		E[i * 2].push_back(i * 2 + 1);
		E[i * 2 + 1].push_back(i * 2);
		E[where[i * 2]].push_back(where[i * 2 + 1]);
		E[where[i * 2 + 1]].push_back(where[i * 2]);
	}
	//rep (i, n) printf("%d, ", id[i]);
	//puts("");
	memset(color, 0xff, sizeof(color));
	rep (i, n + n) {
		if (color[i] == -1) {
			dfs(i, 0);
		}
	}
	rep (i, n) {
		printf("%d ", color[where[i * 2]]);
	}
}
