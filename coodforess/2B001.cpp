#include<cstdio>
#define N 1007
int n,sta[N],a[N][N],dp[N][N],path[N][N];
int getcnt(int aa,int bb){
	if(!aa)return 1;
	int cnt=0;
	while(aa%bb==0){
		aa/=bb;
		++cnt;
	}
	return cnt;
}
int solve(int bb){
	int i;
	dp[0][0]=getcnt(a[0][0],bb);
	for(i=1;i<n;++i){
		dp[0][i]=dp[0][i-1]+getcnt(a[0][i],bb);
		path[0][i]=0;
		dp[i][0]=dp[i-1][0]+getcnt(a[i][0],bb);
		path[i][0]=1;
	}
	int j;
	for(i=1;i<n;++i)
		for(j=1;j<n;++j){
			if(dp[i][j-1]<dp[i-1][j]){
				dp[i][j]=dp[i][j-1]+getcnt(a[i][j],bb);
				path[i][j]=0;
			}
			else{
				dp[i][j]=dp[i-1][j]+getcnt(a[i][j],bb);
				path[i][j]=1;
			}
		}
	return dp[n-1][n-1];
}
int main(){
	scanf("%d",&n);
	int i,j,ti=-1,tj=-1;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j){
			scanf("%d",a[i]+j);
			if(!a[i][j]){ti=i;tj=j;}
		}
	int aa=solve(2),bb=solve(5);
	if(ti+1&&tj+1&&aa&&bb){
		puts("1");
		i=n-1-ti;
		j=n-1-tj;
		while(ti--)putchar('D');
		while(tj--)putchar('R');
		while(i--)putchar('D');
		while(j--)putchar('R');
		return 0;
	}
	if(aa<bb)
		printf("%d\n",solve(2));
	else printf("%d\n",solve(5));
	i=n-1;
	j=n-1;
	n=n-1<<1;
	int stalen=0;
	while(n--){
		sta[stalen++]=path[i][j];
		if(path[i][j])--i;
		else--j;
	}
	while(stalen--){
		if(sta[stalen])putchar('D');
		else putchar('R');
	}
	return 0;
}

