#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

/*
矩阵的面积就是里面2的面积
计算方法:(r-l)*(d-u)
  0--1--2--3--4--5
0 0  0  0  0  0  0
1 0  0  0  0  0  0
2 0  0  1  1  1  0
3 0  0  1  2  1  0
4 0  0  1  1  1  0
5 0  0  0  0  0  0

*/


struct B {
	double x1, y1, x2, y2;
	void init() {
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		if(x1 > x2) {
			swap(x1, x2);
		}
		if(y1 > y2) {
			swap(y1, y2);
		}
	};
};


int const inf = 0x3f3f3f3f, maxn = 510;
int x1, y1, x2, y2, n, mx, my;
int m[maxn][maxn];
set<double> x, y;
set<double>::iterator si;
map<double, int> hx, hy;
map<int, double> hhx, hhy;
B b[maxn];

int main() {
	const bool debug = false;
	int i, j, k,cs=1;
	while(scanf("%d", &n),n) {

		x.clear();y.clear();

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
		for(si = x.begin(), mx = 2; si != x.end(); hx[*si] = mx, hhx[mx] = *si, si++,mx+=2) ;

		//对y离散化
		for(si = y.begin(), my = 2; si != y.end(); hy[*si] = my, hhy[my] = *si, si++,my+=2);

		//初始化矩阵
		for(i = 0; i < mx; ++i){
			fill(m[i], m[i] + my, 0);
		}

		//填充矩阵，填充为1
		for(i = 0; i < n; i++) {
			int xuper = hx[b[i].x2];
			int yuper = hy[b[i].y2];
			//填充上下边界
			for(j = hx[b[i].x1]; j <= xuper; j++){
				if(m[j][hy[b[i].y1]]==0)m[j][hy[b[i].y1]]=1;
				if(m[j][hy[b[i].y2]]==0)m[j][hy[b[i].y2]]=1;
			}
			//填充左右边界
			for(k = hy[b[i].y1]; k <= yuper; k++){
				if(m[hx[b[i].x1]][k]==0)m[hx[b[i].x1]][k]=1;
				if(m[hx[b[i].x2]][k]==0)m[hx[b[i].x2]][k]=1;
			}
			//填充矩阵内部
			for(j = hx[b[i].x1] + 1; j < xuper; j++) {
				for(k = hy[b[i].y1] + 1; k < yuper; k++) {
					m[j][k]=2;
				}
			}
		}

		double ans = 0;
		for(i=3;i<mx;i+=2){
			for(j=3;j<my;j+=2){
				if(m[i][j]==2){
					ans += (hhx[i+1]-hhx[i-1])*(hhy[j+1]-hhy[j-1]);
				}
			}
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",cs++,ans);


	}
	return 0;
}


