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

#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 200100

using namespace std;
typedef __int64 ll;

struct nodeH {
    int t, id;
    ll y, x1, x2;
    int id_y, id_x1, id_x2;
    nodeH (int _id, int _t, ll _y, ll _x1, ll _x2) { id = _id, t = _t, y = _y, x1 = _x1, x2 = _x2; }
    nodeH () {}
    friend bool operator < (nodeH a, nodeH b) {
        if (a.y == b.y) return a.x1 < b.x1;
        else return a.y < b.y;
    }
    void print(int i) {
        printf("p1[%d]: ", i);
        printf("t = %d, id = %d, y = %d, x1 = %d, x2 = %d\n", t, id, y, x1, x2);
        printf("id_y = %d, id_x1 = %d, id_x2 = %d\n", id_y, id_x1, id_x2);
    }
} p1[maxn];

struct nodeV {
    int t, id;
    ll x, y1, y2;
    int id_x, id_y1, id_y2;
    nodeV (int _id, int _t, ll _x, ll _y1, ll _y2) { id = _id, t = _t, x = _x, y1 = _y1, y2 = _y2; }
    nodeV () {}
    friend bool operator < (nodeV a, nodeV b) {
        if (a.x == b.x) return a.y1 < b.y1;
        else return a.x < b.x;
    }
    void print(int i) {
        printf("p2[%d]: ", i);
        printf("t = %d, id = %d, x = %d, y1 = %d, y2 = %d\n", t, id, x, y1, y2);
        printf("id_x = %d, id_y1 = %d, id_y2 = %d\n", id_x, id_y1, id_y2);
    }
} p2[maxn];

ll xpos[maxn << 1], ypos[maxn << 1];

