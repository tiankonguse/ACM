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
#define maxn 30010
#define word_len 32
#define word_size 26
using namespace std;
struct Trie_Node{
    int id;
    Trie_Node *next[word_size];
    void init(){
         id = -1;
         memset(next,NULL,sizeof(next));
    }
}trie[maxn * word_len],root;
int tidx, tcnt;
int insert(char* s){
    int i,j;
    Trie_Node *p=&root;
    for(i=0;s[i];i++){
        j=s[i]-'a';
        if(p->next[j]==NULL){
            trie[tidx].init();
            p->next[j]=&trie[tidx++];
        }
        p=p->next[j];
    }
    if(p->id==-1) p->id = tcnt++;
    return p->id;
}
void init(){
    root.init();
    tidx = tcnt = 0;
}
int cmp(const void *a, const void *b)
{
  char *x=(char *)a;
	char *y=(char *)b;
	return strcmp(x, y);
}

char str[maxn][word_len];
char tmp[word_len];
int cnt[maxn];

struct node{
    int id, idx;
    friend bool operator<(node a, node b){
        if(cnt[a.id] == cnt[b.id]){
            if(a.id == b.id) return a.idx < b.idx;
            else return a.id < b.id;
        }
        else return cnt[a.id] > cnt[b.id];
    }
}p[maxn];
int main(){
    int n = 0;
    while(~scanf("%s", str[n])) n++;
    qsort(str, n, sizeof str[0], cmp);
    init();
    memset(cnt, 0, sizeof cnt);
    for(int i=0;i<n;i++){
        memcpy(tmp, str[i], sizeof str[i]);
        sort(tmp, tmp + strlen(tmp));
        p[i].id = insert(tmp);
        p[i].idx = i;
        cnt[ p[i].id ]++;

    }
    sort(p, p + n);
    int pos = 0, sz;
    for(int k=0;k<5;k++){
        sz = cnt[ p[pos].id ];
        printf("Group of size %d: ", sz);
        for(int i=0;i<sz;i++){
            if(pos == 0 || strcmp(str[ p[pos - 1].idx ], str[ p[pos].idx ]) != 0)
                printf("%s ", str[ p[pos].idx ]);
            pos++;
        }
        puts(".");
    }
    return 0;
}
