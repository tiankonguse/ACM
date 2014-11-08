<<<<<<< HEAD
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
=======
>>>>>>> 1.0
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, v) for (typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
const int MAX_N = 100005;
struct Node {
    int size, state;
<<<<<<< HEAD
    bool isRoot;
    Node *fa, *ch[2];
    inline bool d() { return fa->ch[1] == this; }
    inline void setChild(Node *c, int d) {
        ch[d] = c;
        c->fa = this;
    }
    inline void up() { size = ch[0]->size + ch[1]->size + state; }
    inline void rot() {
        bool o = d();
        Node *f = fa;
        if (f->isRoot) {
            f->isRoot = 0;
            isRoot = 1;
            fa = f->fa;
        } else {
            f->fa->setChild(this, f->d());
        }
        f->setChild(ch[!o], o);
        setChild(f, !o);
        f->up();
    }
    inline void Splay();
}mem[MAX_N], *null = &mem[0], *C, *pt[MAX_N];

void Node::Splay() {
    while (!isRoot) {
        if (fa->isRoot) {
            rot();
        } else {
            d() == fa->d() ? (fa->rot(), rot()) : (rot(), rot());
        }
    }
    up();
}

Node *select(Node *p) {
    if (!p->size) return null;
    while (p->ch[0]->size || !p->state)
        p = p->ch[0]->size ? p->ch[0] : p->ch[1];
    return p;
}

int n;
vector <int> E[MAX_N];

Node *newNode() {
    C->size = C->state = 0;
    C->fa = C->ch[0] = C->ch[1] = null;
    C->isRoot = 1;
    return C++;
}

void bfs() {
    static int Q[MAX_N];
    int qh = 0, qt = 1;
    Q[0] = 0;
    while (qh != qt) {
        int x = Q[qh++];
        foreach (it, E[x]) {
            if (*it != pt[x]->fa - null - 1) {
                pt[*it]->fa = pt[x];
                Q[qt++] = *it;
            }
        }
    }
}

Node *expose(Node *p) {
    Node *tmp;
    for (tmp = null; p != null; tmp = p, p = p->fa) {
        p->Splay();
		// if (type == xxxx) process path here!
        p->ch[1]->isRoot = 1;
        p->ch[1]->fa = p;
        p->setChild(tmp, 1);
        tmp->isRoot = 0;
        p->up();
    }
    return tmp;
}

int main() {
    int Q;
    null->size = 0;
    null->fa = null->ch[0] = null->ch[1] = null;
    {
        C = &mem[1];
        scanf("%d%d", &n, &Q);
        rep (i, n) {
            E[i].clear();
            pt[i] = newNode();
        }
        rep (i, n - 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--; y--;
            E[x].push_back(y);
            E[y].push_back(x);
        }
        bfs();
        rep (i, Q) {
            int op, x;
            scanf("%d%d", &op, &x);
            x--;
            if (op) {
                Node *p = expose(pt[x]);
                p = select(p);
                if (p == null)
                    puts("-1");
                else
                    printf("%d\n", p - null);
            } else {
                pt[x]->Splay();
                pt[x]->state ^= 1;
                pt[x]->up();
            }
        }
    }
    return 0;
=======
	bool isRoot;
	Node *fa, *ch[2];
	inline bool d() { return fa->ch[1] == this; }
	inline void setChild(Node *c, int d) {
		ch[d] = c;
		c->fa = this;
	}
	inline void up() { size = ch[0]->size + ch[1]->size + state; }
	inline void rot() {
		bool o = d();
		Node *f = fa;
		if (f->isRoot) {
			f->isRoot = 0;
			isRoot = 1;
			fa = f->fa;
		} else {
			f->fa->setChild(this, f->d());
		}
		f->setChild(ch[!o], o);
		setChild(f, !o);
		f->up();
	}
	inline void Splay();
}mem[MAX_N], *null = &mem[0], *C, *pt[MAX_N];
 
void Node::Splay() {
	while (!isRoot) {
		if (fa->isRoot) {
			rot();
		} else {
			d() == fa->d() ? (fa->rot(), rot()) : (rot(), rot());
		}
	}
	up();
}
 
Node *select(Node *p) {
	if (!p->size) return null;
	while (p->ch[0]->size || !p->state)
		p = p->ch[0]->size ? p->ch[0] : p->ch[1];
	return p;
}
 
int n;
vector <int> E[MAX_N];
 
Node *newNode() {
	C->size = C->state = 0;
	C->fa = C->ch[0] = C->ch[1] = null;
	C->isRoot = 1;
	return C++;
}
 
void bfs() {
	static int Q[MAX_N];
	int qh = 0, qt = 1;
	Q[0] = 0;
	while (qh != qt) {
		int x = Q[qh++];
		foreach (it, E[x]) {
			if (*it != pt[x]->fa - null - 1) {
				pt[*it]->fa = pt[x];
				Q[qt++] = *it;
			}
		}
	}
}
 
Node *expose(Node *p/*, int t*/) {
	Node *tmp;
	for (tmp = null; p != null; tmp = p, p = p->fa) {
		p->Splay();
		//if (p->fa == null && t == xxxx) gogogo
		p->ch[1]->isRoot = 1;
		p->ch[1]->fa = p;
		p->setChild(tmp, 1);
		tmp->isRoot = 0;
		p->up();
	}
	return tmp;
}
 
int main() {
	int Q;
	null->size = 0;
	null->fa = null->ch[0] = null->ch[1] = null;
	{
		C = &mem[1];
		scanf("%d%d", &n, &Q);
		rep (i, n) {
			E[i].clear();
			pt[i] = newNode();
		}
		rep (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		bfs();
		rep (i, Q) {
			int op, x;
			scanf("%d%d", &op, &x);
			x--;
			if (op) {
				Node *p = expose(pt[x]);
				p = select(p);
				if (p == null)
					puts("-1");
				else
					printf("%d\n", p - null);
			} else {
				pt[x]->Splay();
				pt[x]->state ^= 1;
				pt[x]->up();
			}
		}
	}
	return 0;
>>>>>>> 1.0
}