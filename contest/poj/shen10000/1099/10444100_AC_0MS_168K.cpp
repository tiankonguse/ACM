#include<stdio.h>
#include<string.h>
char map[50][50];
int str[15][15];
int len,h;
int k=1;
void init()
{
	for(int i=0;i<=len;i++)
	{
		map[0][i]=map[h][i]='*';
	}	
	for(int i=0;i<=h;i++)
	{
		map[i][0]=map[i][len]='*';
		map[i][len+1]='\0';
	}	
}
void print()
{
	printf("Case %d:\n\n",k++);
	for(int i=0;i<=h;i++)
		printf("%s\n",map[i]);	
	printf("\n");
}

void setl(int x,int y)
{
	map[x][y-2]='H';
	map[x][y-1]='-';
	map[x][y  ]='O';
	map[x][y+1]='-';
	map[x][y+2]='H';
}
void setv(int x,int y)
{
	map[x-2][y]='H';
	map[x-1][y]='|';
	map[x  ][y]='O';
	map[x+1][y]='|';
	map[x+2][y]='H';
}

void set(int x,int y)
{
	map[x][y]='O';
	if(map[x][y-2]==' ')
	{
		map[x][y-2]='H';
		map[x][y-1]='-';
	}	
	else
	{
		map[x][y+2]='H';
		map[x][y+1]='-';	
	}	
	if(x>2 && map[x-2][y]==' ')
	{
		map[x-2][y]='H';
		map[x-1][y]='|';
	}	
	else
	{
		map[x+2][y]='H';
		map[x+1][y]='|';	
	}	
	
}

int main()
{
	int n;
	
	while(scanf("%d",&n),n)
	{
		memset(map,' ',sizeof(map));
		len=4*n+2;
		h=4*n-2;
		init();
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&str[i][j]);	
			if(str[i][j]==1)
			{
				setl(1+4*i,3+4*j);
			}
			else if(str[i][j]==-1)
			{
				setv(1+4*i,3+4*j);
			}
		}
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(str[i][j]==0)
			{
				set(1+4*i,3+4*j);
			}
		}
		print();
	}
	return 0;	
}
