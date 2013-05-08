#include<iostream>
using namespace std;
const int Row=45;
const int Line=15;
char str[Row][Line];
bool cover[Row][Line];
char dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1} ;
int h,w,cnt;
struct Link
{
int x,y;
}link[Row][Line];
bool find (int py, int px)
{
	int i, j ;
	int x, y ;
	for (i = 0 ; i < 4 ; ++i)
	{
		y = py + dir[i][0] ;
		x = px + dir[i][1] ;
		if ((0<x && x <=w && 0<y && y<=h) && !cover[y][x] && (str[y][x]=='*'))
		{
			cover[y][x] = true ;
			if (!link[y][x].x || find (link[y][x].y, link[y][x].x))
			{
				link[y][x].y = py ;
				link[y][x].x = px ;
				return 1 ;
			}
		}
	}
	return 0 ;
}



int mach()
{
	int sum=0;
	for (int j = 1 ; j <=h ; ++j)
	for (int i = 1 ; i <=w ; ++i)
	{
		if (str[j][i] == '*')
		{
			++cnt ;
			memset (cover, false, sizeof (cover)) ;
			sum += find (j, i) ;
		}
	}
return cnt-sum/2;
}

int main()
{
	int k;
	scanf("%d",&k);

	while(k--)
	{
		cnt=0;
		scanf("%d %d",&h,&w);
		memset(link,0,sizeof(link));
		for(int i=1;i<=h;i++)
		{
			scanf("%s",&str[i][1]);
		}
		printf("%d\n",mach());
	}

	return 0;
}
