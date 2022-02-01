#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

int const maxn =  32003;
int n;
int m[maxn];
int lev[maxn];
int x0,y0;

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
    while(pos <= maxn)
    {
         m[pos] ++;
         pos += Lowbit(pos);
    }
}


int main() {

	int i, j, k,cs=1;
	while(~scanf("%d", &n)) {

		fill(m,m+maxn,0);
		fill(lev,lev+n,0);
		for(i = 0; i < n; i++) {
			scanf("%d%d",&x0,&y0);
			x0++;
			lev[musum(x0)]++;
			myplus(x0);
		}

		for(i=0;i<n;i++){
			printf("%d\n",lev[i]);
		}

	}
	return 0;
}


