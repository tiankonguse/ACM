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
#define maxn 52
#define size 4
#define leng 22
#define maxm 1010
using namespace std;
int chr[128];
int root, idx;
struct trie_node{
    int next[size];
    int fail;
    bool flag;
    void init(){
        fail = -1, flag = false;
        memset(next, 0, sizeof(next));
    }
}trie[maxn * leng];
int q[maxn * leng];
void trie_init(){
    root = idx = 0;
    trie[root].init();
}
void insert(char *s){
    int i, j, p = root;
    for(i=0;s[i];i++){
        j = chr[ s[i] ];
        if(!trie[p].next[j]){
            trie[++idx].init();
            trie[p].next[j] = idx;
        }
        p = trie[p].next[j];
    }
    trie[p].flag = true;
}
void build(){
    int j, p;
    q[0] = root;
    for(int l=0,h=1;l<h;){
        p = q[l++];
        for(j=0;j<size;j++){
            if(trie[p].next[j]){
                q[h++] = trie[p].next[j];
                if(trie[p].fail == -1) trie[trie[p].next[j]].fail = root;
                else{
                    trie[trie[p].next[j]].fail = trie[trie[p].fail].next[j];
                    trie[trie[p].next[j]].flag |= trie[trie[trie[p].fail].next[j]].flag;
                }
            }
            else{
                if(trie[p].fail != -1) trie[p].next[j] = trie[trie[p].fail].next[j];
            }
        }
    }
}
char word[leng];
char str[maxm];
int dp[maxm][maxn * leng];
char cst[10];
int main(){
    chr['A'] = 0, chr['G'] = 1, chr['T'] = 2, chr['C'] = 3;
    cst[0] = 'A', cst[1] = 'G', cst[2] = 'T', cst[3] = 'C';
    int n, m, t, _ca = 1;
    while(scanf("%d", &n) && n){
        trie_init();
        for(int i=0;i<n;i++){
            scanf(" %s", word);
            insert(word);
        }
        build();
        scanf(" %s", str);
        m = strlen(str);
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<=idx;j++){
                if(dp[i][j] <= m && !trie[j].flag){
                    for(int k=0;k<4;k++){
                        t = trie[j].next[k];
                        if(!trie[t].flag){
                            dp[i + 1][t] = min(dp[i + 1][t], dp[i][j] + (cst[k] != str[i]));
                        }
                    }
                }
            }
        }
        int res = inf;
        for(int i=0;i<=idx;i++){
            if(!trie[i].flag) res = min(res, dp[m][i]);
        }
        printf("Case %d: ", _ca++);
        if(res > m) puts("-1");
        else printf("%d\n", res);
    }
    return 0;
}
