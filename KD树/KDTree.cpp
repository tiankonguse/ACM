/* 
使用前调用init静态建树，然后模仿query进行类Binary Search Tree式的访问即可 
Obj是点的类型，如果追求效率或者在点上除了坐标还有其它信息，可以自己写一个Obj类，然后重载[]运算符
*/
namespace KDTree {
    int K;
    typedef vector <int> Obj;
    template <int T> bool cmpT(const Obj &a, const Obj &b) { return a[T] < b[T]; }
    bool (*cmp[])(const Obj &, const Obj &) = {cmpT <0>, cmpT <1>, cmpT <2>}; //填到所需要的最大维度数目为止，这里表示的是最大3维
    struct Filter {
        Obj low, high; //每一维的限制

        bool ok(const Obj &o) const { //一个点是否符合当前Filter的要求
            rep (i, K)
                if (o[i] < low[i] || o[i] > high[i])
                    return 0;
            return 1;
        }

        bool isFit(const Filter &o) const { //o包含的集合是否this的子集
            rep (i, K)
                if (o.low[i] < low[i] || o.high[i] > high[i])
                    return 0;
            return 1;
        }

        void merge(const Filter &o) {
            rep (i, K) {
                low[i] = min(low[i], o.low[i]);
                high[i] = max(high[i], o.high[i]);
            }
        }
    };
    struct Node {
        Obj u;
        Filter f;
        int sz, k;
        Node *lc, *rc;
        void update() {
            sz = 1;
            f.low = u;
            f.high = u;
            if (lc) {
                sz += lc->sz;
                f.merge(lc->f);
            }
            if (rc) {
                sz += rc->sz;
                f.merge(rc->f);
            }
        }
    }mem[100005], *C, *root;

    Node *newNode(const Obj &u, int k) {
        C->u = u;
        C->sz = 1;
        C->k = k;
        C->lc = C->rc = 0;
        return C++;
    }

    Node *build(vector <Obj> &a, int l, int r, int k) {
        if (l >= r) return 0;
        int mid = (l + r) / 2;
        nth_element(a.begin() + l, a.begin() + mid, a.begin() + r, cmp[k]);
        Node *c = newNode(a[mid], k);
        c->lc = build(a, l, mid, (k + 1) % K);
        c->rc = build(a, mid + 1, r, (k + 1) % K);
        c->update();
        return c;
    }

    int query(Node *p, const Filter &f) {
        if (!p) return 0;
        if (f.isFit(p->f)) return p->sz; //子树下的东西全是符合要求的
        int x = p->u[p->k];
        int res = f.ok(p->u);
        if (x >= f.low[p->k]) res += query(p->lc, f); //if表示“如果左子树下仍可能有符合条件的点”
        if (x <= f.high[p->k]) res += query(p->rc, f);//同上
        return res;
    }

    void init(vector <Obj> a, int K) { //传入建树的列表和维数K
        KDTree::K = K;
        C = mem;
        root = build(a, 0, a.size(), 0);
    }
}

//询问使用姿势(C++0x下)
KDTree::Filter f;
f.low = {1, 5};
f.high = {5, 7}; //第一个维度限制为[1, 5]，第二个维度限制为[5, 7]
ret = KDTree::query(KDTree::root, f);