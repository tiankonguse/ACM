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
typedef double LL;
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
	
	if(str1[r]>0)return str1[r];
	
	int k0=r,k1=r;
	LL ans1,ans0;
	
	int l=get(r,k0,k1);
	
	if(l==-1){
		return str1[r]=str0[k0];
	}
	
	if(k0==k1){
		return str1[r]=dfs(l)+str0[k0];
	}
	
	ans0=dfs(l)+str0[k0];
	ans1=dfs(k0)+str0[k1];	
	if(ans0>ans1)ans0=ans1;
	
	return str1[r]=ans0;
}


int main()
{
	bool yes;
	while(~scanf("%d%lf",&n,&m)){
		yes=false;
		for(int i=0;i<n;i++){
			scanf("%lf",&str0[i]);
			str1[i]=-1;
			if(str0[i]>m)yes=true;
		}
		if(yes){
			printf("-1\n");
		}else{
			dfs(n-1);
			printf("%.0f\n",str1[n-1]);			
		}
	}
	return 0;
}
