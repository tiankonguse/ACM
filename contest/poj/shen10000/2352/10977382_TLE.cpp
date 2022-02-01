#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

int const maxn =  15010;
int n, mx, my;
int m[maxn];
int lev[maxn];
set<int> x, y;
set<int>::iterator si;
map<int, int> hx, hy;
int p[maxn][2],x0,y0;

int Lowbit(int t){ return t & -t;}

int musum(int end){
    int sum = 0;
    while (end > 0)
    {
         sum += m[end];
         end -= Lowbit(end);
    }
     return sum;
}

void myplus(int pos){
    while(pos <= mx)
    {
         m[pos] ++;
         pos += Lowbit(pos);
    }
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

		fill(m,m+mx,0);


		fill(lev,lev+n,0);

		//填充矩阵，填充为1
		for(i = 0; i < n; i++) {
			x0=hx[p[i][0]];
			lev[musum(x0)]++;
			myplus(x0);
		}
		for(i=0;i<n;i++){
			printf("%d\n",lev[i]);
		}

	}
	return 0;
}


