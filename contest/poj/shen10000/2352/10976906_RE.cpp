#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

int const maxn =  15010;
int n, mx, my;
int m[2000][2000];
int lev[maxn];
set<int> x, y;
set<int>::iterator si;
map<int, int> hx, hy;
int p[maxn][2];





int main() {

	int i, j, k,cs=1;
	while(~scanf("%d", &n)) {

		x.clear();y.clear();

		for(i = 0; i < n; i++) {
			scanf("%d%d",&p[i][0],&p[i][1]);
			x.insert(p[i][0]);
			y.insert(p[i][1]);
		}
		hx.clear();
		hy.clear();


		//对x离散化
		for(si = x.begin(), mx = 1; si != x.end(); hx[*si] = mx, si++,mx+=1) ;

		//对y离散化
		for(si = y.begin(), my = 1; si != y.end(); hy[*si] = my, si++,my+=1);

		//初始化矩阵
		for(i = 0; i < mx; ++i){
			fill(m[i], m[i] + my, 0);
		}

		fill(lev,lev+n,0);

		//填充矩阵，填充为1
		for(i = 0; i < n; i++) {
			m[hx[p[i][0]]][hy[p[i][1]]]=1;
		}

		for(i=1;i<mx;i++){
			for(j=1;j<my;j++){
				m[i][j]+=m[i-1][j]+m[i][j-1]-m[i-1][j-1];
			}
		}

		for(i = 0; i < n; i++) {
			lev[m[hx[p[i][0]]][hy[p[i][1]]]-1]++;
		}
		for(i=0;i<n;i++){
			printf("%d\n",lev[i]);
		}


	}
	return 0;
}


