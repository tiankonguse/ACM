#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;

int const maxn =  1124;
int n;
int m[maxn][maxn];
int op,x,y,A,L,B,R,T;

int Lowbit(int t){ return t & -t;}

int Sum(int i, int j){
	int tempj, sum = 0;
	while( i > 0 ){
		tempj = j;
		while( tempj > 0 ){
			sum += m[i][tempj];
			tempj -= Lowbit(tempj);
		}
		i -= Lowbit(i);
	}
return sum;
}
//更新一个点
void Update(int i, int j, int num){
	int tempj;
	while( i <= n ){
		tempj = j;
		while( tempj <= n ){
			m[i][tempj] += num;
			tempj += Lowbit(tempj);
		}
		i += Lowbit(i);
	}
}




int main() {
	while(~scanf("%d",&op)){
		scanf("%d",&n);
		n++;

		for(int i=0;i<n;i++){
			fill(m[i],m[i]+n,0);
		}

		while(scanf("%d",&op),op^3){
			if(op==1){
				scanf("%d%d%d",&x,&y,&A);
				x++,y++;
				Update(x,y,A);
			}else{
				scanf("%d%d%d%d",&L,&B,&R,&T);
				L++,B++,R++,T++;
				printf("%d\n",Sum(R,T)-Sum(L-1,T)-Sum(R,B-1)+Sum(L-1,B-1));
			}
		}
	}

	return 0;
}




