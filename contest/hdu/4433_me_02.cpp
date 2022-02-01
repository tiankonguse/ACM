#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1010,inf=0x3f3f3f3f;
int dp[maxn][10][10],n;
char from[maxn],to[maxn];

void init(){
	int i,j,k;
	for(i=0;from[i];i++){
		from[i]-='0',to[i]-='0';
	}
	n=i;
	from[n]=to[n]=0;
	from[n+1]=to[n+1]=0;



	for(j=0;j<10;j++){
		for(k=0;k<10;k++){
			dp[n][j][k]=dp[n+1][j][k]=0;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				dp[i][j][k]=inf;
			}
		}
	}
}
//111111 222222

/*
这个dp方程不好想，或者无从下手吧
最后看了小程的代码才明白了
然后我写成递归的形式了，现在有改为递推的形式。递归的容易理解

*/

void solver(){
	int d,dj,dk;
	int pos,now,next;
	for(pos=n-1;pos>=0;pos--){
		for(now=0;now<10;now++){
			for(next=0;next<10;next++){
				d=(now+10-from[pos])%10;
				for(dj=d;dj>=0;dj--){
					for(dk=dj;dk>=0;dk--){
						dp[pos][now][next]=min(dp[pos][now][next],dp[pos+1][(next-dj+10)%10][(to[pos+2]-dk+10)%10]+d);
					}
				}

				d=(10+from[pos]-now)%10;
				for(dj=d;dj>=0;dj--){
					for(dk=dj;dk>=0;dk--){
						dp[pos][now][next]=min(dp[pos][now][next],dp[pos+1][(next+dj)%10][(to[pos+2]+dk)%10]+d);
					}
				}
			}
		}

	}

}

int main(){

	while(~scanf("%s%s",from,to)){
		init();
		solver();
		printf("%d\n",dp[0][to[0]][to[1]]);
	}
	return 0;
}
