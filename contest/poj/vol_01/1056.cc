#include"iostream"
#include"cstdlib"
#define MAXN 10005
#define WORD_LEN 11
using namespace std;
int idx;
struct Trie_node{
    bool visited;
    Trie_node *next[2];
    void init();
}trie[MAXN*WORD_LEN],root;
void Trie_node::init(){
    visited=false;
    memset(next,NULL,sizeof(next));
}
bool insert(char* s){
    int i,j;
    Trie_node *p=&root;
    for(i=0;s[i];i++){
        j=s[i]-'0';
        if(p->next[j]==NULL){
            trie[idx].init();
            p->next[j]=&trie[idx++];
        }
        else if(p->next[j]->visited){
            return false;
        }
        p=p->next[j];
    }
    p->visited=true;
    return true;
}
char str[21];
int main(){
    int c=1;
    idx=0;
    bool flag=true;
    while(~scanf(" %s",str)){
       if(str[0]=='9'){
          if(flag){
             printf("Set %d is immediately decodable\n",c++);
          }
          else{
             printf("Set %d is not immediately decodable\n",c++);
          }
          idx=0;
          flag=true;
          root.init();
       }
       else{
          if(!insert(str))flag=false;
       }
    }
    return 0;
}
