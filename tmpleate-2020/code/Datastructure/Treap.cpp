/*  init null before everything.
    For example: null = pool; null->size = 0; null->ch[0] = null->ch[1] = null;*/
struct Node;
Node *null;
struct Node {
    Node *ch[2];
    int fix, key, size;
    void up();
}pool[N * 20], *C = pool + 1;

void Node::up() {
    if (this == null) return;
    size = ch[0]->size + ch[1]->size + 1;
}

Node *newNode(int key) {
    C->ch[0] = C->ch[1] = null;
    C->size = 1;
    C->key = key;
    C->fix = (rand() << 16) ^ rand();
    return C++;
}

// o = 0 -- left child up
void rot(Node *&u, int o) {
    Node *v = u->ch[o];
    u->ch[o] = v->ch[!o];
    v->ch[!o] = u;
    u->up();
    v->up();
    u = v;
}

void insert(Node *&u, int key) {
    if (u == null) {
        u = newNode(key);
    } else {
        u->size++;
        if (key < u->key) {
            insert(u->ch[0], key);
            if (u->ch[0]->fix < u->fix) rot(u, 0);
        } else {
            insert(u->ch[1], key);
            if (u->ch[1]->fix < u->fix) rot(u, 1);
        }
    }
}

//if each element in u less or equal than each element in v
Node *merge(Node *u, Node *v) {
    if (u == null) return v;
    if (v == null) return u;
    if (u->fix < v->fix) {
        u->ch[1] = merge(u->ch[1], v);
        u->up();
        return u;
    } else {
        v->ch[0] = merge(u, v->ch[0]);
        v->up();
        return v;
    }
}

void erase(Node *&u, int key) {
    if (u == null) return;
    if (u->key == key) {
        u = merge(u->ch[0], u->ch[1]);
    } else {
        key < u->key ? erase(u->ch[0], key) : erase(u->ch[1], key);
        u->up();
    }
}