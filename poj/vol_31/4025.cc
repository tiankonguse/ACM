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

#define maxn 10100
#define WORD_LEN 44
#define MAX_WORD 26
using namespace std;
typedef __int64 ll;
struct _trie {
    struct Trie_Node{
        int id;
        Trie_Node *next[MAX_WORD];
        void init(){
             id=-1;
             memset(next,NULL,sizeof(next));
        }
    }trie[maxn * WORD_LEN],root;
    int acnt[26];
    int tidx,cnt;
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
        if(p->id==-1)p->id=cnt++;
        return p->id;
    }
    void cont() {
        for (int i = 0; i < tidx; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (trie[i].next[j] != NULL) ++acnt[j];
            }
        }
    }
    void init() {
        root.init();
        tidx=cnt=0;
        memset(acnt, 0, sizeof acnt);
    }
}t1, t2;

char str[1010];
bool mark[26];
int main() {
    int n, m;
    while (~scanf("%d", &n)) {
        t1.init(), t2.init();
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < n; ++i) {
            scanf(" %s", str);
            if (strlen(str) == 1) mark[str[0] - 'a'] = true;
            t1.insert(str);
            reverse(str, str + strlen(str));
            t2.insert(str);
        }

        ll ret = 1LL * t1.tidx * t2.tidx;
        t1.cont(), t2.cont();
        for (int i = 0; i < 26; ++i) {
            ret += mark[i];
            ret -= 1LL * t1.acnt[i] * t2.acnt[i];
        }
        printf("%I64d\n", ret);
    }
    return 0;
}
