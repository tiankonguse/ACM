#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

int const maxn =  15010;
int n, mx, my;
//int m[3500][3500];
int lev[maxn];
set<int> x, y;
set<int>::iterator si;
map<int, int> hx, hy;
int p[maxn][2];

	int *m;

	int myget(int i,int j){
		return m[i * my + j];
	}
	void myset(int i,int j,int val){
		 m[i * my + j]=val;
	}





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

		m = new int[mx*my];
		m[0]=1;

		fill(m,m+mx*my,0);


		fill(lev,lev+n,0);

		//填充矩阵，填充为1
		for(i = 0; i < n; i++) {
			myset(hx[p[i][0]],hy[p[i][1]],1);
		}

		for(i=1;i<mx;i++){
			for(j=1;j<my;j++){
				myset(i,j,myget(i,j)+myget(i-1,j)+myget(i,j-1)-myget(i-1,j-1));
			}
		}

		for(i = 0; i < n; i++) {
			lev[ myget(hx[p[i][0]],hy[p[i][1]])-1]++;
		}
		for(i=0;i<n;i++){
			printf("%d\n",lev[i]);
		}


	}
	return 0;
}


