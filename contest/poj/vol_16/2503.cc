#include"iostream"
#include"string"
#include"cstdlib"
#define MAX_SIZE 100001
#define WORD_SIZE 26
#define WORD_LEN 11
using namespace std;
char str[MAX_SIZE][WORD_LEN]={{"eh"}};
int idx;
struct Tree_Node{
    int num;
    Tree_Node *next[WORD_SIZE];
    void init();
}trie[MAX_SIZE*WORD_LEN],root;
void Tree_Node::init(){
    num=0;
    memset(next,NULL,sizeof(next));
}
void insert(char *s,int k){
    int i,j;
    Tree_Node *p=&root;
    for(i=0;s[i];i++){
        j=s[i]-'a';
        if(p->next[j]==NULL){
            trie[idx].init();
            p->next[j]=&trie[idx++];
        }
        p=p->next[j];
    }
    p->num=k;
}
int find(char *s){
    int i,j;
    Tree_Node *p=&root;
    for(i=0;s[i];i++){
        j=s[i]-'a';
        if(p->next[j]==NULL)return 0;
        p=p->next[j];
    }
    return p->num;
}
int main(){
    char buff[30],word[30];
    idx=0;
    int cnt=1;
    while(gets(buff) && strcmp(buff,"")!=0){
       sscanf(buff,"%s%s",str[cnt],word);
       insert(word,cnt);
       cnt++;
    }
    while(gets(buff)){
       printf("%s\n",str[find(buff)]);
    }
    return 0;
}
