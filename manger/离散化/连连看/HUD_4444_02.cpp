#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct B {
	int x1, y1, x2, y2;
	void init() {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 > x2) {
			swap(x1, x2);
		}
		if(y1 > y2) {
			swap(y1, y2);
		}
	};
};

struct P {
	int x, y, stp, d;
};
int pos[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{ -1, 0}
};
bool operator < (const P &a, const P &b) {
	return a.stp > b.stp;
}
priority_queue<P> que;
int const inf = 0x3f3f3f3f, maxn = 410;
int x1, y1, x2, y2, n, mx, my;
int m[maxn][maxn];
bool v[4][maxn][maxn];//方向
int s[4][maxn][maxn];//步数
set<int> x, y;
set<int>::iterator si;
map<int, int> hx, hy;
B b[maxn];

int main() {
	const bool debug = false;
	int i, j, k;
	P bg, nd, t;
	while(~scanf("%d%d%d%d", &x1, &y1, &x2, &y2)) {
		if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)break;
		scanf("%d", &n);

		x.clear();x.insert(x1);x.insert(x2);
		y.clear();y.insert(y1);y.insert(y2);

		for(i = 0; i < n; i++) {
			b[i].init();
			x.insert(b[i].x1);
			x.insert(b[i].x2);
			y.insert(b[i].y1);
			y.insert(b[i].y2);
		}
		hx.clear();
		hy.clear();

		//把地图扩大二倍后，矩阵内部就可以被填充，矩阵边界就可以走了

		//对x离散化
		for(si = x.begin(), mx = 1; si != x.end(); hx[*si++] = mx, mx+=2) ;


		//对y离散化
		for(si = y.begin(), my = 1; si != y.end(); hy[*si++] = my, my+=2);

		//初始化
		for(j = 0; j < 4; ++j){
			for(i = 0; i < mx; ++i){
				fill(v[j][i], v[j][i] + my, false);
				fill(s[j][i], s[j][i] + my, inf);
			}
		}
		for(i = 0; i < mx; ++i){
			fill(m[i], m[i] + my, 0);
		}

		//填充矩阵，填充为1
		for(i = 0; i < n; i++) {
			int xuper = hx[b[i].x2];
			int yuper = hy[b[i].y2];
			//填充上下边界
			for(j = hx[b[i].x1]; j <= xuper; j++){
				m[j][hy[b[i].y1]]=m[j][hy[b[i].y2]]=1;
			}
			//填充左右边界
			for(k = hy[b[i].y1]; k <= yuper; k++){
				m[hx[b[i].x1]][k]=m[hx[b[i].x2]][k]=1;
			}
			//填充矩阵内部
			for(j = hx[b[i].x1] + 1; j < xuper; j++) {
				for(k = hy[b[i].y1] + 1; k < yuper; k++) {
					m[j][k]=2;
				}
			}
		}


		//此路不同，标记为2
		for(i=1;i<mx-1;i++){
			for(j=1;j<my-1;j++){
				if(m[i-1][j]&&m[i][j-1]&&m[i+1][j]&&m[i][j+1])
					m[i][j]=2;
			}
		}

		if(debug) {
			puts("---- stp ----");
			for(i = 0; i < mx; i++) {
				for(j = 0; j < my; j++) {
					printf(" %2d",m[i][j]);
				}
				puts("");
			}
			puts("---- stp ----\n\n");
		}


		while(!que.empty())que.pop();

		nd.x = hx[x2];
		nd.y = hy[y2];

		bg.x = hx[x1];
		bg.y = hy[y1];

		bg.stp = 0;
		//分别标记出发点的四个方向，并入队
		for(i = 0; i < 4; i++) {
			bg.d = i;
			v[i][bg.x][bg.y] = true;
			s[i][bg.x][bg.y] = 0;
			que.push(bg);
		}

		int ndnum=0;

		while(!que.empty()) {

			bg = que.top();que.pop();

			//由于是优先搜索，所以只要到达就一定是最优的
			if(bg.x == nd.x && bg.y == nd.y){
				break;
			}

			for(i = 0; i < 4; i++) {

				//回头，不会有更优的答案
				if((i+2)%4 == bg.d)continue;

				t.x = bg.x + pos[i][0];
				t.y = bg.y + pos[i][1];

				//越界
				if(t.x < 0 || t.y < 0 || t.x >= mx || t.y >= my)continue;

				//此路不通
				if(m[t.x][t.y] >1)continue;

				//更新步数
				t.stp = s[bg.d][bg.x][bg.y] + (i == bg.d?0:1);

				//此地点已经达到过,且更优
				if(v[i][t.x][t.y] && t.stp >= s[i][t.x][t.y])continue;




				//此路可以更新
				s[i][t.x][t.y] = t.stp;
				v[i][t.x][t.y] = true;
				t.d = i;

				que.push(t);
			}

		}

		int ans = inf;
		for(i = 0; i < 4; i++) {
			if(ans > s[i][nd.x][nd.y])
				ans = s[i][nd.x][nd.y];
		}
		printf("%d\n", ans==inf?-1:ans);

		if(debug) {
			puts("---- stp ----");
			for(i = 0; i < mx; i++) {
				for(j = 0; j < my; j++) {
					if(m[i][j]){
						printf(" %2d",-m[i][j]);
					}else{
						int tmp=inf;
						for(int kk=0;kk<4;kk++){
							if(tmp>s[kk][i][j]){
								tmp=s[kk][i][j];
							}
						}
						if(tmp==inf)tmp=-3;
						printf(" %2d",tmp);
					}

				}
				puts("");
			}
			puts("---- stp ----\n\n");
		}

	}
	return 0;
}
