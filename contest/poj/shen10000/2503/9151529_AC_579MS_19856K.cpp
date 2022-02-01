#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct T{
    T *next[26];
    char *p;
    T(){p=NULL;memset(next,0,sizeof(next));};
}*root;


void insert(char *a,char *b)
{
    T *p1,*p2;
    int i;
    p1=root;
    for(;*a;a++)
    {
        if(p1->next[*a-'a']!=NULL)
        {
            p1=p1->next[*a-'a'];
        }
        else
        {
            p2=new T;
            p1->next[*a-'a']=p2;
            p1=p1->next[*a-'a'];
        }
    }
    p1->p =new char[13];
    strcpy(p1->p,b);
    
}

char* find(char *str)
{
    T* p1=root;
    for(;*str;str++)
    {
        if(p1->next[*str-'a']!=NULL)
            p1=p1->next[*str-'a'];
        else return NULL;
    }
    return p1->p;
}
int main()
{
    char a[30],c[12],b[12];

    root = new T;
    while(1)
    {
		gets(a);
		if(strlen(a)==0)break;		
		sscanf(a,"%s%s",b,c);

        insert(c,b);
	
	}
	while(scanf("%s",a)!=EOF)
	{
		char *p=find(a);
		if(p==NULL)printf("eh\n");
		else printf("%s\n",p);
		
	}
 return 0;
}
