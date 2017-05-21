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
typedef long long ll;
#define maxn 50050
#define WORD_LEN 222
#define MAX_WORD 28 
using namespace std;
struct Trie_Node{
    int id;
    Trie_Node *next[MAX_WORD];
    void init(){
         id=-1;
         memset(next,NULL,sizeof(next));
    }
}trie[maxn*WORD_LEN],root;
int tidx,cnt;
int insert(char* s){
    int i,j;
    Trie_Node *p=&root;
    for(i=0;s[i];i++){
        if (s[i] == '-') j = 26;
  	else if (s[i] == '\'') j = 27;
		else j = s[i] - 'a';
        if(p->next[j]==NULL){
            trie[tidx].init();
            p->next[j]=&trie[tidx++];
        }
        p=p->next[j];
    }
    if(p->id==-1)p->id=cnt++;
    return p->id;
}
bool query(char* s){
    int i,j;
    Trie_Node *p=&root;
    for(i=0;s[i];i++){
        if (s[i] == '-') j = 26;
		else if (s[i] == '\'') j = 27;
		else j = s[i] - 'a';
        if(p->next[j]==NULL){
            return false;
        }
        p=p->next[j];
    }
	return p->id != -1;
}
void init(){
    root.init();
    tidx=cnt=0;
}

char str[222];
int main() {
	int n, m;
	init();
	for (scanf("%d", &n); n--; ) {
		scanf(" %s", str);
		insert(str);
	}
	scanf("%d", &m);
	bool flag(true);
	for (int i = 1; i <= m; ) {
		scanf(" %s", str);
		if (strcmp(str, "-1") == 0) {
			if (flag) {
				printf("Email %d is spelled correctly. \n", i);
			}
			flag = true;
			++i;
		}
		else
		if (!query(str)) {
			if (flag) {
				flag = false;
				printf("Email %d is not spelled correctly.\n", i);
			}
			puts(str);
		}
	}
	printf("End of Output\n");

    return 0;
}
