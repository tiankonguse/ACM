#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int N=1000;
__int64 str[N][N];//初始化为-1 
__int64 fun(int m,int n){
	if(n>=999 || m>=999)return fun(m-1,n)+fun(m,n-1); 
	if(str[m][n]!=-1)return str[m][n];
	if(m==0 || n==0)return str[m][n]=1;
	return str[m][n]=fun(m-1,n)+fun(m,n-1);	
}
int main()
{
	int n,m;
	memset(str,-1,sizeof(str)); 
	while(scanf("%d%d",&n,&m)){
		if(n==0 && m==0)break;
		printf("%I64d\n",fun(n,m)); 
	} 
	
	return 0;
}
