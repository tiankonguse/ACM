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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxc 1000100
#define maxn 100100
using namespace std;
int arr[maxn];
int c[maxn];
struct tree_node{
    int v, p;
    tree_node (int _v, int _p) { v = _v, p = _p; }
    tree_node () {}
    friend bool operator<(tree_node a, tree_node b){
        if (a.v == b.v) return a.p > b.p;
        else return a.v < b.v;
    }
}tree[maxc << 2], t0;

void build(int l, int r, int p) {
    if (l == r) {
        tree[p].v = 0;
        tree[p].p = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, 2*p);
    build(mid + 1, r, 2*p+1);
    tree[p] = max(tree[2*p], tree[2*p+1]);
}
void update(int l, int r, int a, int c, int d, int p){
    if(l == r){
        tree[p].v = c;
        tree[p].p = d;
        return;
    }
    int mid = (l + r) >> 1;
    if(a <= mid) update(l, mid, a, c, d, 2*p);
    else update(mid+1, r, a, c, d, 2*p+1);
    tree[p] = max(tree[2*p], tree[2*p+1]);
}

tree_node query(int l, int r, int a, int b, int p){
    if(l == a && r == b){
        return tree[p];
    }
    int mid = (l + r) >> 1;
    if(a > mid) return query(mid + 1, r, a, b, 2*p+1);
    else if(b <= mid) return query(l, mid, a, b, 2*p);
    else return max(query(l, mid, a, mid, 2*p), query(mid+1, r, mid+1, b, 2*p+1));
}

int dp[maxn];
int pre[maxn];
int list[maxn];

int main() {
    int n, mx;
    while (~scanf("%d", &n)) {
        mx = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            ++arr[i];
            mx = max(mx, arr[i]);
        }
        int cnt = 0;
        arr[0] = -1;
        for (int i = 1; i <= n; ++i) {
            if (arr[i] != arr[i - 1]) {
                arr[++cnt] = arr[i];
                c[cnt] = 1;
            }
            else ++c[cnt];
        }
        int ret = 0, rc;

        build(1, mx, 1);
        for (int i = 1; i <= cnt; ++i) {
            int a = arr[i];
            t0 = tree_node(0, 0);
            if (a - 2 >= 1  ) t0 = max(t0, query(1, mx, 1, a - 2, 1));
            if (a + 2 <= mx) t0 = max(t0, query(1, mx, a + 2, mx, 1));
            t0 = max(t0, query(1, mx, a, a, 1));
            dp[i] = t0.v + c[i];
            pre[i] = t0.p;
            update(1, mx, a, dp[i], i, 1);
            if (dp[i] > ret) {
                ret = dp[i];
                rc = i;
            }
        }

        printf("%d\n", n - ret);
        int top = 0;
        while (rc) {
            list[top++] = rc;
            rc = pre[rc];
        }
        int cc = 0;
        for (int i = top - 1; i >= 0; --i) {
            for (int j = 0; j < c[list[i]]; ++j) {
                ++cc;
                if (cc == ret) printf("%d\n", arr[list[i]] - 1);
                else printf("%d ", arr[list[i]] - 1);
            }
        }
    }
    return 0;
}
