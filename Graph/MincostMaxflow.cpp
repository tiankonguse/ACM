int s , t , pre[N] , mcnt;
struct arc {
    int x , f , c , next;
}e[M];
inline void addarc(int x , int y , int z , int c) {
    e[mcnt] = (arc) {y , z , c , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , -c , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , p[N];
bool f[N];
bool Bellman_Ford() {
    deque<int> Q;
    int i , x , y , z;
    for (i = 0 ; i <= t ; ++ i)
        d[i] = 1 << 30 , f[i] = 0;
    d[s] = 0 , f[s] = 1 , Q.push_back(s);
    while (!Q.empty()) {
        x = Q.front() , Q.pop_front() , f[x] = 0;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = e[i].c;
            if (e[i].f && d[y] > d[x] + z) {
                d[y] = d[x] + z , p[y] = i;
                if (!f[y]) {
                    if (Q.empty() || d[y] < d[Q.front()])
                        Q.push_front(y);
                    else
                        Q.push_back(y);
                    f[y] = 1;
                }
            }
        }
    }
    return d[t] != 1 << 30;
}

pair<int , int> MincostMaxflow() {
    int maxflow = 0 , ans = 0 , x;
    while (Bellman_Ford()) {
        int flow = 1 << 30;
        for (x = t ; x != s ; x = e[p[x] ^ 1].x)
            flow = min(flow , e[p[x]].f);
        maxflow += flow , ans += d[t] * flow;
        for (x = t ; x != s ; x = e[p[x] ^ 1].x)
            e[p[x]].f -= flow , e[p[x] ^ 1].f += flow;
    }
    return make_pair(maxflow , ans);
}
