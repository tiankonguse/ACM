#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int N=100;
int str[N][N];//³õÊ¼»¯Îª-1 
int fun(int m,int n){
	if(str[m][n]!=-1)return str[m][n];
	if(m==n || n==0)return str[m][n]=1;
	if(m<n)return str[m][n]=0;
	return str[m][n]=fun(m-1,n-1)+fun(m-1,n);	
}
int main(){
	memset(str,-1,sizeof(str));
	int m,n;
	while(cin>>n>>m)cout<<fun(m,n)<<endl;
	return 0;
}