int findX(int l, int r, ll x) {
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (xpos[mid] == x) return mid + 1;
        else if (xpos[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int findY(int l, int r, ll y) {
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (ypos[mid] == y) return mid + 1;
        else if (ypos[mid] < y) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}


int tree[maxn << 2];
void update(int l, int r, int a, int b, int c, int p) {
    if (l == a && r == b) {
        tree[p] = c;
        return;
    }
    int mid = (l + r) >> 1, lp = p << 1, rp = p << 1 | 1;
    if (tree[p] != -2) {
        tree[lp] = tree[rp] = tree[p];
        tree[p] = -2;
    }
    if (b <= mid) update(l, mid, a, b, c, lp);
    else if (a > mid) update(mid + 1, r, a, b, c, rp);
    else {
        update(l, mid, a, mid, c, lp);
        update(mid + 1, r, mid + 1, b, c, rp);
    }

}
int query(int l, int r, int a, int p) {
    if (tree[p] != -2) return tree[p];
    int mid = (l + r) >> 1, lp = p << 1, rp = p << 1 | 1;
    if (a <= mid) return query(l, mid, a, lp);
    else return query(mid + 1, r, a, rp);
}

ll minDis[maxn]; int minPos[maxn];
ll tDis[maxn]; int tPos[maxn];

ll asn[maxn];

int ret[maxn];

int main() {
    int n, m;
    int _c1, _c2, xnt, ynt, hLen, vLen;
    ll x1, y1, x2, y2, x, y;
    int ans; ll dit;

    while (~scanf("%d%d", &n, &m)) {
        _c1 = _c2 = xnt = ynt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            xpos[xnt++] = x1, xpos[xnt++] = x2;
            ypos[ynt++] = y1, ypos[ynt++] = y2;
            if (y1 == y2) {
                p1[_c1++] = nodeH(i, 1, y1, x1, x2);
            }
            else {
                p2[_c2++] = nodeV(i, 1, x1, y1, y2);
            }
        }
        for (int i = 0; i < m; ++i) {
            scanf("%I64d%I64d", &x, &y);
            xpos[xnt++] = x, ypos[ynt++] = y;
            p1[_c1++] = nodeH(i, 0, y, x, x);
            p2[_c2++] = nodeV(i, 0, x, y, y);
        }
        sort(xpos, xpos + xnt);
        hLen = 1;
        for (int i = 1; i < xnt; ++i) {
            if (xpos[i] != xpos[i - 1]) xpos[hLen++] = xpos[i];
        }
        sort(ypos, ypos + ynt);
        vLen = 1;
        for (int i = 1; i < ynt; ++i) {
            if (ypos[i] != ypos[i - 1]) ypos[vLen++] = ypos[i];
        }

        for (int i = 0; i < _c1; ++i) {
            p1[i].id_x1 = findX(0, hLen - 1, p1[i].x1);
            p1[i].id_x2 = findX(0, hLen - 1, p1[i].x2);
            p1[i].id_y = findY(0, vLen - 1, p1[i].y);
        }

        for (int i = 0; i < _c2; ++i) {
            p2[i].id_y1 = findY(0, vLen - 1, p2[i].y1);
            p2[i].id_y2 = findY(0, vLen - 1, p2[i].y2);
            p2[i].id_x = findX(0, hLen - 1, p2[i].x);
        }

        sort(p1, p1 + _c1);
        sort(p2, p2 + _c2);

//        for (int i = 0; i < _c1; ++i) {
//            p1[i].print(i); puts("");
//        }
//        for (int i = 0; i < _c2; ++i) {
//            p2[i].print(i); puts("");
//        }
       // memset(minDis, 0x3f, sizeof minDis);
        for (int i = 0; i < maxn; ++i) minDis[i] = Inf;

        //spec.H
        //right
        for (int i = 0; i < maxn; ++i) tDis[i] = Inf;
        for (int i = 0; i < maxn; ++i) asn[i] = Inf;
        
        for (int i = 1; i < _c1; ++i) {
            if (p1[i].t == 0 && p1[i].y == p1[i - 1].y) {
                if (p1[i - 1].t == 1) {
                    asn[i] = p1[i].x1 - p1[i - 1].x2;
                    if (asn[i] < tDis[p1[i].id]) {
                        tDis[p1[i].id] = asn[i];
                        tPos[p1[i].id] = p1[i - 1].id;
                    }
                }
                else if (asn[i - 1] != Inf) {
                    asn[i] = asn[i - 1] + p1[i].x1 - p1[i - 1].x1;
                    if (asn[i] < tDis[p1[i].id]) {
                        tDis[p1[i].id] = asn[i];
                        tPos[p1[i].id] = tPos[p1[i - 1].id];
                    }
                }
                if (tDis[p1[i].id] < minDis[p1[i].id]) {
                    minDis[p1[i].id] = tDis[p1[i].id];
                    minPos[p1[i].id] = tPos[p1[i].id];
                }
            }
        }
        //left
        for (int i = 0; i < maxn; ++i) tDis[i] = Inf;
        for (int i = 0; i < maxn; ++i) asn[i] = Inf;
        
        for (int i = _c1 - 2; i >= 0; --i) {
            if (p1[i].t == 0 && p1[i].y == p1[i + 1].y) {
                if (p1[i + 1].t == 1) {
                    asn[i] = p1[i + 1].x1 - p1[i].x1;
                    if (asn[i] < tDis[p1[i].id]) {
                        tDis[p1[i].id] = asn[i];
                        tPos[p1[i].id] = p1[i + 1].id;
                    }
                }
                else if (asn[i + 1] != Inf) {
                    asn[i] = asn[i + 1] + p1[i + 1].x1 - p1[i].x1;
                    if (asn[i] < tDis[p1[i].id]) {
                        tDis[p1[i].id] = asn[i];
                        tPos[p1[i].id] = tPos[p1[i + 1].id];
                    }
                }
                
                if (tDis[p1[i].id] < minDis[p1[i].id]) {
                    minDis[p1[i].id] = tDis[p1[i].id];
                    minPos[p1[i].id] = tPos[p1[i].id];
                }
            }
        }

        //spec.V
        //up
        for (int i = 0; i < maxn; ++i) tDis[i] = Inf;
        for (int i = 0; i < maxn; ++i) asn[i] = Inf;
        
        for (int i = 1; i < _c2; ++i) {
            if (p2[i].t == 0 && p2[i].x == p2[i - 1].x) {
                if (p2[i - 1].t == 1) {
                    asn[i] = p2[i].y1 - p2[i - 1].y2;
                    if (asn[i] < tDis[p2[i].id]) {
                        tDis[p2[i].id] = asn[i];
                        tPos[p2[i].id] = p2[i - 1].id;
                    }
                }
                else if (asn[i - 1] != Inf) {
                    asn[i] = asn[i - 1] + p2[i].y1 - p2[i - 1].y1;
                    if (asn[i] < tDis[p2[i].id]) {
                        tDis[p2[i].id] = asn[i];
                        tPos[p2[i].id] = tPos[p2[i - 1].id];
                    }
                }
                if (tDis[p2[i].id] < minDis[p2[i].id]) {
                    minDis[p2[i].id] = tDis[p2[i].id];
                    minPos[p2[i].id] = tPos[p2[i].id];
                }
            }
        }
        //down
        for (int i = 0; i < maxn; ++i) tDis[i] = Inf;
        for (int i = 0; i < maxn; ++i) asn[i] = Inf;
        
        for (int i = _c2 - 2; i >= 0; --i) {
            if (p2[i].t == 0 && p2[i].x == p2[i + 1].x) {
                if (p2[i + 1].t == 1) {
                    asn[i] = p2[i + 1].y1 - p2[i].y1;
                    if (asn[i] < tDis[p2[i].id]) {
                        tDis[p2[i].id] = asn[i];
                        tPos[p2[i].id] = p2[i + 1].id;
                    }
                }
                else if (asn[i + 1] != Inf) {
                    asn[i] = asn[i + 1] + p2[i + 1].y1 - p2[i].y1;
                    if (asn[i] < tDis[p2[i].id]) {
                        tDis[p2[i].id] = asn[i];
                        tPos[p2[i].id] = tPos[p2[i + 1].id];
                    }
                }
                if (tDis[p2[i].id] < minDis[p2[i].id]) {
                    minDis[p2[i].id] = tDis[p2[i].id];
                    minPos[p2[i].id] = tPos[p2[i].id];
                }
            }
        }
        
        //up
        memset(tree, 0xff, sizeof tree);
        for (int i = 0; i < _c1; ++i) {
            if (p1[i].t == 1) {
                update(1, hLen, p1[i].id_x1, p1[i].id_x2, i, 1);
            }
            else {
                ans = query(1, hLen, p1[i].id_x1, 1);
                if (ans == -1) continue;
                dit = p1[i].y - p1[ans].y;
                if (dit < minDis[p1[i].id]) {
                    minDis[p1[i].id] = dit;
                    minPos[p1[i].id] = p1[ans].id;
                }
            }
        }

        //down
        memset(tree, 0xff, sizeof tree);
        for (int i = _c1 - 1; i >= 0; --i) {
            if (p1[i].t == 1) {
                update(1, hLen, p1[i].id_x1, p1[i].id_x2, i, 1);
            }
            else {
                ans = query(1, hLen, p1[i].id_x1, 1);
                if (ans == -1) continue;
                dit = p1[ans].y - p1[i].y;
                if (dit < minDis[p1[i].id]) {
                    minDis[p1[i].id] = dit;
                    minPos[p1[i].id] = p1[ans].id;
                }
            }
        }

        //right
        memset(tree, 0xff, sizeof tree);
        for (int i = 0; i < _c2; ++i) {
            if (p2[i].t == 1) {
                update(1, vLen, p2[i].id_y1, p2[i].id_y2, i, 1);
            }
            else {
                ans = query(1, vLen, p2[i].id_y1, 1);
                if (ans == -1) continue;
                dit = p2[i].x - p2[ans].x;
                if (dit < minDis[p2[i].id]) {
                    minDis[p2[i].id] = dit;
                    minPos[p2[i].id] = p2[ans].id;
                }
            }
        }

        //left
        memset(tree, 0xff, sizeof tree);
        for (int i = _c2 - 1; i >= 0; --i) {
            if (p2[i].t == 1) {
                update(1, vLen, p2[i].id_y1, p2[i].id_y2, i, 1);
            }
            else {
                ans = query(1, vLen, p2[i].id_y1, 1);
                dit = p2[ans].x - p2[i].x;
                if (ans == -1) continue;
//                cout<< p2[ans].id << ":" << dit<<endl;
//                cout << minDis[p2[i].id] << endl;
                if (dit < minDis[p2[i].id]) {
                    minDis[p2[i].id] = dit;
                    minPos[p2[i].id] = p2[ans].id;
                }
            }
        }

        memset(ret, 0, sizeof ret);
        for (int i = 0; i < m; ++i) {
            ++ret[ minPos[i] ];
        }
        for (int i = 0; i < n; ++i) {
            printf("%d\n", ret[i]);
        }
    }
    return 0;
}
