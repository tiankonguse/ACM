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
#define maxn 610
#define size 26
#define leng 12
#define maxl 110
using namespace std;
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
        j = s[i] - 'A';
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
int dp[maxl][maxn * leng];
int main(){
    int n, l, m, tl, t;
    while(~scanf("%d%d%d", &n, &l, &m)){
        if(n == 0 && l == 0 && m == 0) break;
        trie_init();
        for(int i=0;i<m;i++){
            scanf(" %s", word);
            insert(word);
        }
        tl = strlen(word);
        build();
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i=0;i<l;i++){
            for(int j=0;j<=idx;j++){
                if(dp[i][j] && (i < tl || trie[j].flag)){
                    for(int k=0;k<size;k++){
                        t = trie[j].next[k];
                        if(t && (i + 1 < tl || trie[t].flag)){
                            dp[i+1][t] += dp[i][j];
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<=idx;i++){
            if(trie[i].flag) res += dp[l][i];
        }
        printf("%d\n", res);
    }
    return 0;
}
