/*************************************************************************
    > File Name: splay.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/2 21:32:47
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

#define Null NULL
const int N=100;
// node 为结点类型
// pre 表示指向父亲的指针
//其中ch[0]表示左结点指针，ch[1]表示右结点指针
struct node{
    node* pre;
    node* ch[2];
}splay_tree[N],*root;

void Rotate(node *x, int c) { // 旋转操作，c=0 表示左旋，c=1 表示右旋
    node *y = x->pre;

    y->ch[!c] = x->ch[c];
    if (x->ch[c] != Null) x->ch[c]->pre = y;
    x->pre = y->pre;
    if (y->pre != Null)
        if (y->pre->ch[0] == y) y->pre->ch[0] = x;
        else y->pre->ch[1] = x;
    x->ch[c] = y, y->pre = x;
    if (y == root) root = x; // root 表示整棵树的根结点
}

void Splay(node *x, node *f) { // Splay 操作，表示把结点x 转到结点f 的下面
    for ( ; x->pre != f; )
        if (x->pre->pre == f) // 父结点的父亲即为f，执行单旋转
            if (x->pre->ch[0] == x) Rotate(x, 1);
            else Rotate(x, 0);
        else {
            node *y = x->pre, *z = y->pre;
            if (z->ch[0] == y)
                if (y->ch[0] == x)
                    Rotate(y, 1), Rotate(x, 1); // 一字形旋转
                else
                    Rotate(x, 0), Rotate(x, 1); // 之字形旋转
            else if (y->ch[1] == x)
                Rotate(y, 0), Rotate(x, 0); // 一字形旋转
            else
                Rotate(x, 1), Rotate(x, 0); // 之字形旋转
        }
}
int main() {

    return 0;
}
