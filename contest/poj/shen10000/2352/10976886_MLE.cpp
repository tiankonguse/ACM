#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
/*
矩阵的周长就是偶数行奇数列的1的宽度 和 奇数列偶数行的高度
  0--1--2--3--4--5
0 0  0  0  0  0  0
1 0  0  0  0  0  0
2 0  0  1  1  1  0
3 0  0  1  2  1  0
4 0  0  1  1  1  0
5 0  0  0  0  0  0

*/
struct P {
	int x, y;
	void init() {
		scanf("%d%d", &x, &y);
	}
};



int const inf = 0x3f3f3f3f, maxn =  15010;
int n, mx, my;
int m[5000][5000];
int lev[maxn];
set<int> x, y;
set<int>::iterator si;
map<int, int> hx, hy;
map<int, int> hhx, hhy;
P p[maxn];




int main() {

	int i, j, k,cs=1;
	while(~scanf("%d", &n)) {

		x.clear();y.clear();

		for(i = 0; i < n; i++) {
			p[i].init();
			x.insert(p[i].x);
			y.insert(p[i].y);
		}
		hx.clear();
		hy.clear();


		//对x离散化
		for(si = x.begin(), mx = 1; si != x.end(); hx[*si] = mx, hhx[mx] = *si, si++,mx+=1) ;

		//对y离散化
		for(si = y.begin(), my = 1; si != y.end(); hy[*si] = my, hhy[my] = *si, si++,my+=1);

		//初始化矩阵
		for(i = 0; i < mx; ++i){
			fill(m[i], m[i] + my, 0);
		}

		fill(lev,lev+n,0);

		//填充矩阵，填充为1
		for(i = 0; i < n; i++) {
			m[hx[p[i].x]][hy[p[i].y]]=1;
		}

		for(i=1;i<mx;i++){
			for(j=1;j<my;j++){
				m[i][j]+=m[i-1][j]+m[i][j-1]-m[i-1][j-1];
			}
		}

		for(i = 0; i < n; i++) {
			lev[m[hx[p[i].x]][hy[p[i].y]]-1]++;
		}
		for(i=0;i<n;i++){
			printf("%d\n",lev[i]);
		}


	}
	return 0;
}


