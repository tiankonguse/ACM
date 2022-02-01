#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pre[102],rank[102];
struct str
{
int x,y,len    ;
}str1[5000]; 


int cmp(void const *a,void const *b)
{
    return (((struct str *)a)->len) - (((struct str *)b)->len);        
}


int find(int x)
{
    if(pre[x]!=x)
    pre[x]=find(pre[x]);    
    return pre[x];    
}


int main()
{
    int n,m,sum,i,j,a,b,p;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            pre[i]=i;
            rank[i]=0;            
        }
        m=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
			{
                scanf("%d",&p);
				if(i<j)
				{
					str1[m].x=i;
					str1[m].y=j;
					str1[m].len=p;					
					m++;
				}
			}
 
        qsort(str1,m,sizeof(str),cmp);
        
        for(i=0;i<m;i++)
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
