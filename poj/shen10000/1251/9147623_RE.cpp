#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int k;
int pre[100],rank[100];
bool map[100];
struct str
{
int x,y,len    ;
}str1[80]; 


int cmp(void const *a,void const *b)
{
    return (((struct str *)a)->len) - (((struct str *)b)->len);        
}

void insert(int x1,int y1,int len1)
{
    str1[k].x=x1;    
    str1[k].y=y1;    
    str1[k].len=len1;    
    k++;
}

int find(int x)
{
    if(pre[x]!=x)
    pre[x]=find(pre[x]);    
    return pre[x];    
}


int main()
{
    int n,m,p,sum;
    char c1,c2;
    while(scanf("%d",&n),n)
    {
        sum=k=0;
        
        for(int i=0;i<n-1;i++)
        {
            getchar();
            c1=getchar();
            c1-='A';    
            scanf("%d",&m);
            while(m--)
            {
                getchar();
                c2=getchar();
                scanf("%d",&p);
                insert(c1,c2-'A',p);    
            }        
        }
        qsort(str1,k,sizeof(str),cmp);
        for(int i=0;i<n;i++)
        {
            map[i]=false;
            pre[i]=i;
            rank[i]=0;            
        }
        
        for(int i=0;i<k;i++)
        {
        
        int a=find(str1[i].x);
        int b=find(str1[i].y);
        
        if(a==b)continue;
        n--;
        sum+=str1[i].len;
        if(n==1)break;
        
        if(rank[a]>rank[b])pre[b]=a;
        else{pre[a]=b;if(rank[a]==rank[b])rank[b]++;}
        }
        printf("%d\n",sum);
    
    }    
return 0;    
}
