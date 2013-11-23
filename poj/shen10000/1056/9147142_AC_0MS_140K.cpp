#include<stdio.h>
#include<string.h>
#include<stdlib.h>
class T{
	public:
    T *next[2];
    T(){next[0]=next[1]=NULL;};
};
T* root;
bool y;

void insert(char *str)
{
    T* p,* newnode;
    int i=0;
    int m=strlen(str);
    p=root;
    for(;*str;str++)
    {
        if(p->next[*str-'0']!=NULL)
        {
			i++;
            p=p->next[*str-'0'];
        }
        else if(i && p->next[0] == NULL && p->next[1] == NULL)
        {
			y=false;
			break;	
		}
		else
        {
			
            newnode=new T;
            p->next[*str-'0']=newnode;
            p=p->next[*str-'0'];
            i=0;
        }

    }
         if(i==m)y=false;
    
}



int main()
{
	int i=0;
    char a[12];
    while(scanf("%s",a)!=EOF)
    {
		i++;
		y=true;
	    root = new T;
	    while(1)
	    {
			if(a[0]=='9')break;
		        if(y)insert(a);
		    scanf("%s",a);
		}
		if(y)printf("Set %d is immediately decodable\n",i);
		else printf("Set %d is not immediately decodable\n",i);
		
		//del();
	
	}
    return 0;
}
