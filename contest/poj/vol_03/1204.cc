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
#define maxn 1010
#define size 26
#define leng 1010
using namespace std;
int root, idx;
struct trie_node{
    int next[size];
    int fail, id;
    void init(){
        fail = -1, id = 0;
        memset(next, 0, sizeof(next));
    }
}trie[maxn * leng], *q[maxn * leng], *tmp;
void init(){
    root = idx = 0;
    trie[root].init();
}
void insert(char *s, int id){
    int i, j, p = root;
    for(i=0;s[i];i++){
        j = s[i] - 'A';
        if(!trie[p].next[j]){
            trie[++idx].init();
            trie[p].next[j] = idx;
        }
        p = trie[p].next[j];
    }
    trie[p].id = id;
}
void build(){
    int j, l = 0, h = 1;
    q[0] = &trie[root];
    while(l < h){
        tmp = q[l++];
        for(j=0;j<size;j++){
            if(tmp->next[j]){
                q[h++] = &trie[tmp->next[j]];
                if(tmp->fail == -1) trie[tmp->next[j]].fail = root;
                else trie[tmp->next[j]].fail = trie[tmp->fail].next[j];
            }
            else{
                if(tmp->fail != -1) tmp->next[j] = trie[tmp->fail].next[j];
            }
        }
    }
}

char mp[maxn][maxn];
char word[maxn][maxn];
bool mark[maxn];
int lens[maxn];
int res[maxn][3];
int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
int r, c, n, tn;
bool check(int x, int y){
    if(x >= 0 && x < r && y >= 0 && y < c) return true;
    else return false;
}
void query(int x, int y, int d){
    int i, j, p = root, t, id;
    while(check(x, y)){
       // cout<<x<<","<<y<<endl; system("pause");
        j = mp[x][y] - 'A';
        while(!trie[p].next[j] && p != root) p = trie[p].fail;
        if(trie[p].next[j]){
            p = trie[p].next[j], t = p;
            while(t > root){
                if(id = trie[t].id){
                    if(!mark[id]){
                        mark[id] = true;
                        tn++;
                        res[id][0] = x - (lens[id] - 1) * dir[d][0];
                        res[id][1] = y - (lens[id] - 1) * dir[d][1];
                        res[id][2] = d;
                    }
                }
                t = trie[t].fail;
            }
        }
        x += dir[d][0];
        y += dir[d][1];
    }
}
int main(){
    while(~scanf("%d%d%d", &r, &c, &n)){
        for(int i=0;i<r;i++) scanf(" %s", mp[i]);
        init();
        for(int i=1;i<=n;i++){
            scanf(" %s", word[i]);
            lens[i] = strlen(word[i]);
            insert(word[i], i);
        }
        build();
        memset(mark, false, sizeof(mark));
        tn = 0;
        for(int i=0;i<r;i++){
            query(i, 0, 1); if(tn == n) break;
            query(i, 0, 2); if(tn == n) break;
            query(i, 0, 3); if(tn == n) break;
            query(i, c - 1, 5); if(tn == n) break;
            query(i, c - 1, 6); if(tn == n) break;
            query(i, c - 1, 7); if(tn == n) break;
        }
        for(int i=0;i<c;i++){
            query(0, i, 3); if(tn == n) break;
            query(0, i, 4); if(tn == n) break;
            query(0, i, 5); if(tn == n) break;
            query(r - 1, i, 7); if(tn == n) break;
            query(r - 1, i, 0); if(tn == n) break;
            query(r - 1, i, 1); if(tn == n) break;
        }
        for(int i=1;i<=n;i++){
            printf("%d %d %c\n", res[i][0], res[i][1], res[i][2] + 'A');
        }
    }
    return 0;
}
