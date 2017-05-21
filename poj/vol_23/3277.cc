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
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 80808
using namespace std;
typedef __int64 ll;
struct node {
    ll p, h;
    int t, id;
    node (ll _p, ll _h, int _t, int _id) { p = _p, h = _h, t = _t, id = _id; }
    node () {}
    friend bool operator < (node a, node b) {
        if (a.p == b.p) return a.t < b.t;
        else return a.p < b.p;
    }
} p[maxn];

struct h_node {
    ll h; int id;
    h_node (ll _h, int _id) { h = _h, id = _id; }
    h_node () {}
    friend bool operator < (h_node a, h_node b) {
        return a.h < b.h;
    }
}tmp;

priority_queue <h_node> q;
bool used[maxn];

int main() {
    int n;
    ll a, b, h;
    while (~scanf("%d", &n)) {
        int m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%I64d %I64d %I64d", &a, &b, &h);
            p[m++] = node(a, h, 0, i);
            p[m++] = node(b, h, 1, i);
        }
        sort(p, p + m);
        while (!q.empty()) q.pop();
        ll pre = p[0].p;
        memset(used, false, sizeof used);
        q.push(h_node(p[0].h, p[0].id));
        ll ret = 0;
        for (int i = 1; i < m; ++i) {
//            printf("%I64d --: %I64d\n", p[i].p, q.top().h);
            if (!q.empty()) ret += q.top().h * (p[i].p - pre);
//            cout << q.top().id << endl;
//            cout << ret << endl;
            pre = p[i].p;
            if (p[i].t == 1) {
//                printf("%d == true\n",p[i].id);
                used[ p[i].id ] = true;
            }
            else q.push( h_node( p[i].h, p[i].id ) );
            while (!q.empty()) {
                tmp = q.top();
                if (used[ tmp.id ]) q.pop();
                else break;
            }
        }
        printf("%I64d\n", ret);
    }
    return 0;
}
