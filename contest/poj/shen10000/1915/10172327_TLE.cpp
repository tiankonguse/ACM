#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int map[9][3]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
class T
{
	public:
	T(){}
	T(int aa,int bb,int nn){x=aa;y=bb;num=nn;}
	int x,y,num;	
}a,b;
queue<T> que;
int n;
bool str2[303][303];

bool _not(const T &c) 
{
	if(c.x==b.x && c.y==b.y)return false;
	return true;	
}


int dfs()
{
	int sum=0;
	memset(str2,true,sizeof(str2));	
	while(!que.empty())que.pop();
	a.num=0;
	que.push(a);
	str2[a.x][a.y]=false;
	while(_not(que.front()))
	{
		T d=que.front();
		que.pop();
		for(int i=0;i<8;i++)
		{
			int xx=d.x+map[i][0];
			int yy=d.y+map[i][1];
			if(xx>=0 && xx<n && yy>=0 && yy<n && str2[xx][yy])
			{
				
				que.push(*(new T(xx,yy,d.num+1)));
				str2[xx][yy]=false;		
			}		
		}	
	
	
	}
	return (que.front()).num;
	
	
}
int main()
{
	int str1[303][303];
	int t;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d%d%d%d%d",&n,&a.x,&a.y,&b.x,&b.y);	
	printf("%d\n",dfs());
	}
	
	
return 0;		
}