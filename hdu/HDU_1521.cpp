#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef __int64 INT;
const int N=11;
const int M=11;
int str0[N];
INT str1[N][M];
INT str[N][N];//³õÊ¼»¯Îª-1 
INT fun(int m,int n){
	if(str[m][n]!=-1)return str[m][n];
	if(m==n || n==0)return str[m][n]=1;
	if(m<n)return str[m][n]=0;
	return str[m][n]=fun(m-1,n-1)+fun(m-1,n);	
}
INT dp(int n,int m){
	
	if(str1[n][m]!=-1)return str1[n][m];
	if(m==0)return str1[n][m]=1;
	if(n==0)return str1[n][m]=0;
	INT ans=0;
	int end=min(str0[n],m);
	for(int i=0;i<=end;i++){
		ans+=dp(n-1,m-i)*fun(m,i);
	}
	return str1[n][m]=ans;
}

int main()
{
	memset(str,-1,sizeof(str));
	int n,m,i;
	while(~scanf("%d%d",&n,&m)){
		memset(str1,-1,sizeof(str1));
		for(i=1;i<=n;i++){
			scanf("%d",&str0[i]);
		}
		dp(n,m);
		printf("%I64d\n",str1[n][m]);
	}
	return 0;
}
