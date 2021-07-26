/*************************************************************************
    > File Name: F 文艺的XiaoB.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 18:04:18
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N = 2100;
int a[N][N];
// a[1...m][1...n]
int n,m;

void mycol(int i,int* col){
	for(int j=0,k;j<m;++j){
		if(a[i][j]==0)col[j]=0;
		else if(i==0 || !a[i-1][j]){
			for(k=i+1;k<n && a[k][j];++k);
			col[j]=k;
		}
	}
}

int Run(){//可以用单调队列优化
	int  i,j,l, r, max = 0;
	int col[N];

	for(i=0; i < n; ++i ){
		mycol(i,col);
		for(j=0; j < m; ++j )
			if( col[j] > i ){
			for( l=j-1; l >=0 && col[l] >= col[j]; --l );
		for( r=j+1; r < m && col[r] >= col[j]; ++r );
				int res = (r-l-1)*(col[j]-i);
				if( res > max ) max = res;
			}
	}

	return max;
}
int main() {
    int i,j;

    while(~scanf("%d%d",&n,&m)){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int ans = Run();
        printf("%d\n",(ans?ans:-1));
    }

    return 0;
}
