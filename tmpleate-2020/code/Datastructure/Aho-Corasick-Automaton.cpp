struct ACautomaton
{
    int nodecnt;
    int u[N][26] , f[N];
    five val[N];
    queue<int> q;
    int newnode() {
        val[nodecnt] = five();
        memset(u[nodecnt] , 0 , sizeof(u[nodecnt]));
        return nodecnt ++;
    }
    void clear() {
        nodecnt = 0;
        newnode();
    }
    void insert(char str[] , int id) {
        int x = 0;
        for (int i = 0 ; str[i] ; ++ i) {
            int c = str[i] - 'a';
            if (!u[x][c])
                u[x][c] = newnode();
            x = u[x][c];
        }
        val[x].insert(id);
    }
    int query(char *str) {
        int x = 0;
        for (int i = 0 ; str[i] ; ++ i) {
            int c = str[i] - 'a';
            x = u[x][c] , val[x].query();
        }
    }
    void getFail() {
        for (int i = 0 ; i < 26 ; ++ i)
            if (u[0][i])
                f[u[0][i]] = 0 , q.push(u[0][i]);
        while (!q.empty()) {
            int x = q.front() ; q.pop();
            for (int i = 0 ; i < 26 ; ++ i) {
                int y = u[x][i];
                if (!y) {u[x][i] = u[f[x]][i]; continue;}
                q.push(y); int j = f[x];
                while (j && !u[j][i]) j = f[j];
                f[y] = u[j][i] , val[y].update(val[f[y]]);
            }
        }
    }
}heap;
