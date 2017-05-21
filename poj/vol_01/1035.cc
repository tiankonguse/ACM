#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include"iostream"
#define WORD_LEN 20
#define MAX_WORD 26
#define MAXN 10100
using namespace std;
struct Trie_Node{
    int id;
    Trie_Node *next[MAX_WORD];
    void init(){
         id=-1;
         memset(next,NULL,sizeof(next));
    }
}trie[MAXN*WORD_LEN],root;
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
int query(char* s){
    int i,j;
    Trie_Node *p=&root;
    for(i=0;s[i];i++){
        j=s[i]-'a';
        if(p->next[j]==NULL){
            return -1;
        }
        p=p->next[j];
    }
    return p->id;
}
void init(){
    root.init();
    tidx=cnt=0;
}

int res[MAXN];
bool used[MAXN];

char dat[MAXN][WORD_LEN];
char s[WORD_LEN],t[WORD_LEN];

int main(){
    init();
    while(scanf(" %s",dat[cnt])){
        if(dat[cnt][0]=='#')break;
        insert(dat[cnt]);
    }
    while(scanf(" %s",s)){
        if(s[0]=='#')break;
        if(query(s)!=-1){
            printf("%s is correct\n",s);
        }
        else{
            int rnt=0,id;
            memset(used,false,sizeof(used));
            int len=strlen(s);
            for(int i=0;i<len;i++){
                for(int j=0;j<i;j++){
                    t[j]=s[j];
                }
                for(int j=i+1;j<len;j++){
                    t[j-1]=s[j];
                }
                t[len-1]='\0';
                id=query(t);
                if(id!=-1){
                    if(!used[id]){
                        res[rnt++]=id;
                        used[id]=true;
                    }
                }
            }
            for(int i=0;i<len;i++){
                for(char c='a';c<='z';c++){
                    for(int j=0;j<i;j++){
                        t[j]=s[j];
                    }
                    t[i]=c;
                    for(int j=i+1;j<len;j++){
                        t[j]=s[j];
                    }
                    t[len]='\0';
                    id=query(t);
                    if(id!=-1){
                        if(!used[id]){
                            res[rnt++]=id;
                            used[id]=true;
                        }
                    }
                }
            }
            for(int i=0;i<=len;i++){
                for(char c='a';c<='z';c++){
                    for(int j=0;j<i;j++){
                        t[j]=s[j];
                    }
                    t[i]=c;
                    for(int j=i;j<len;j++){
                        t[j+1]=s[j];
                    }
                    t[len+1]='\0';
                    id=query(t);
                    if(id!=-1){
                        if(!used[id]){
                            res[rnt++]=id;
                            used[id]=true;
                        }
                    }
                }
            }
            sort(res,res+rnt);
            printf("%s:",s);
            for(int i=0;i<rnt;i++){
                printf(" %s",dat[res[i]]);
            }
            printf("\n");
        }
    }

    return 0;
}
