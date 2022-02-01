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
#define maxn 1010
using namespace std;

int n;
struct node {
    double _x1, _x2, y1, y2;
    int x1, x2;
} rec[maxn];

double xpos[maxn];

int find1(int l, int r, double x){ // a[res] <= x
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(xpos[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

struct lines{
    int l, r, flag;
    double h;
    friend bool operator<(lines a, lines b){
        if(a.h == b.h) return a.flag < b.flag;
        else return a.h < b.h;
    }
}line[maxn];

struct tree_node{
    int cnt;
    double s;
}tree[maxn * 4];

void build(int l, int r, int p){
    if(l == r){
        tree[p].cnt = 0;
        tree[p].s = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, 2*p);
    build(mid+1, r, 2*p+1);
    tree[p].cnt = 0;
    tree[p].s = 0;
}
void node_update(int l, int r, int p, int lp, int rp){
    if(tree[p].cnt >= 1) tree[p].s = xpos[r] - xpos[l - 1];
    else if(l == r) tree[p].s = 0;
    else tree[p].s = tree[lp].s + tree[rp].s;
}
void update(int l, int r, int a, int b, int c, int p){
    int mid = (l + r) >> 1, lp = 2*p, rp = 2*p+1;
    if(l == a && r == b){
        tree[p].cnt += c;
        node_update(l, r, p, lp, rp);
        return;
    }
    if(b <= mid) update(l, mid, a, b, c, lp);
    else if(a > mid) update(mid+1, r, a, b, c, rp);
    else{
        update(l, mid, a, mid, c, lp);
        update(mid+1, r, mid+1, b, c, rp);
    }
    node_update(l, r, p, lp, rp);
}

int main() {
    int _ca = 1;
    while (scanf("%d", &n) && n) {
        int xnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf(" %lf %lf %lf %lf", &rec[i]._x1, &rec[i].y1, &rec[i]._x2, &rec[i].y2);
            xpos[xnt++] = rec[i]._x1, xpos[xnt++] = rec[i]._x2;
        }
        sort(xpos, xpos + xnt);
        int cnt = 1;
        for (int i = 1; i < xnt; ++i) {
            if (xpos[i] != xpos[i - 1]) {
                xpos[cnt++] = xpos[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            rec[i].x1 = find1(0, cnt - 1, rec[i]._x1) + 1;
            rec[i].x2 = find1(0, cnt - 1, rec[i]._x2) + 1;
        }
        int x1, x2; double y1, y2;
        int N = n << 1;
        for (int i = 0; i < N; i += 2) {
            x1 = rec[i >> 1].x1;
            x2 = rec[i >> 1].x2;
            y1 = rec[i >> 1].y1;
            y2 = rec[i >> 1].y2;
            line[i].l = x1, line[i].r = x2, line[i].h = y1, line[i].flag = 1;
            line[i+1].l = x1, line[i+1].r = x2, line[i+1].h = y2, line[i+1].flag = -1;
        }
        sort(line, line + N);
        build(1, cnt, 1);
        int a, b, c;
        double ret = 0;
        for (int i = 0;i < N - 1; ++i) {
            a = line[i].l;
            b = line[i].r - 1;
            c = line[i].flag;
            update(1, cnt, a, b, c, 1);
            ret += tree[1].s * (line[i + 1].h - line[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", _ca++, ret);

    }
    return 0;
}
