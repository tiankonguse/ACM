#include<string>
#include<iostream>
using namespace std;
const int N=360;
int str[N];
int ans[N][N];
int max(int a,int b){
	return a>b?a:b;
}
int main()
{
int n;
while(scanf("%d",&n)!=EOF){
	memset(ans,0,sizeof(int)*(n+2));
	int tmp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&tmp);
			ans[i][j]=tmp+max(ans[i-1][j],ans[i-1][j-1]);
			
		}
	}
	tmp=ans[n][0];
	for(int i=1;i<=n;i++){
		if(tmp<ans[n][i])tmp=ans[n][i];
	}
	printf("%d\n",tmp);
}
return 0;
}
