#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int pre[100],rank[100];
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
    int n,m,sum,a,b,c,k;
    while(cin>>n,n)
    {
        sum=0;
        cin>>m;
        if(m)
        {
	        for(int i=0;i<m;i++)
	        {
	        scanf("%d%d%d",&str1[i].x,&str1[i].y,&str1[i].len);    
	        }
	        qsort(str1,m,sizeof(str),cmp);
	        for(int i=1;i<=n;i++)
	        {
	            pre[i]=i;
	            rank[i]=0;            
	        }
	        
	        for(int i=0;i<m;i++)
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
		}
        printf("%d\n",sum);
    
    }    
return 0;    
}
