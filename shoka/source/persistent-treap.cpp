struct Node;

typedef std::pair <Node*, Node*> Pair;

struct Node {
    int size;
    Node *left, *right;

    Node(Node *left, Node *right) : left(left), right(right) {}

    Node* update() {
        size = left->size + 1 + right->size;
        return this;
    }

    Pair split(int);
};

bool random(int a, int b) {
    return rand() % (a + b) < a;
}

Node *null;

Node* merge(Node *p, Node *q) {
    if (p == null) {
        return q;
    }
    if (q == null) {
        return p;
    }
    if (random(p->size, q->size)) {
        p->right = merge(p->right, q);
        return p->update();
    }
    q->left = merge(p, q->left);
    return q->update();
}

Pair Node::split(int n) {
    if (this == null) {
        return std::make_pair(null, null);
    }
    if (n <= left->total) {
        Pair ret = left->split(n);
        left = null;
        return std::make_pair(ret.first, merge(ret.second, this->update()));
    }
    Pair ret = right->split(n - left->total);
    right = null;
    return std::make_pair(merge(this->update(), ret.first), ret.second);
}

int main() {
    // initialize
    null = new Node(0, 0);
    null->left = null->right = null;
}
