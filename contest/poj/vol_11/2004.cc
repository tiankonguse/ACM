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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 10100;
int const leng = 22;
int const maxc = 26;

struct trie_node {
    int id, mx, nxt;
    trie_node *next[maxc];
    void init() {
        id = -1;
        memset(next, NULL, sizeof next);
    }
} trie[maxn * leng], root;
int idx;
void init() {
    root.init();
    idx = 0;
}
int insert(char *s, int id) {
    trie_node *p = &root;
    for (int i = 0; s[i]; ++i) {
        int j = s[i] - 'a';
        if (p -> next[j] == NULL) {
            trie[idx].init();
            p -> next[j] = &trie[idx++];
        }
        p = p -> next[j];
    }
    if (p -> id == -1) p -> id = id;
    return p -> id;
}

int query(char *s) {
    trie_node *p = &root;
    for (int i = 0; s[i]; ++i) {
        int j = s[i] - 'a';
        if (p -> next[j] == NULL) {
            return -1;
        }
        p = p -> next[j];
    }
    return p -> id;
}
char str[maxn][leng];
struct node {
    char tmp[leng];
    int len, sid;
    friend bool operator < (node a, node b) {
        if (a.len != b.len) return a.len < b.len;
        else return strcmp(a.tmp, b.tmp) < 0;
    }
} s[maxn];
int inv[maxn];
int dp[maxn];
int pre[maxn];
char ts[leng];
int ans[maxn];

int main() {
//    freopen("2004.in","r",stdin);
    init();
    int n = 0;
    while (~scanf("%s", str[n])) {
        memcpy(s[n].tmp, str[n], sizeof str[n]);
        s[n].len = strlen(str[n]);
        sort(s[n].tmp, s[n].tmp + s[n].len);
        s[n].tmp[s[n].len] = 0;
        s[n].sid = insert(s[n].tmp, n);
        inv[s[n].sid] = n;
        ++n;
    }
    sort(s, s + n);
//    for (int i = 0; i < n; ++i) puts( s[i].tmp );
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; ++i) {
        if (s[i].len == 1) dp[s[i].sid] = 1;
        else {
            dp[s[i].sid] = 1;
            for (int j = 0; j < s[i].len; ++j) {
                int cc = 0;
                for (int k = 0; k < s[i].len; ++k) {
                    if (j == k) continue;
                    ts[cc++] = s[i].tmp[k];
                }
                ts[cc] = 0;
                int id = query(ts);
                if (id != -1) {
                    if (dp[s[i].sid] < dp[id] + 1) {
                        dp[s[i].sid] = dp[id] + 1;
                        pre[s[i].sid] = id;
                    }
                }
            }
        }
    }
    int ret = 0, fr;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > ret) {
            ret = dp[i];
            fr = i;
        }
    }
    for (int i = 0; i < ret; ++i) {
        ans[i] = inv[fr];
        fr = pre[fr];
    }
    for (int i = ret - 1; i >= 0; --i) {
        printf("%s\n", str[ans[i]]);
    }
    return 0;
}
