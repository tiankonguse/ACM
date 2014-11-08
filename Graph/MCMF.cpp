const int N = 40005;
const int M = 400005;
const int INF = 0x7fffffff;

struct edge {
    int x, y, c, w;
    edge *next, *op;
}g[M], *ls[N], *fa[N];
int e, d[N], inQ[N];

void addedge(int x, int y, int c, int w) {
    g[e].x = x; g[e].y = y; g[e].c = c; g[e].w = w; g[e].next = ls[x]; ls[x] = &g[e]; g[e].op = &g[e + 1];
    ++e;
    g[e].x = y; g[e].y = x; g[e].c = 0; g[e].w =-w; g[e].next = ls[y]; ls[y] = &g[e]; g[e].op = &g[e - 1];
    ++e;
}

int MCMF(int S, int T, int n) {
    int cost = 0;
    for (;;) {
        rep (i, n) {
            d[i] = INF;
            inQ[i] = 0;
        }
        d[S] = 0;
        queue <int> Q;
        Q.push(S);
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            inQ[x] = 0;
            for (edge *t = ls[x]; t; t = t->next) {
                if (t->c && d[t->x] + t->w < d[t->y]) {
                    d[t->y] = d[t->x] + t->w;
                    fa[t->y] = t;
                    if (!inQ[t->y]) {
                        inQ[t->y] = 1;
                        Q.push(t->y);
                    }
                }
            }
        }
        if (d[T] == INF) return cost;
        int nf = INF;
        for (int i = T; i != S; i = fa[i]->x) checkmin(nf, fa[i]->c);
        for (int i = T; i != S; i = fa[i]->x) {
            fa[i]->c -= nf;
            fa[i]->op->c += nf;
        }
        cost += d[T] * nf;
    }
}