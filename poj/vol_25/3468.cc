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

#define maxn 100100

#define Inf 0 //0x3FFFFFFFFFFFFFFFLL

using namespace std;
typedef long long ll;

struct node{
    ll key, sum, delta, size;
    node *ch[2], *pre;
    void add(ll a){
        if(size == 0) return;
        key += a;
        delta += a;
        sum += size * a;
    }
    void update(){
        size = ch[0]->size + ch[1]->size + 1;
        sum = ch[0]->sum + ch[1]->sum + key;
    }
    void pushdown(){
        if(delta){
            ch[0]->add(delta);
            ch[1]->add(delta);
        }
        delta = 0;
    }
};
ll arr[maxn];
#define keytree root->ch[1]->ch[0]
struct SplayTree{
    int cnt, top;
    node *st[maxn], data[maxn];
    node *null, *root;
    node* newnode(ll v){
        node *p;
        if(top) p = st[top--];
        else p = &data[cnt++];
        p->key = p->sum = v;
        p->delta = 0;
        p->size = 1;
        p->ch[0] = p->ch[1] = p->pre = null;
        return p;
    }
    void init(){
        cnt = top = 0;
        null = newnode(Inf);
        null->size = 0;
        root = newnode(Inf);
        root->ch[1] = newnode(Inf);
        root->ch[1]->pre = root;
        root->update();
    }
    node* build(int l,int r){
        if(l > r) return null;
        int mid = (l + r) >> 1;
        node *p = newnode(arr[mid]);
        p->ch[0] = build(l, mid - 1);
        p->ch[1] = build(mid + 1, r);
        if(p->ch[0] != null) p->ch[0]->pre = p;
        if(p->ch[1] != null) p->ch[1]->pre = p;
        p->update();
        return p;
    }
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
            else{
                p = p->ch[0];
            }
        }
        splay(p, x);
    }

    void add(int a, int b, ll c){
        select(a - 1, null);
        select(b + 1, root);
        keytree->add(c);
        splay(keytree, null);
    }
    ll getsum(int a, int b){
        select(a - 1, null);
        select(b + 1, root);
        return keytree->sum;
    }
    void debug() {
        vis(root);
        printf("---\n\n");
    }
    void vis(node* t) {
        if (t == null) return;
        vis(t->ch[0]);
        printf("node%2d:lson %2d,rson %2d,pre %2d,sz=%lld,key=%lld,sum=%lld\n",
                t - data, t->ch[0] - data, t->ch[1] - data,
                t->pre - data, t->size, t->key, t->sum);
        vis(t->ch[1]);
    }
}spt;
int main(){
    int n,q; char ch;
    int a,b; ll c;
    while(~scanf("%d%d", &n, &q)){
        for(int i=1;i<=n;i++) scanf("%lld", &arr[i]);
        spt.init();
        node *troot = spt.build(1, n);
        spt.keytree = troot;
        troot->pre = spt.root->ch[1];
        spt.splay(troot, spt.null);
       // spt.debug();
        while(q--){
            scanf(" %c", &ch);
            if(ch == 'Q'){
                scanf("%d%d", &a, &b);
                printf("%lld\n", spt.getsum(a, b));
            }
            else{
                scanf("%d%d%lld", &a, &b, &c);
                spt.add(a, b, c);
            }
        }
    }
    return 0;
}
