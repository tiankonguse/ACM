#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM  130
typedef struct tnode{
        int _count;
        struct tnode *next[MAXNUM];     //slibing nodes
}t_node;
int insert(const char* str,t_node *node){
        char *pos=str;
//      int i;
        t_node *nextnode,*curnode=node;
        if(*pos==0) return 0;
        for(;*pos;pos++){               //util the end of the string
                if(curnode->next[*pos]==NULL){          //if not exits
                        curnode->next[*pos]=(t_node *)malloc(sizeof(t_node));
                        memset(curnode->next[*pos],0,sizeof(t_node));
                }
                nextnode=curnode->next[*pos];           //change the node
                curnode=nextnode;
        }
        curnode->_count++;
        printf("str is :%s total:%d \n",str,curnode->_count);
        return 0;
}
void destory(t_node *node){
        int i;
        for(i=0;i<MAXNUM;i++){
                if(node->next[i]){
                        destory(node->next[i]);
                        free(node->next[i]);    //recursion
                }
        }
}
int main(){
        t_node root;
        char buffer[MAXNUM];
        memset(&root,0,sizeof(t_node));
        while(fgets(buffer,MAXNUM,stdin)!=NULL){
                buffer[strlen(buffer)-1]=0;
                printf("begin to handle %s\n",buffer);
                insert(buffer,&root);
        }
        destory(&root);
return 0;
}
