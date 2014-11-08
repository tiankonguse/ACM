#include <algorithm>
using namespace std;

/*
每次先调用一下Splay::init()
不同的题目注意修改newNode, pushdown, update三个函数就足够了
Splay命名空间里的函数都是对树的操作，对结点的操作都归类到Node里。
空间吃紧时可修改erase函数，增加内存池管理
*/
const int N = 130005;
struct Node {
	int key, size;
	bool rvs;
	Node *f, *ch[2];
	void set(int c, Node *x);   //设当前结点的左(0)/右(1)儿子为x
	void fix();                 //令两个儿子的父亲指针指向自己，主要为了写起来方便，意义明确
	void pushdown();            //标记下传
	void update();              //从儿子处更新自己的信息
	void rotate();              //向上旋转
	void Splay(Node *);         //把当前Node旋转到参数传入的Node下面。Node默认为null，直接调用Splay()则旋转到根
}statePool[N], *null;			//本模板统一用null代替NULL
void Node::set(int c, Node *x) {
	ch[c] = x;
	x->f = this;
}
void Node::fix() {
	ch[0]->f = this;
	ch[1]->f = this;
}
void Node::pushdown() {
	if (this == null) return;
	if (rvs) {
		ch[0]->rvs ^= 1;
		ch[1]->rvs ^= 1;
		rvs = 0;
		swap(ch[0], ch[1]);
	}
}
void Node::update() {
	if (this == null) return;
	size = ch[0]->size + ch[1]->size + 1;
}
void Node::rotate() {
	Node *x = f;
	bool o = f->ch[0] == this;
	x->set(!o, ch[o]);
	x->f->set(x->f->ch[1] == x, this);
	set(o, x);
	x->update();
	update();
}
void Node::Splay(Node *goal = null) {
	pushdown();
	for (; f != goal;) {
		f->f->pushdown();
		f->pushdown();
		pushdown();
		if (f->f == goal) {
			rotate();
		} else if ((f->f->ch[0] == f) ^ (f->ch[0] == this)) {
			rotate();
			rotate();
		} else {
			f->rotate();
			rotate();
		}
	}
}
namespace Splay {
	int poolCnt;
	Node *newNode() {
		Node *p = &statePool[poolCnt++];
		p->f = p->ch[0] = p->ch[1] = null;
		p->size = 1;
		p->rvs = 0;
		return p;
	}
	//该命名空间里的函数必须先调用init()
	void init() {
		poolCnt = 0;
		null = newNode();
		null->size = 0;
	}

	//用a[l..r]的值建立一棵完全平衡的Splay tree。返回树根。
	template <class T> Node *build(int l, int r, T a[]) {
		if (l > r) return null;
		Node *p = newNode();
		int mid = (l + r) / 2;
		p->key = a[mid];
		if (l < r) {
			p->ch[0] = build(l, mid - 1, a);
			p->ch[1] = build(mid + 1, r, a);
			p->update();
			p->fix();
		}
		return p;
	}
	
	//返回树中第i个元素，若没有其它操作，请记得select后进行Splay操作以保证均摊复杂度。
	Node *select(Node *root, int i) {
		for (Node *p = root;;) {
			p->pushdown();
			if (p->ch[0]->size + 1 == i) {
				return p;
			} else if (p->ch[0]->size >= i) {
				p = p->ch[0];
			} else {
				i -= p->ch[0]->size + 1;
				p = p->ch[1];
			}
		}
	}
	
	//返回结点p在树中的排名
	int rank(Node *p) {
		p->Splay();
		return p->ch[0]->size + 1;
	}
	
	// 返回 >= a 的结点，若没有则返回null, 若之后没有其它操作，最好进行Splay操作以保证均摊复杂度。
	// 返回null时可以这样保证复杂度： select(root, root->size)->Splay();
	template <class T> Node *lower_bound(Node *root, T a) {
		Node *ret = null;
		for (Node *p = root; p != null; ) {
			p->pushdown();
			if (a < p->key) {
				p = p->ch[1];
			} else {
				ret = p;
				p = p->ch[0];
			}
		}
		return ret;
	}
	
	//传入两树根，将之合并(可以处理null)。p中结点均在q中结点的左边。
	Node *merge(Node *p, Node *q) {
		p->f = q->f = null;
		if (p == null) return q;
		if (q == null) return p;
		q = select(q, 1);
		q->Splay();
		q->set(0, p);
		q->update();
		return q;
	}
	
	//当p为根，且q为p的右儿子时，翻转从p到q的所有结点，返回树根
	Node *reverse(Node *p, Node *q) {
		swap(p->ch[0], q->ch[0]);
		p->ch[1] = q->ch[1];
		q->ch[1] = p;
		q->f = null;
		p->fix();
		q->fix();
		p->update();
		q->update();
		p->ch[0]->rvs ^= 1;
		return q;
	}
	
	//翻转第l个元素到第r个元素，返回树根，下标从1开始。
	Node *reverse(Node *root, int l, int r) {
		if (l >= r) return root;
		Node *p = select(root, l);
		p->Splay();
		Node *q = select(p, r);
		q->Splay(p);
		return reverse(p, q);
	}
	
	//在p的前一位插入q，返回树根
	Node *insert(Node *p, Node *q) {
		p->Splay();
		if (p->ch[0] == null) {
			p->set(0, q);
		} else {
			Node *t = select(p, p->ch[0]->size);
			t->Splay(p);
			t->set(1, q);
			t->update();
		}
		p->update();
		return p;
	}
	
	//在第i个元素前插入结点q，返回树根
	Node *insert(Node *root, Node *q, int i) {
		if (i > root->size) {
			Node *p = select(root, root->size);
			p->Splay();
			p->set(1, q);
			p->update();
			return p;
		} else {
			Node *p = select(root, i);
			return insert(p, q);
		}
	}
	
	//删除以p为根的子树
	Node *erase(Node *p) {
		if (p->f != null) {
			Node *q = p->f;
			q->pushdown();
			q->set(q->ch[1] == p, null);
			q->update();
			q->Splay();
			return q;
		} else {
			return null;
		}
	}
	
	//删除第l个到第r个结点，返回树根
	Node *erase(Node *root, int l, int r) {
		if (l > r) return root;
		if (l == r) {
			Node *p = select(root, l);
			p->Splay();
			return merge(p->ch[0], p->ch[1]);
		} else {
			Node *p = select(root, l);
			p->Splay();
			Node *q = select(p, r);
			q->Splay(p);
			return merge(p->ch[0], q->ch[1]);
		}
	}
	
	//切开结点p与其左儿子之间的边，返回左子树的根以及原树的根。
	pair <Node *, Node *> split(Node *p) {
		Node *q = p->ch[0];
		p->ch[0] = null;
		q->f = null;
		p->update();
		p->Splay();
		return make_pair(q, p);
	}
}