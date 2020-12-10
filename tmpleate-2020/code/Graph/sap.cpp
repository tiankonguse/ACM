template <class Type>
struct ISAP {
#define N 55
#define M 10005

	int n, S, T, e;
	struct edge {
		int x, y;
		Type c;
		edge *next, *op;
	}g[M], *fa[N], *ls[N], *cur[N];
	int d[N], num[N];
	Type ret;

	void init(int _n, int _S, int _T) {
		n = _n;
		S = _S;
		T = _T;
		e = 0;
		for (int i = 0; i < n; i++) {
			ls[i] = NULL;
		}
	}

	void addedge(int x, int y, Type c) {
		g[e].x = x; g[e].y = y; g[e].c = c; g[e].op = &g[e + 1]; g[e].next = ls[x]; ls[x] = &g[e++];
		g[e].x = y; g[e].y = x; g[e].c = 0; g[e].op = &g[e - 1]; g[e].next = ls[y]; ls[y] = &g[e++];
	}

	void relabel(int x) {
		cur[x] = ls[x];
		d[x] = n + 5;
		for (edge *t = ls[x]; t; t = t->next) {
			if (t->c && d[t->y] + 1 < d[x]) {
				d[x] = d[t->y] + 1;
			}
		}
	}

	void aug() {
		Type nf = numeric_limits <Type>::max();
		for (int i = T; i != S; i = fa[i]->x) {
			if (fa[i]->c < nf) {
				nf = fa[i]->c;
			}
		}
		ret += nf;
		for (int i = T; i != S; i = fa[i]->x) {
			fa[i]->c -= nf;
			fa[i]->op->c += nf;
		}
	}

	Type sap() {
		for (int i = 0; i < n; i++) {
			d[i] = 0;
			num[i] = 0;
			cur[i] = ls[i];
		}
		num[0] = n;
		int i = S;
		ret = 0;
		while (d[S] < n) {
			edge *&t = cur[i];
			for (; t; t = t->next) {
				if (d[i] == d[t->y] + 1 && t->c) {
					break;
				}
			}
			if (t) {
				fa[t->y] = t;
				i = t->y;
				if (i == T) {
					aug();
					i = S;
				}
			} else {
				if (!(--num[d[i]])) {
					return ret;
				}
				relabel(i);
				++num[d[i]];
				if (i != S) {
					i = fa[i]->x;
				}
			}
		}
		return ret;
	}
#undef N
#undef M
};
