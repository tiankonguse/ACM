#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct T
{
    char *p;
    T *next[26];     
	T(){p=NULL;memset(next,0,sizeof(next));}
}*root;

void insert(char *c,char *b)
{
       T *p1 = root;
       for(;*c;c++)
       {
			  int m = *c - 'a';
              if(!p1->next[m])//null&node[++cnt]
              {
				T *node=new T;
			    p1->next[m] = node;
			  }
              p1 = p1->next[m];
       }
      p1->p = new char[13];
      strcpy(p1->p,b);
}


char* find(char *str)
{
       T * p1 = root;
       while(*str)
       {

              if(!p1->next[*str - 'a'])
                     return NULL;
              p1 = p1->next[*str - 'a'];
              str++;
       }
       return p1->p;
}

int main()
{
char a[33],b[12],c[12];
root=new T;
while(1)
{
	gets(a);
	if(strlen(a)==0)break;
	sscanf(a,"%s%s",b,c);
	//printf("%s  %s\n",b,c);
	insert(c,b);		
} 

while(scanf("%s",a)!=EOF)
{
char *p2=find(a);
if(p2)printf("%s\n",p2);
else printf("eh\n");	
	
}
    
       //system("pause");
       return 0;
}
