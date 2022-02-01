#include"iostream"
#include"cstdio"
#include"cstdlib"
#include"string.h"
#define MAXN 500001
#define WORD_LEN 10
#define WORD_SIZE 26
using namespace std;
int idx,id,degree[MAXN],parents[MAXN];
struct Trie_Node{
   int num;
   Trie_Node *next[WORD_SIZE];
   void init();
}trie[MAXN*WORD_LEN],root;
void Trie_Node::init(){
     num=-1;
    // memset(next,NULL,sizeof(next));
}
int insert(char *s){
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
   if(p->num==-1){
      p->num=id++;
      return p->num;
   }
   else return p->num;
}
int Find(int a){
    int x=a,tmp;
    while(parents[a]>=0)a=parents[a];
    while(parents[x]!=a && parents[x]>=0){
       tmp=parents[x];
       parents[x]=a;
       x=tmp;
    }
    return a;
}
void Union(int a,int b){
    if(parents[a]<parents[b]){
        parents[a]+=parents[b];
        parents[b]=a;
    }
    else{
         parents[b]+=parents[a];
         parents[a]=b;
    }
}
char s1[20],s2[20];
int main(){
    int id1,id2,r1,r2,cnt=0;
    idx=id=0;
    memset(parents,0xff,sizeof(parents));
    while(~scanf("%s%s",s1,s2)){
      // if(s1[0]=='0')break;
       id1=insert(s1);
       id2=insert(s2);
       degree[id1]++;
       degree[id2]++;
       r1=Find(id1);
       r2=Find(id2);
       if(r1!=r2)Union(r1,r2);
    }
    //cout<<id<<endl;
    if(id==0)printf("Possible\n");
    else if(parents[Find(0)]!=-id)printf("Impossible\n");
    else{
       for(int i=0;i<id;i++){
         if(degree[i]&1)cnt++;
         if(cnt>2)break;
       }
       if(cnt<=2)printf("Possible\n");
       else printf("Impossible\n");
    }
   // system("pause");
    return 0;
}
