#include<stdio.h>
#include<queue>
using namespace std;
typedef struct{int x,y;}P;

queue<P>que;
P a;
int str3[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
int n,m,sum=0;
char str1[102][102];
int p1,p2;

int find(int &x,int &y)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		if(str1[i][j]=='@')
		{
			x=i;
			y=j;
			return 0;
		}	
	return 1;	
}

void fun(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m)return ;
	if(str1[x][y]=='*')return;
	
	a.x=x;
	a.y=y;
	str1[x][y]='*';
	que.push(a);	
}

void con()
{
	int x1,y1;
	while(!que.empty())
	{
		a=que.front();
		que.pop();
		p1=a.x;
		p2=a.y;			
	
		
		for(int i=0;i<8;i++)
		{
			x1=p1+str3[i][0];
			y1=p2+str3[i][1];
			fun(x1,y1);	
		}	
	}	
	
	
	
}
int main()
{

	while(scanf("%d%d",&n,&m),n)
	{	
		while(!que.empty())que.pop();
		sum=0;
		
		for(int i=0;i<n;i++)
		    scanf("%s",str1[i]);

		
		while(1)
		{
			int x,y;
			if(find(x,y))break;
			
			sum++;	
			a.x=x;
			a.y=y;
			str1[x][y]='*';
			que.push(a);
			
			con();
				
		}
			
		printf("%d\n",sum);	
			
	}
	
	
return 0;	
}
