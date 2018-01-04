struct Node {
    int count;
    Node *left, *right;

    Node(int count, Node* left, Node* right): count(count), left(left), right(right) {}

    Node* insert(int l, int r, int k);
};

Node* null;

Node* Node::insert(int l, int r, int k) {
    if (k < l || r <= k) {
        return this;
    }
    if (l + 1 == r) {
        return new Node(this->count + 1, null, null);
    }
    int m = (l + r) >> 1;
    return new Node(this->count + 1, 
            this->left->insert(l, m, k),
            this->right->insert(m, r, k));
}

int main() {
    // initialize
    null = new Node(0, NULL, NULL);
    null->left = null->right = null;
}
