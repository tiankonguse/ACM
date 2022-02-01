#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 100100
#define word_len 8
#define max_word 28
using namespace std;
int parents[maxn];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}
void init(){
    memset(parents, 0xff, sizeof(parents));
}

struct tnode {
    int id, val;
    tnode *next[max_word];
    void init(int a) {
        id = -1;
        val = a;
        memset(next, NULL, sizeof next);
    }
} trie[maxn * word_len], root;
int tidx;
void insert(char *s, int num) {
    int i, j;
    tnode *p = &root;
    for (i = 0; s[i]; ++i) {
        if (s[i] == '?') j = 26;
        else if (s[i] == '*') j = 27;
        else j = s[i] - 'a';
        if (p -> next[j] == NULL) {
            trie[tidx].init(j);
            p -> next[j] = &trie[tidx++];
        }
        p = p -> next[j];
    }
    if (p -> id == -1) p -> id = num;
    else {
        Union( Find(p -> id), num );
    }
}
void tinit() {
    root.init(-1);
    tidx = 0;
}

char str[22];
int s[22];

bool used[maxn];
int res[maxn], rnt, len;

inline void push(int id) {
    id = Find(id);
    if (!used[id]) {
     //   printf("push(%d)\n", id);
        res[rnt++] = id;
        used[id] = true;
    }
}
inline char chg(int x) {
    if (x < 26) return x + 'a';
    if (x == 26) return '?';
    if (x == 27) return '*';
}
void dfs(int pos, tnode *p) {
  //  printf("dfs(%d, %c)\n", pos, chg(p -> val) );
    if (p -> id != -1) {
        if (p -> val == 27 || pos == len) {
            push(p -> id);
        }
    }

    if (p -> next[ 27 ] != NULL) {
        for (int i = pos; i <= len; ++i) {
            dfs(i, p -> next[27]);
        }
    }
    if (pos == len) return;
    if (p -> next[ s[pos] ] != NULL) {
        dfs(pos + 1, p -> next[ s[pos] ]);
    }
    if (p -> next[ 26 ] != NULL) {
        dfs(pos + 1, p -> next[26]);
    }

}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        tinit();
        init();
        for (int i = 0; i < n; ++i) {
            scanf(" %s", str);
            insert(str, i);
        }
        for (int i = 0; i < m; ++i) {
            memset(used, false, sizeof used);
            rnt = 0;
            scanf(" %s", str);
            len = strlen(str);
            for (int j = 0; j < len; ++j) {
                if (str[j] == '?') s[j] = 26;
                else if (str[j] == '*') s[j] = 27;
                else s[j] = str[j] - 'a';
            }
            dfs(0, &root);
            if (rnt == 0) puts("Not match");
            else {
                for (int j = 0; j < n; ++j) {
                    if (!used[j] && used[Find(j)]) res[rnt++] = j;
                }
                sort(res, res + rnt);
                for (int j = 0; j < rnt; ++j) {
                    if (j == rnt - 1) printf("%d\n", res[j]);
                    else printf("%d ", res[j]);
                }
            }
        }
    }
    return 0;
}
