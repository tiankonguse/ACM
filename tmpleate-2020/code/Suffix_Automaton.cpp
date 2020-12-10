const int N = 250005;

struct Node {
    Node *ch[26], *fa;
    int val;
    int len[10];
    Node(): 
        val(0), fa(NULL) { 
        memset(ch, 0, sizeof(ch));
        memset(len, 0, sizeof(len));
    }
}pool[N * 2 + 5], *last, *root;
vector <Node *> vec[N];

namespace SAM {
    int cnt;

    void init() {
        if (cnt)
            for (int i = 0; i < cnt; i++)
                pool[i] = Node();
        cnt = 1;
        root = &pool[0];
        last = root;
    }

    void add(int c) {
        Node *p = last, *np = &pool[cnt++];
        last = np;
        np->val = p->val + 1;
        for  (; p && !p->ch[c]; p = p->fa)
            p->ch[c] = np;
        if (!p) {
            np->fa = root;
        } else {
            Node *q = p->ch[c];
            if (p->val + 1 == q->val) {
                 np->fa = q;
            } else {
                Node *nq = &pool[cnt++];
                *nq = *q;
                nq->val = p->val + 1;
                q->fa = nq;
                np->fa = nq;
                for (; p && p->ch[c] == q; p = p->fa)
                    p->ch[c] = nq;
            }
        }
    }
}