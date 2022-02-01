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
#define maxn 200200
using namespace std;
struct node{
    int key, minv, size, delta, rev;
    node *ch[2], *pre;
    void add(int v){
        if(size == 0) return;
        key += v;
        minv += v;
        delta += v;
    }
    void reverse(){
        if(size == 0) return;
        rev ^= 1;
        swap(ch[0], ch[1]);
    }
    void update(){
        size = ch[0]->size + ch[1]->size + 1;
        minv = min(key, min(ch[0]->minv, ch[1]->minv));
    }
    void pushdown(){
        if(delta){
            ch[0]->add(delta);
            ch[1]->add(delta);
            delta = 0;
        }
        if(rev){
            ch[0]->reverse();
            ch[1]->reverse();
            rev = 0;
        }
    }
};
int num[maxn];
#define keytree root->ch[1]->ch[0]
struct SplayTree{
    int cnt, top;
    node *st[maxn], data[maxn], *root, *null;
    node* newnode(int v){
        node *p;
        if(top) p = st[top--];
        else p = &data[cnt++];
        p->key = p->minv = v;
        p->delta = p->rev = 0;
        p->size = 1;
        p->pre = p->ch[0] = p->ch[1] = null;
        return p;
    }
    void init(){
        cnt = top = 0;
        null = newnode(inf);
        null->size = 0;
        root = newnode(inf);
        root->ch[1] = newnode(inf);
        root->ch[1]->pre = root;
        root->update();
    }
    node* build(int l, int r){
        if(l > r) return null;
        int mid = (l + r) >> 1;
        node *p = newnode(num[mid]);
        p->ch[0] = build(l, mid - 1);
        p->ch[1] = build(mid + 1, r);
        if(p->ch[0] != null) p->ch[0]->pre = p;
        if(p->ch[1] != null) p->ch[1]->pre = p;
        p->update();
        return p;
    }
    // c=0 zag, c=1 zig
    void rotate(node *x, int c){
        node *y = x->pre;
        y->pushdown();
        x->pushdown();
        y->ch[!c] = x->ch[c];
        if(x->ch[c] != null) x->ch[c]->pre = y;
        x->pre = y->pre;
        if(y->pre != null) y->pre->ch[y == y->pre->ch[1]] = x;
        x->ch[c] = y;
        y->pre = x;
        y->update();
        if(y == root) root = x;
    }
    void splay(node *x, node *f){
        x->pushdown();
        while(x->pre != f){
            if(x->pre->pre == f){
                rotate(x, x->pre->ch[0] == x);
                break;
            }
            node *y = x->pre;
            node *z = y->pre;
            int c = (y == z->ch[0]);
            if(y->ch[c] == x){
                rotate(x, !c), rotate(x, c);
            }
            else{
                rotate(y, c), rotate(x, c);
            }
        }
        x->update();
    }
    void select(int k, node *x){
        node *p = root;
        int tmp;
        while(1){
            p->pushdown();
            tmp = p->ch[0]->size;
            if(tmp == k) break;
            else if(tmp < k){
                k -= tmp + 1;
                p = p->ch[1];
            }
            else p = p->ch[0];
        }
        splay(p, x);
    }
/*-------------------------------------*/
    void add(int a, int b, int c){
        select(a - 1, null);
        select(b + 1, root);
        keytree->add(c);
        splay(keytree, null);
    }
    void reverse(int a, int b){
        select(a - 1, null);
        select(b + 1, root);
        keytree->reverse();
        splay(keytree, null);
    }
    void revolve(int a, int c, int d){
        int len = c - a + 1;
        d %= len; if(d < 0) d += len;
        int b = c - d;
        if(d == 0) return;
        else if(d == 1){
            del(c);
            insert(a - 1, st[top]->key);
        }
        else{
            select(b + 1, null);
            select(c + 1, root);
            select(a - 1, root);
            select(c, root->ch[1]);
            node *p = root->ch[0]->ch[1];
            root->ch[0]->ch[1] = null;
            root->ch[0]->update();
            keytree->ch[1] = p;
            p->pre = keytree;
            splay(p, null);
        }
    }
    void insert(int a, int c){
        select(a, null);
        select(a + 1, root);
        keytree = newnode(c);
        keytree->pre = root->ch[1];
        root->ch[1]->update();
        splay(keytree, null);
    }
    void del(int a){
        select(a, null);
        node *tr = root;
        root = root->ch[1];
        root->pre = null;
        select(0, null);
        root->ch[0] = tr->ch[0];
        root->ch[0]->pre = root;
        root->update();
        st[++top] = tr;
    }
    int getmin(int a, int b){
        select(a - 1, null);
        select(b + 1, root);
        int res = keytree->minv;
        splay(keytree, null);
        return res;
    }
    void debug() {vis(root);}
    void vis(node* t) {
        if (t == null) return;
        vis(t->ch[0]);
        printf("node%2d:lson %2d,rson %2d,pre %2d,sz=%2d,key=%2d\n",
                t - data, t->ch[0] - data, t->ch[1] - data,
                t->pre - data, t->size, t->key);
        vis(t->ch[1]);
    }
}spt;
int main(){
    int n,m;
    char op[20]; int x,y,z;
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++) scanf("%d", &num[i]);
        spt.init();
        if(n > 0){
            node *tr = spt.build(1, n);
            spt.keytree = tr;
            tr->pre = spt.root->ch[1];
            spt.splay(tr, spt.null);
        }
        //spt.debug();
        scanf("%d", &m);
        while(m--){
            scanf(" %s", op);
            if(op[0] == 'A'){
                scanf("%d%d%d", &x, &y, &z);
                spt.add(x, y, z);
            }
            else if(op[0] == 'I'){
                scanf("%d%d", &x, &y);
                spt.insert(x, y);
            }
            else if(op[0] == 'D'){
                scanf("%d", &x);
                spt.del(x);
            }
            else if(op[0] == 'M'){
                scanf("%d%d", &x, &y);
                printf("%d\n", spt.getmin(x, y));
            }
            else if(op[3] == 'E'){
                scanf("%d%d", &x, &y);
                spt.reverse(x, y);
            }
            else{
                scanf("%d%d%d", &x, &y, &z);
                spt.revolve(x, y, z);
            }
        }
    }
    return 0;
}
