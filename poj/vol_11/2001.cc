#include"iostream"
#include"cstdlib"
#define MAX_SIZE 1005
#define WORD_SIZE 26
#define WORD_LEN 21
using namespace std;
char str[MAX_SIZE][WORD_LEN];
int cnt,idx;
struct Trie_Node{
    int visited;
    Trie_Node *next[WORD_SIZE];
    void inti();
}trie[MAX_SIZE*WORD_LEN],root;
void Trie_Node::inti(){
    memset(next,NULL,sizeof(next));
}
void insert(char *s){
    int i,j;
    Trie_Node *p=&root;
    for(i=0;s[i];i++){
       j=s[i]-'a';
       if(p->next[j]==NULL){
          trie[idx].inti();
          p->next[j]=&trie[idx++];
       }
       p=p->next[j];
       p->visited++;
    }
}
void prefiexs(char *s){
    int i,j;
    Trie_Node *p=&root;
    printf("%s ",s);
    for(i=0;s[i];i++){
       j=s[i]-'a';
       if(p->visited==1){
          break;
       }
       p=p->next[j];
       printf("%c",s[i]);
    }
    printf("\n");
}
int main(){
    idx=cnt=0;
    while(scanf("%s",str[cnt])!=EOF){
         insert(str[cnt++]);
    }
    for(int i=0;i<cnt;i++){
         prefiexs(str[i]);
    }
    return 0;
}
