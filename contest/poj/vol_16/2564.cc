#include"iostream"
#include"cstdlib"
#define max(a,b) (a>b?a:b)
#define MAX_SIZE 25001
#define WORD_SIZE 26
#define WORD_LEN 17
using namespace std;
int dp[MAX_SIZE];
int idx,cnt;
struct Trie_Node{
    int num;
    Trie_Node *next[WORD_SIZE];
    void init();
}trie[MAX_SIZE*WORD_LEN],root;
void Trie_Node::init(){
    num=-1;
    memset(next,NULL,sizeof(next));
}
void insert(char *s,int k){
    int i,j;
    Trie_Node *p=&root;
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
    Trie_Node *p=&root;
    for(i=0;s[i];i++){
       j=s[i]-'a';
       if(p->next[j]==NULL)return -1;
       p=p->next[j];
    }
    return p->num;
}
int main(){
    idx=0,cnt=0;
    int i,k,len,r,res=0;
    char j;
    char word[WORD_LEN],tmp[WORD_LEN];
    memset(dp,0,sizeof(dp));
    while(scanf("%s",word)!=EOF){
       //if(word[0]=='.')break;
          len=strlen(word);
          insert(word,cnt);
          memcpy(tmp,word,sizeof(word));
          //mdf
          for(i=0;i<len;i++){
             for(j='a';j<word[i];j++){
                 tmp[i]=j;
                 r=find(tmp);
                 if(r!=-1){
                     dp[cnt]=max(dp[cnt],dp[r]+1);
                 }
             }
             tmp[i]=j;
          }
          //add
          memcpy(tmp+1,word,sizeof(word));
          for(i=0;i<len;i++){
             for(j='a';j<word[i];j++){
                tmp[i]=j;
                r=find(tmp);
                if(r!=-1){
                     dp[cnt]=max(dp[cnt],dp[r]+1);
                }
             }
             tmp[i]=j;
          }
          //del
          int now=0;
          for(i=0;i<len;i++){
             now=0;
             for(k=0;k<len;k++){
                if(k!=i)tmp[now++]=word[k];
             }
             tmp[now]='\0';
             if(strcmp(tmp,word)>0)continue;
             r=find(tmp);
             if(r!=-1){
                 dp[cnt]=max(dp[cnt],dp[r]+1);
             }            
          }
          if(dp[cnt]>res)res=dp[cnt];
          cnt++;
    }
    printf("%d\n",res+1);
    return 0;
}
