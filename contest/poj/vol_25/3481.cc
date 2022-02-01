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
#define maxn 1000100
using namespace std;
struct node{
    int id, key, size;
    node *ch[2], *pre;
    void update(){
        size = ch[0]->size + ch[1]->size + 1;
    }

};
#define keytree root->ch[1]->ch[0]
struct SplayTree{
    int cnt, top;
    node *st[maxn], data[maxn], *null, *root;
    node* newnode(int id, int key){
        node *p;
        if(top) p = st[top--];
        else p = &data[cnt++];
        p->key = key;
        p->id = id;
        p->size = 1;
        p->ch[0] = p->ch[1] = p->pre = null;
        return p;
    }
    void init(){
        cnt = top = 0;
        null = newnode(0, 0);
        null->size = 0;
        root = newnode(0, -inf);
        root->ch[1] = newnode(0, inf);
        root->ch[1]->pre = root;
        root->update();
    }
    void rotate(node *x, int c){
        node *y = x->pre;
        // y->pushdown();
        y->ch[!c] = x->ch[c];
        if(x->ch[c]->pre != null) x->ch[c]->pre = y;
        x->pre = y->pre;
        if(y->pre != null) y->pre->ch[y == y->pre->ch[1]] = x;
        x->ch[c] = y;
        y->pre = x;
        y->update();
        if(y == root) root = x;
    }
    void splay(node *x, node *f){
        // x->pushdown();
        while(x->pre != f){
            if(x->pre->pre == f){
                rotate(x, x->pre->ch[0] == x);
                break;
            }
            node *y = x->pre;
            node *z = y->pre;
            int c = (y == z->ch[0]);
            if(x == y->ch[c]){
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
            //p->pushdown();
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
    /*-------------------------*/
    void insert(int id, int key){
        node *p = root;
        while(1){
            int c = (key > p->key);
            if(p->ch[c] != null) p = p->ch[c];
            else{
                p->ch[c] = newnode(id, key);
                p->ch[c]->pre = p;
                p->update();
                splay(p->ch[c], null);
                break;
            }
        }
    }
    int getmax(){
        if(root->size == 2) return 0;
        select(root->size - 2, null);
        node *tr = root;
        root = root->ch[1];
        root->pre = null;
        select(0, null);
        root->ch[0] = tr->ch[0];
        root->ch[0]->pre = root;
        root->update();
        st[++top] = tr;
        return tr->id;
    }
    int getmin(){
        if(root->size == 2) return 0;
        select(1, null);
        node *tr = root;
        root = root->ch[1];
        root->pre = null;
        select(0, null);
        root->ch[0] = tr->ch[0];
        root->ch[0]->pre = root;
        root->update();
        st[++top] = tr;
        return tr->id;
    }
}spt;
int main(){
    int op, k, p;
    spt.init();
    while(scanf("%d", &op) && op){
        if(op == 1){
            scanf("%d%d", &k, &p);
            spt.insert(k, p);
        }
        else if(op == 2){
            printf("%d\n", spt.getmax());
        }
        else{
            printf("%d\n", spt.getmin());
        }
    }
    return 0;
}
