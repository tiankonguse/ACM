#include<stdio.h>
#include<queue>
using namespace std;
typedef struct{int x,y;}P;

char str1[25][25];
queue<P>que;
P a;
int str3[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,sum=0;
int p1,p2,x1,y1;

void fun(int x,int y)
{
	if(x<0||y<0||x>=m||y>=n)return;	
	if(str1[x][y]=='#')return;
	a.x=x;
	a.y=y;
	que.push(a);
	sum++;
	str1[x][y]='#';	
}
void cin(int n,int m)
{
		for(int i=0;i<m;i++)
		{
			getchar();
			for(int j=0;j<n;j++)
			{
				str1[i][j]=getchar();
				if(str1[i][j]=='@')
				{
					a.x=i;
					a.y=j;
					que.push(a);
				    str1[i][j]='#';		
				}	
				
			}
	    }		
}

int main()
{
	
	while(scanf("%d%d",&n,&m),m+n)
	{
		sum=1;
		while(!que.empty())que.pop();
			
		cin(n,m);	

		while(!que.empty())
		{
			a=que.front();
			que.pop();
			p1=a.x;
			p2=a.y;			
		
			
			for(int i=0;i<4;i++)
			{
				x1=p1+str3[i][0];
				y1=p2+str3[i][1];
				fun(x1,y1);	
			}	
		}
		
		printf("%d\n",sum);	
			
	}	
		
		
return 0;	
}
