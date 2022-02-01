#include<stdio.h>
const int N=1015;
int str[N];
int n,k;

void restr(int begin)
{
	int end=n-1;
	int p;
	while(end>begin)
	{
		p=str[end];
		str[end]=str[begin];
		str[begin]=p;
		end--;
		begin++;
	}
	
}

int find(int p,int begin,int end)
{
	if(begin==end)return begin;
	if(begin+1==end)
	{
		if(str[end]>str[p])return end;
		return begin;
	}
	
	int mid=(begin+end)/2;
	if(str[mid]<=str[p])return find(p,begin,mid-1);
	return find(p,mid,end);
}


void serch(int p)
{
	int p0=find(p-1,p,n-1);//find the first number that is bigger than the value of str[p-1]
	int p1=str[p-1];
	str[p-1]=str[p0];
	str[p0]=p1;
}

void next()
{
	int i=n-1;	
	while(i && str[i-1]>=str[i])i--;
	if(i==0){restr(0);return ;}
	serch(i);
	restr(i);			
}

void print()
{
	printf("%d",str[0]);
	for(int i=1;i<n;i++)
	{
		printf(" %d",str[i]);
	}
	printf("\n");
}

int main()
{

	scanf("%d",&n);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;i++)scanf("%d",&str[i]);	
		if(n!=1)
		{
			while(k--)
			{
				next();	
			}		
		}

		
		print();
	}
return 0;	
}