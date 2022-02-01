#include"iostream"
#include"cstdlib"
#define MAX_SIZE 10001
#define WORD_SIZE 10
using namespace std;
int idx,n;
char str[MAX_SIZE][WORD_SIZE];
struct Tree_Node{
     bool exist;
     Tree_Node *next[WORD_SIZE];
     void init();  
}trie[MAX_SIZE*WORD_SIZE],root;
void Tree_Node::init(){
    exist=false;
    for(int i=0;i<WORD_SIZE;i++)next[i]=NULL;
}
bool insert(char *s){
    int i,j;
    Tree_Node *p=&root;
    for(i=0;s[i];i++){
       j=s[i]-'0';
       if(p->next[j]==NULL){
          trie[idx].init();
          p->next[j]=&trie[idx++];
       }
       else if(i==strlen(s)-1)return false;
       p=p->next[j];
       if(p->exist)return false;
    }
    p->exist=true;
    return true;
}
int main(){
    int T;
    bool flag;
  //  freopen("phone.in","r",stdin);
 //   freopen("3630out.txt","w",stdout);
    scanf("%d",&T);
    while(T--){
       idx=0;
       flag=true;
       root.init();
       scanf("%d",&n);
       for(int i=0;i<n;i++){
          scanf("%s",str[i]);
          if(flag){
              if(!insert(str[i]))flag=false;
          }
       }
       if(flag)printf("YES\n");
       else printf("NO\n");
    }
 //   system("pause");
    return 0;
}
