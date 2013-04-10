#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=1010,inf=0x3f3f3f3f;
int dp[maxn][10][10],n;
char from[maxn],to[maxn];

int main(){
	int i,j,k,d,dj,dk;
	from[0]=to[0]=0;
	while(~scanf("%s%s",from+1,to+1)){
		for(i=1;from[i];i++){
			from[i]-='0';
			to[i]-='0';
		}
		n=i;
		for(i=0;i<=n;i++){
			for(j=0;j<10;j++){
				for(k=0;k<10;k++){
					dp[i][j][k]=inf;
				}
			}
		}
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				dp[0][j][k]=0;
			}
		}
		for(i=1;i<n;i++){
			for(j=0;j<10;j++){//倒数第2位
				for(k=0;k<10;k++){//倒数第3位
//					printf("%d %d %d\n",from[i-1],j,d);
					//+
					d=(j+10-from[i])%10;
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][k][to[i-2]]+d);//只扳动1位
					for(dj=d;dj>0;dj--){
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][(k-dj+10)%10][to[i-2]]+d);//扳动2位
						for(dk=dj;dk>0;dk--){
							dp[i][j][k]=min(dp[i][j][k],dp[i-1][(k-dj+10)%10][(to[i-2]-dk+10)%10]+d);//扳动3位
						}
					}
					//-
					d=(from[i]+10-j)%10;
					dp[i][j][k]=min(dp[i][j][k],dp[i-1][k][to[i-2]]+d);//只扳动1位
					for(dj=d;dj>0;dj--){
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][(k+dj)%10][to[i-2]]+d);//扳动2位
						for(dk=dj;dk>0;dk--){
							dp[i][j][k]=min(dp[i][j][k],dp[i-1][(k+dj)%10][(to[i-2]+dk)%10]+d);//扳动3位
						}
					}
				//	printf("%d %d %d = %d %d\n",i,j,k,dp[i][j][k],d);
				}
			}
		}
		printf("%d\n",dp[n][to[n]][to[n-1]]);
	}
	return 0;
}
