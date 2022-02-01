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
const int N=100010;
typedef __int64 LL;
LL str0[N];
LL str1[N];
int n;
LL m; 
int get(int l,int &k0,int &k1){
	LL sum=str0[l];
	for(l--;l>=0;l--){
		sum+=str0[l];
		if(sum>m)return l;
		if(str0[l]>=str0[k0]){
			k1=k0;
			k0=l;
		}	
	}
	return -1;
}

LL dfs(int r){
	
	if(str1[r]!=0)return str1[r];
	int k0=r,k1=r;
	LL ans1,ans0;
	int l=get(r,k0,k1);
	
	if(l==-1){
		return str1[r]=str0[k0];
	}
	if(k0==k1){
		return dfs(l)+str0[k0];
	}
	
	ans0=dfs(l)+str0[k0];
	ans1=dfs(k0)+str0[k1];	
	if(ans0>ans1)ans0=ans1;
	return str1[r]=ans0;
}


int main()
{
	while(~scanf("%d%I64d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%I64d",&str0[i]);
		}
		memset(str1,0,sizeof(LL)*(n+1));
		
		dfs(n-1);
		printf("%I64d\n",str1[n-1]);
	}
	return 0;
}
