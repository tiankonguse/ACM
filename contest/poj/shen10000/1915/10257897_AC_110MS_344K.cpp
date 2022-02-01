#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
class point{public:int x, y,step;}begin,end,tmp;
queue<point>que;
const int N=333;
int m;
int str[8][2]={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
char map[N][N];
int find(){
	memset(map,0,sizeof(map));
	while(!que.empty())que.pop();
	begin.step=0;
	que.push(begin);
	int x,y,step;
	while(!que.empty()){
		tmp=que.front();
		x=tmp.x,y=tmp.y,step=tmp.step;
		que.pop();
		if(x==end.x && y==end.y)break;
		for(int i=0;i<8;i++){
			tmp.x=x+str[i][0];
			if(tmp.x<0 || tmp.x>=m)continue;
			tmp.y=y+str[i][1];
			if(tmp.y<0 || tmp.y>=m)continue;
			if(map[tmp.x][tmp.y])continue;
			map[tmp.x][tmp.y]=1;
			tmp.step=step+1;
			que.push(tmp);
		}
	}
	return step;
}

int main()
{
int n;
scanf("%d",&n);
while(n--){
	scanf("%d",&m);
	scanf("%d%d",&begin.x,&begin.y);
	scanf("%d%d",&end.x,&end.y);
	printf("%d\n",find());
}

return 0;
}
