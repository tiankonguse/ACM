#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=65;
class T{public:int l,num;}str[N];
int ss[N];
int n,len,k,num;
int cmp(const void *a,const void *b)
{
return ((T*)b)->l - ((T*)a)->l;	
}

bool dfs(int left,int i,int tatol)
{
	if(i==tatol)return true;
	
	for(int j=i;j<k;j++)
	{
		const int &l=str[j].l;
		int &numb=str[j].num;
		if(numb==0 || l>left)continue;
		numb--;
		if(l==left)
		{
			if(dfs(len,0,tatol+1))return true;
			numb++;	return false;	
		}
		if(dfs(left-l,i,tatol))return true;
		numb++;
		if(left == len || j+1==k)return false;
	}	
return false;	
}

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		memset(ss,-1,sizeof(ss));
		k=0;
		int sum=0;
		while(n--)
		{
			scanf("%d",&len);	
			sum+=len;
			if(ss[len]==-1){str[k].l=len;str[k].num=1;ss[len]=k;k++;}
			else str[ss[len]].num++;
		}	
		qsort(str,k,sizeof(T),cmp);	
		
		for(int i=str[0].l;i<=sum;i++)
		{
			while(sum%i)i++;	
			num=sum/i;
			len=i;
			if(dfs(len,0,0))
			{
				printf("%d\n",i);break;	
			}
		}	
	}
		
return 0;	
}
