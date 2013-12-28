#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct node
{
	int x;
	int y;
	int step;
	int b;//蓝色钥匙
	int ye;//黄色钥匙
	int r;//红色钥匙
	int g;//绿色钥匙
};

int n,m;
int fx,fy;//起始坐标
int ex,ey;//终点坐标
char map[105][105];
int vis[105][105][2][2][2][2];
int tx[]={1,0,-1,0};
int ty[]={0,1,0,-1};

int check(node d)
{
	if(d.x<0||d.x>=n||d.y<0||d.y>=m||map[d.x][d.y]=='#')
		return 0;
	else if(vis[d.x][d.y][d.b][d.ye][d.r][d.g])
		return 0;
	else
	    return 1;
}

int bfs()
{
	int i;
	queue<node>Q;
	node curr,next;
	curr.x=fx;
	curr.y=fy;
	curr.step=0;
	curr.b=0;
	curr.ye=0;
	curr.r=0;
	curr.g=0;
	vis[fx][fy][0][0][0][0]=1;
	Q.push(curr);
	while(!Q.empty())
	{
		curr=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			next=curr;
			next.x+=tx[i];
			next.y+=ty[i];
			if(check(next))
			{
				next.step++;
				if(map[next.x][next.y]=='.'||map[next.x][next.y]=='*')
				{
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
					Q.push(next);
				}
				else if(map[next.x][next.y]=='b')//出现蓝钥匙
				{
					next.b=1;//钥匙++
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
					//map[next.x][next.y]='.';
				}
				else if(map[next.x][next.y]=='y')//出现黄色钥匙
				{
					next.ye=1;
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
				//	map[next.x][next.y]='.';
				}
				else if(map[next.x][next.y]=='r')//出现红色钥匙
				{
					next.r=1;
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
				//	map[next.x][next.y]='.';
				}
				else if(map[next.x][next.y]=='g')//出现绿色钥匙
				{
					next.g=1;
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
				//	map[next.x][next.y]='.';
				}
				else if(map[next.x][next.y]=='B'&&next.b==1)//出现蓝色门并且有蓝色钥匙
				{
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
				//	map[next.x][next.y]='.';
				}
				else if(map[next.x][next.y]=='Y'&&next.ye==1)//出现黄色门并且有黄色钥匙
				{
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
				//	map[next.x][next.y]='.';
				}
				else if(map[next.x][next.y]=='R'&&next.r==1)//出现红色门并且有红色钥匙
				{
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
				//	map[next.x][next.y]='.';
				}
				else if(map[next.x][next.y]=='G'&&next.g==1)//出现有绿色门并且有绿色钥匙
				{
					Q.push(next);
					vis[next.x][next.y][next.b][next.ye][next.r][next.g]=1;
				//	map[next.x][next.y]='.';
				}
				else if(next.x==ex&&next.y==ey)
		        	return next.step;
			}
		}
	}
	return -1;
}

int main()
{
	int i,j;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
			break;

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='*')
				{
					fx=i;
					fy=j;
				}
				if(map[i][j]=='X')
				{
					ex=i;
					ey=j;
				}
			}
		}
		int ans;
		memset(vis,0,sizeof(vis));
		ans=bfs();
		if(ans==-1)
			printf("The poor student is trapped!\n");
		else
			printf("Escape possible in %d steps.\n",ans);
	}
	return 0;
}
/*
1 10
gryb*BYRGX
1 6
*....X
1 10
*........X
1 3
*#X
3 20
####################
#XY.gBr.*.Rb.G.GG.y#
####################
0 0

2 3
X..
*.X

1 1
*
1 2
*b

*/
