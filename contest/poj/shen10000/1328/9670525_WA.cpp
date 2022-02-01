#include<stdio.h>
#include<stdlib.h>
int n,d,begin;
struct T{int x,y;}str[1010],*a,*b;
int cmp(void const *aa,void const *bb)
{
	a=	(struct T*)aa;
	b=	(struct T*)bb;
	if(a->x==b->x)
	{
	return a->y - b->y;
	}
	return a->x - b->x;	
}


bool OOK(int &now, int k)
{
	int xy=(str[k].x-now)*(str[k].x-now)+str[k].y*str[k].y;
	if(xy>=d*d)return true;
	return false;		
}

int find(int k)
{
	int now=str[k].x;
	while(OOK(now,k))now++;
	return (begin=now-1);	
}

bool ok(int &now,int k)
{
if(OOK(now,k))return true;
if(now<=str[k].x)return false;
now=find(k);
return true;
	
}

int main()
{
	int max,num,now;
	int lll=0;
	while(scanf("%d%d",&n,&d),n)
	{
		lll++;
		max=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&str[i].x,&str[i].y);
			max=max<str[i].y?str[i].y:max;	
		}
		if(max>d){printf("Case %d: -1\n",lll);continue;}
		qsort(str,n,sizeof(struct T),cmp);
		//for(int i=0;i<n;i++)printf("%d  %d\n",str[i].x,str[i].y);
		num=1;
		now=find(0);
		for(int i=0;i<n;i++)
		{
			if(ok(now,i))continue;
			else {num++;now=find(i);}
		}
		printf("Case %d: %d\n",lll,num);
		
		
	}
	
	getchar();
return 0;	
}
