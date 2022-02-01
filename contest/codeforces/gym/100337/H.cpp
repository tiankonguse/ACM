#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef pair <int, int> PII;
const int N = 60005;
const int M = 200100;
int n;
vector <int> cx;
struct Matrix {
    int x0, y0, x1, y1, id;
    void read() {
        scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    }
}a[N];

struct Node {
    int fix, idx;
    PII v, maxv;
    Node *ch[2];

    void update() {
        maxv = v;
        rep (o, 2)
            if (ch[o]) maxv = max(maxv, ch[o]->maxv);
    }
}pool[N * 20], *C;

struct SegTreeNode {
    int l, r;
    Node *root;
}Tr[N * 4];

bool cmp(const Matrix &a, const Matrix &b) {
    return a.x0 < b.x0;
}

void build(int p, int l, int r) {
    Tr[p].l = l;
    Tr[p].r = r;
    Tr[p].root = NULL;
    if (l + 1 != r) {
        int mid = (l + r) / 2;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid, r);
    }
}

Node *newNode(int idx, PII v) {
    C->fix = rand();
    C->idx = idx;
    C->v = C->maxv = v;
    C->ch[0] = C->ch[1] = NULL;
    return C++;
}

void rot(Node *&p, int o) {
    Node *q = p->ch[o];
    p->ch[o] = q->ch[!o];
    q->ch[!o] = p;
    p->update();
    q->update();
    p = q;
}

void add(Node *&p, int i, PII v) {
    if (!p) {
        p = newNode(i, v);
    } else if (p->idx == i) {
        p->v = max(p->v, v);
        p->update();
    } else {
        bool o = i > p->idx;
        add(p->ch[o], i, v);
        p->update();
        if (p->ch[o]->fix < p->fix)
            rot(p, o);
    }
}

PII get(Node *p, int i) {
    if (!p) {
        return PII((int)-1e9, 0);
    } else if (p->idx <= i) {
        PII res = p->v;
        if (p->ch[0]) res = max(res, p->ch[0]->maxv);
        res = max(res, get(p->ch[1], i));
        return res;
    } else {
        return get(p->ch[0], i);
    }
}

void ins(int p, int idx, int y0, int y1, int id) {
    add(Tr[p].root, y0, PII(y1, id));
    if (Tr[p].l + 1 == Tr[p].r) return;
    int mid = (Tr[p].l + Tr[p].r) / 2;
    if (idx < mid) {
        ins(p * 2, idx, y0, y1, id);
    } else {
        ins(p * 2 + 1, idx, y0, y1, id);
    }
}

PII query(int p, int limx, int limy) {
    if (Tr[p].l > limx) return PII((int)-1e9, 0);
    if (Tr[p].r - 1 <= limx) {
        return get(Tr[p].root, limy);
    }
    if (Tr[p].l + 1 >= Tr[p].r) return PII((int)-1e9, 0);
    PII res = max(query(p * 2, limx, limy), query(p * 2 + 1, limx, limy));
    return res;
}

PII check(int lim) {
    C = pool;
    vector <Matrix> b;
    rep (i, n) {
        if (a[i].x1 - a[i].x0 >= lim && a[i].y1 - a[i].y0 >= lim) {
            b.push_back(a[i]);
        }
    }
    int m = b.size();
    build(1, 0, cx.size());
    for (int i = m - 1; i >= 0; i--) {
        int limx = lower_bound(cx.begin(), cx.end(), b[i].x1 - lim + 1) - cx.begin(); // >= is bad
        PII res = query(1, limx - 1, b[i].y1 - lim);
        if (res.first >= b[i].y0 + lim) {
            return PII(b[i].id, res.second);
        }
        ins(1, lower_bound(cx.begin(), cx.end(), b[i].x0) - cx.begin(), b[i].y0, b[i].y1, b[i].id);
    }
    return PII(-1, -1);
}

int main() {
    srand(199355);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    rep (i, n) {
        a[i].read();
        cx.push_back(a[i].x0);
    }
    sort(cx.begin(), cx.end());
    cx.erase(unique(cx.begin(), cx.end()), cx.end());
    sort(a, a + n, cmp);
    rep (i, n) a[i].id = i;
    int l = 0, r = 200000;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        PII res = check(mid);
        if (res.first == -1) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    if (l == 0) {
        puts("Impossible");
    } else {
        PII ans = check(l);
        double mx, my, d = l * 0.5;
        int i = ans.first;
        int j = ans.second;
        mx = (max(a[i].x0, a[j].x0) + min(a[i].x1, a[j].x1)) * 0.5;
        my = (max(a[i].y0, a[j].y0) + min(a[i].y1, a[j].y1)) * 0.5;
        printf("%.1f %.1f %.1f\n", mx, my, d);
    }
}
/*
4
0 0 2 3
1 -1 4 1
1 1 4 4
2 0 5 5

1
0 0 1 1

2
0 0 3 3
0 0 3 3
 */