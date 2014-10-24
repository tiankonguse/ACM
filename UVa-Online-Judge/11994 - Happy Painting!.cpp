#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int N = 50005;
int st[N];
struct LinkCutTree {
    int type[N] , f[N] , p[N] , c[N][2];
    //addtional data
    int size[N] , C[N] , route[N] , paint[N];

    void malloc(int num) {
        for (int x = 1 ; x <= num ; ++ x) {
            type[x] = -1 , f[x] = p[x] = c[x][0] = c[x][1] = 0;
            size[x] = 1 , paint[x] = C[x] = route[x] = 0;
        }
    }
    void clear() {
    }
    inline void pushdown(int x) {
        if (paint[x]) {
            C[x] = route[x] = paint[x];
            if (c[x][0]) paint[c[x][0]] = paint[x];
            if (c[x][1]) paint[c[x][1]] = paint[x];
            paint[x] = 0;
        }
    }
    inline void pushup(int x) {
        pushdown(x); pushdown(c[x][0]); pushdown(c[x][1]);
        size[x] = size[c[x][0]] + 1 + size[c[x][1]];
        route[x] = route[c[x][0]] | C[x] | route[c[x][1]];
    }
    void rotate(int x) {
        int t = type[x] , y = f[x] , z = c[x][!t] ;
        type[x] = type[y] , f[x] = f[y] , p[x] = p[y];
        if (~type[x]) c[f[x]][type[x]] = x;
        type[y] = !t , f[y] = x , p[y] = 0 , c[x][!t] = y;
        if (z) type[z] = t , f[z] = y;
        c[y][t] = z ;
        pushup(y);
    }
    void splay(int x) {
        int scnt = 0;
        st[scnt ++] = x;
        for (int i = x ; ~type[i] ; i = f[i])
            st[scnt ++] = f[i];
        for (int i = scnt - 1 ; i >= 0 ; -- i)
            pushdown(st[i]);
        while (~type[x]) {
            int y = f[x];
            (type[y] == type[x]) ?
                rotate(y) : rotate(x);
            if (~type[x])
                rotate(x);
        }
        pushup(x);
    }
    int access(int x) { // returns the lowest node last exposed
        int y = 0 , z;
        while (x) {
            splay(x);
            z = c[x][1];
            if (z) { // cut right subtree off
                type[z] = -1;
                f[z] = 0 , p[z] = x;
            }
            c[x][1] = y;// connect to new path
            if (y) {
                f[y] = x;
                p[y] = 0;
                type[y] = 1;
            }
            pushup(x);
            y = x ,  x = p[x];
        };
        return y;
    }
    int findroot(int x) {
        access(x);
        splay(x);
        while(c[x][0]) x = c[x][0];
        splay(x);
        return x;
    }
    void Link(int x, int y , int k) { // x is root of some tree, setroot(x) before join
        splay(x);
        assert(!p[x]);
        p[x] = y;
        if (k) C[x] = k;
        access(x);
    }
    int Cut(int y) {
        access(y);
        splay(y);
        int tmp = c[y][0];
        if (c[y][0]) {
            p[c[y][0]] = p[y];
            type[c[y][0]] = -1;
            c[y][0] = 0;
        }
        while (c[tmp][1]) tmp = c[tmp][1];
        p[y] = 0;
        pushup(y); return tmp;
    }
    void Paint(int x , int y , int k) {
        if (x == y || findroot(x) != findroot(y))
            return;
        access(y) , y = 0; int z ;
        while (x) {
            splay(x);
            if (!p[x]) { //x belong to the route from root to y
                // in a way , x is LCA(x , y) now
                // so we will just update the right subtree of x.
                // the right subtree of x is the route from LCA(x , y) to y
                if (c[x][1]) paint[c[x][1]] = k;
                // and y is the route from LCA(x , y) to x
                if (y) paint[y] = k;
            }
            z = c[x][1];
            if (z) { // cut right subtree off
                type[z] = -1;
                f[z] = 0 , p[z] = x;
            }
            c[x][1] = y;// connect to new path
            if (y) {
                f[y] = x;
                p[y] = 0;
                type[y] = 1;
            }
            pushup(x);
            y = x ,  x = p[x];
        }
    }
    void Query(int x , int y) {
        if (x == y || findroot(x) != findroot(y)) {
            puts("0 0");
            return;
        }
        access(y) , y = 0; int z;
        while (x) {
            splay(x);
            if (!p[x]) {
                printf("%d %d\n" , size[c[x][1]] + size[y] , __builtin_popcount(route[c[x][1]] | route[y]));
            }
            z = c[x][1];
            if (z) {
                type[z] = -1;
                f[z] = 0 , p[z] = x;
            }
            c[x][1] = y;
            if (y) {
                f[y] = x;
                p[y] = 0;
                type[y] = 1;
            }
            pushup(x);
            y = x , x = p[x];
        }
    }
    void Change(int x, int y, int k) {
        if (x == y) return;
        int fx = findroot(x), pa = 0;
        if (fx != x)
            pa = Cut(x);
        if (x == findroot(y)) {
            if (pa)
                Link(x, pa , 0);
        }
        else {
            Link(x, y , k);
        }
    }
};
LinkCutTree T;
int n , m;

void work() {
    int i , j , k , x , y , z;
    T.malloc(n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d", &T.p[i]);
    }
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d", &x);
        if (!T.p[i])
            continue;
        T.route[i] = T.C[i] = 1 << x - 1;
    }
    while (m --) {
        scanf("%d",&j);
        if (j == 1) {
            scanf("%d%d%d",&x,&y,&k);
            T.Change(x , y , 1 << k - 1);
        }
        if (j == 2) {
            scanf("%d%d%d",&x,&y,&k);
            T.Paint(x , y , 1 << k - 1);
        }
        if (j == 3) {
            scanf("%d%d",&x,&y);
            T.Query(x , y);
        }
    }

}

int main() {
    freopen("~input.txt" , "r" , stdin);
    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
