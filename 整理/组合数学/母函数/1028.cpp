#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str1[121][121];
int str2[121][121];
//fun1(n,m)定义为整数m拆分的数最小为n 
int fun1(int n,int m){

	if(str1[n][m]!=-1)return str1[n][m];
	
	if(n==m)return str1[n][m]=1;
	if(n>m)return str1[n][m]=0;
	return str1[n][m]=fun1(n,m-n)+fun1(n+1,m); 
	
	 return str1[n][m];   
}
// fun2(n,m)定义为整数m拆分的数最大为n 
int fun2(int n,int m){
	if(str2[n][m]!=-1)return str2[n][m];
	
	if(m==0)return str2[n][m]=1;
	if(n==0)return str2[n][m]=0;
	 
	if(n>m)return str2[n][m]=fun2(m,m); 
	return  str2[n][m]=fun2(n,m-n)+fun2(n-1,m); 
} 

int main()
{
	memset(str1,-1,sizeof(str1));
	memset(str2,-1,sizeof(str2));

	
	int n;
	
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",fun1(1,n));
	 
	return 0;
}
