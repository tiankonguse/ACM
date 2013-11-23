#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int N=2010;
int a[N][N];
// a[1...m][1...n]
int n,m;

void mycol(int i,int* col){
	for(int j=0,k;j<n;++j){
		if(a[i][j]==0)col[j]=0;
		else if(i==0 || !a[i-1][j]){
			for(k=i+1;k<m && a[k][j];++k);
			col[j]=k;
		}
	}
}


int Run(){// str[1...m][1...n]
	int  i,j,l, r, max = 0;
	int col[N];
	
	for(i=0; i < m; ++i ){
		mycol(i,col);
		for(j=0; j < n; ++j )
			if( col[j] > i ){
				for( l=j-1; l >=0 && col[l] >= col[j]; --l );++l;
				for( r=j+1; r < n && col[r] >= col[j]; ++r );--r;
				int res = (r-l+1)*(col[j]-i);
				if( res > max ) max = res;
			}
	}

	return max;
}


int main()
{
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
		printf("%d\n",Run());
	}
	
	
	return 0;
}
