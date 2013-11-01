#include <stdio.h>
#include <stdlib.h>

struct Edge
{
	int from,to,len;
}edge[200];

int n,father[100];

int find(int x)
{
	int temp,root=x;
	while(root!=father[root])
	{
		root=father[root];
	}
	while(x!=root)
	{
		temp=father[x];
		father[x]=root;
		x=temp;
	}
	return root;
}

int Kruskal()
{
	int i,root1,root2,count=0,ans=0;
	for(i=0;count<n-1;i++)
	{
		root1=find(edge[i].from),root2=find(edge[i].to);
		if(root1!=root2)
		{
			father[root1]=root2;
			count++;
			ans+=edge[i].len;
		}
	}
	return ans;
}

int cmp(const void *a,const void *b)
{
	return (*(struct Edge *)a).len - (*(struct Edge *)b).len;
}

int main()
{
	int i,j,m,t,c,c1,count;
	while(scanf("%d",&n),n)
	{
		getchar();
		for(i=1;i<=n;i++)
		{
			father[i]=i;
		}
		for(count=0,i=1;i<n&&scanf("%c%c%d",&c,&c1,&m);i++)
		{
			getchar();
			for(j=1;j<=m;j++)
			{
				scanf("%c%c%d",&c,&c1,&edge[count].len);
				edge[count].from=i,edge[count].to=c-'A'+1;
				count++;
				getchar();
			}
		}
		qsort(edge,count,sizeof(edge[0]),cmp);
		printf("%d\n",Kruskal());
	}
	return 0;
}
