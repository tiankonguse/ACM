typedef double T;
typedef vector <T> VEC;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define eps 1e-5
#define ITERNUMBER 1000

/*
    稳定双共轭梯度法(迭代)解线性方程组
    稀疏矩阵有奇效

    用法：
    先设置namespace里面的n(矩阵行数)和_A，然后调用doit()传入b和迭代初始值。返回解向量X。所有向量均视为列向量。
    A * X = b
    下标均为0-base

    要求：A为非奇异(满秩)方阵，即AX = b有唯一解。
*/

struct Mat_element {
    unsigned int _index;
    double _value;
    Mat_element():_index(0), _value(0) {}
    Mat_element(unsigned int n, double v):_index(n), _value(v) {}
};

namespace LinearSystemBICGSTAB_Namespace {
    int n;
    vector < vector<Mat_element> > _A;

    VEC multiply(const VEC &x) {
        VEC res(n);
        rep (i, n) rep (_, _A[i].size()) {
            int j = _A[i][_]._index;
            T v = _A[i][_]._value;
            res[i] += v * x[j];
        }
        return res;
    }

    VEC multiply(const T &x, const VEC &a) {
        VEC res(n);
        rep (i, n) res[i] = a[i] * x;
        return res;
    }

    T multiply(const VEC &a, const VEC &b) {
        T res = 0;
        rep (i, n) res += a[i] * b[i];
        return res;
    }

    VEC subtract(const VEC &a, const VEC &b) {
        VEC res(n);
        rep (i, n) res[i] = a[i] - b[i];
        return res;
    }

    VEC add(const VEC &a, const VEC &b) {
        VEC res(n);
        rep (i, n) res[i] = a[i] + b[i];
        return res;
    }

    bool isZero(const VEC &v) {
        rep (i, v.size()) if (fabs(v[i]) > eps) return 0;
        return 1;
    }

    VEC doit(VEC b, const VEC &_init) {
        VEC r0, r[2], p[2], v[2], t, s, x;
        T R[2], w[2], alpha, beta;
        x = _init;
        r[0] = r0 = subtract(b, multiply(x));
        if (isZero(r0)) return x;
        R[0] = alpha = w[0] = 1;
        v[0] = p[0] = VEC(n);
        rep (_, ITERNUMBER) {
            int i = _ & 1 ^ 1;
            R[i] = multiply(r0, r[i ^ 1]);
            beta = (R[i] / R[i ^ 1]) * (alpha / w[i ^ 1]);
            p[i] = add(r[i ^ 1], multiply(beta, subtract(p[i ^ 1], multiply(w[i ^ 1], v[i ^ 1]))));
            v[i] = multiply(p[i]);
            alpha = R[i] / multiply(r0, v[i]);
            s = subtract(r[i ^ 1], multiply(alpha, v[i]));
            t = multiply(s);
            w[i] = multiply(t, s) / multiply(t, t);
            x = add(add(x, multiply(alpha, p[i])), multiply(w[i], s));
            if (isZero(subtract(b, multiply(x)))) return x;
            r[i] = subtract(s, multiply(w[i], t));
        }
        return x;
    }
}

