#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int N=60;
int map[N]; 
int num[N]; 
int used[N];
__int64 str[N][N];
__int64 com(int m,int n){
	if(str[m][n]>=0)return str[m][n];
	if(m==0){
		return str[m][n]=n>used[m]?0:1;
	}
	str[m][n]=0;
	int l=n>used[m]?used[m]:n;
	for(int mm=0;mm<=l;mm++){
		str[m][n]+=com(m-1,n-mm);
	}
	return str[m][n];
}
int main()
{
int m,n,k,r;


int jj=1;
while(scanf("%d%d",&n,&k)){
	if(n==0 && k==0)break;
	memset(map,-1,sizeof(map));
	memset(used,0,sizeof(used));
	m=0;

	for(int i=0;i<n;i++){
		scanf("%d",&r);
		if(map[r]==-1){
			map[r]=m;
			used[m++]=1;
		}else{
			used[map[r]]++;
		}
	}
	
	//dp[i][j] += dp[i-1][j-k], 0<=k<=tot[i].
	memset(str,-1,sizeof(str));
	for(int i=0;i<=used[0];i++)str[0][i]=1;
	for(int i=1;i<m;i++)
	for(int j=0;j<=n;j++){
		int l=j>used[i]?used[i]:j;
		for(int mm=0;mm<=l;mm++){
			str[i][j]+=str[i-1][j-mm];
		}
	}

	

	printf("Case %d:\n",jj++);
	while(k--){
		scanf("%d",&r);
		printf("%I64d\n",com(m-1,r));
	}
}
return 0;
}
