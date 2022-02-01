#include<stdio.h>
#include<stdlib.h>
int n,d;
struct T{int x,y;}str[1010],*a,*b;
int cmp(void const *aa,void const *bb)
{
	a=	(struct T*)aa;
	b=	(struct T*)bb;
	if(a->x==b->x)return a->y - b->y;
	return a->x - b->x;	
}


bool OOK(int &now, int k)
{
	int xy=(str[k].x-now)*(str[k].x-now)+str[k].y*str[k].y;
	if(xy<=d)return true;
	return false;		
}

int find(int k)
{
	int now=str[k].x;
	while(OOK(now,k))now++;
	return now-1;	
}

bool ok(int &now,int k)
{
if(OOK(now,k))return true;
if(now<str[k].x)return false;
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
		d=d*d;
		qsort(str,n,sizeof(struct T),cmp);
	//	printf("\n");
	//	for(int i=0;i<n;i++)printf("%d  %d\n",str[i].x,str[i].y);
	//	printf("\n");
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
/*
2 5
-3 4
-6 3


4 5
-5 3
-3 5
2 3
3 3

20 8
-20 7
-18 6
-5 8
-21 8
-15 7
-17 5
-1 5
-2 3
-9 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 7
9 6
10 5
0 0

2 3
0 2
2 3

2 3
0 2
1 3

3 3
1 2
-3 2
2 4

8 5
2 4
-4 4
-3 3
-3 1
-3 0
-1 0
0 5
6 0

3 0
1 2
-3 1
2 1

3 2
1 2
-3 1
2 1

1 2
0 2


2 3
0 2
2 3

4 -5
4 3
4 3
2 3
6 -9



3 -3
1 2
-3 2
2 1

6 2
1 2
1 2
1 2
-3 1
2 1
0 0

1 2
0 2

2 3
0 2
1 3

3 10
1 10
2 3
4 5

3 5
1 10
2 3
4 5

4 7
1 10
2 3
4 5
0 0

3 9
1 10
2 3
4 5


*/
