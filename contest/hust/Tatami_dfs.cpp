#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

const int N = 30;
int str[N][N];
int n,m;
int ans;

void init(){
	memset(str,-1,sizeof(str));
	ans = 0;
}

void put(int x, int y, int i){
	if(i == 1){
		str[x][y] = 1;
		str[x][y+1] = 3;
	}else if(i == 2){
		str[x][y] = 2;
		str[x+1][y] = 4;
	}
}

void unPut(int x, int y, int i){
	if(i == 1){
		str[x][y] = -1;
		str[x][y+1] = -1;
	}else if(i == 2){
		str[x][y] = -1;
		str[x+1][y] = -1;
	}
}

bool noCross(int x, int y){
	if(x == 1 || y == 1){
		return true;
	}

	if(str[x-1][y-1] == 1 || str[x-1][y-1] == 2){
		return true;
	}
	return false;
}

bool checkPut(int x, int y, int i){
	if(i == 1){
		if(y< m && str[x][y] == -1 && str[x][y+1] == -1 && noCross(x,y)){
			return true;
		}
	}else if(i == 2){
		if(x < n && str[x][y] == -1 && str[x+1][y] == -1 && noCross(x,y)){
			return true;
		}
	}
	return false;
}

/*
	要在 (x,y) 放置 lev 方向的图形
	lev
	0: 不放置
	1: 放置向右
	2: 放置向下
	3: 放置向左
	4: 放置向上
*/
void dfs(int x, int y){
	//完全覆盖
	if(x == n+1 && y == m){
		ans++;
		return ;
	}
	//移动到最小面了
	if(x == n+1){
		dfs(1, y+1);
		return ;
	}
	//已经覆盖,移动到下一个
	if(str[x][y] != -1){
		dfs(x+1, y);
		return;
	}
	//需要覆盖
	for(int i=1;i<=2;i++){
		if(checkPut(x,y,i)){
			put(x,y,i);
			dfs(x+1,y);
			unPut(x,y,i);
		}
	}
}

void solver(){
	dfs(1, 1);
}

int main(int argc, char* argv[]) {

	while(~scanf("%d%d",&n,&m)){
		init();
		solver();
		printf("%d\n",ans);
	}
    return 0;
}






