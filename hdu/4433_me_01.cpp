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


int mydp(int pos,int now,int next){
	int d,dj,dk;

	if(dp[pos][now][next]!=inf)return dp[pos][now][next];

	d=(now+10-from[pos])%10;
	for(dj=d;dj>=0;dj--){
		for(dk=dj;dk>=0;dk--){
			dp[pos][now][next]=min(dp[pos][now][next],mydp(pos+1,(next-dj+10)%10,(to[pos+2]-dk+10)%10)+d);
		}
	}

	d=(10+from[pos]-now)%10;
	for(dj=d;dj>=0;dj--){
		for(dk=dj;dk>=0;dk--){
			dp[pos][now][next]=min(dp[pos][now][next],mydp(pos+1,(next+dj)%10,(to[pos+2]+dk)%10)+d);
		}
	}

	return dp[pos][now][next];
}

int main(){

	while(~scanf("%s%s",from,to)){
		init();
		printf("%d\n",mydp(0,to[0],to[1]));
	}
	return 0;
}
