#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 30
using namespace std;
vector<char> v0[1010];

struct node {
    int v, id, e;
    node (int _v, int _id, int _e) { v = _v, id = _id, e = _e; }
    node () {}
    friend bool operator<(node a, node b) {
        if (a.v == b.v) return a.e > b.e;
        else return a.v > b.v;
    }
}tmp;
priority_queue<node> q;

vector<node> tree[501];

int n, m, R;
vector<int> res[maxn];

int lst[maxn];
int ret;

void dfs(int u, int d) {
    int sz = tree[u].size();
    for (int i = 0; i < sz; ++i) {
        if (tree[u][i].id >= 0 && tree[u][i].id < m) {
            if (tree[u][i].id < n) {
                ret += tree[u][i].v * (d + 1);
                for (int j = 0; j < d; ++j) {
                    res[ tree[u][i].id ].push_back(lst[j]);
                }
                res[ tree[u][i].id ].push_back(i);
            }
        }
        else {
            lst[d] = i;
            dfs(tree[u][i].id, d + 1);
        }
    }

}


int main() {
    int _ca = 1;
    while (scanf("%d", &R) && R) {
        for (int i = 0; i < 1000; ++i) v0[i].clear();

        scanf("%d", &n);
        char ch = 'A';
        int f, sum = 0;
        while (!q.empty()) q.pop();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &f);
            sum += f;
            q.push(node(f, i, i));
        }

        int need = ((R - 1) - (n - 1) % (R - 1)) % (R - 1);
        m = n + need;

        for (int i = 0; i < need; ++i) q.push( node(0, n + i, inf) );
        for (int i = 0; i < 501; ++i) tree[i].clear();

        int now = 500;
        while (q.size() > 1) {
            int vs = 0;
            int mi = inf;
            for (int i = 0; i < R; ++i) {
                tmp = q.top(); q.pop();
                vs += tmp.v;
                mi = min(mi, tmp.e);
                tree[now].push_back(tmp);
            }
            q.push( node(vs, now, mi) );
            --now;
        }
        int root = now + 1;
        ret = 0;
        for (int i = 0; i < n; ++i) res[i].clear();
        dfs(root, 0);
        printf("Set %d; average length %.2lf\n", _ca++, 1.0 * ret / sum);
        for (int i = 0; i < n; ++i) {
            printf("    %c: ", 'A' + i);
            for (int j = 0; j < res[i].size(); ++j) printf("%d", res[i][j]);
            puts("");
        }
        puts("");
    }
    return 0;
}
