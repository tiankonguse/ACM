#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<deque>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int N=6;
const int L=50010;
const int M=100010;
typedef __int64 LL;
struct TT{
	LL val;
	int num;
	TT(LL v,int n){val=v,num=n;};
};
deque<TT>que[N];
LL sum[N][M];
LL str[N][M];
int l,n;
LL kk;
void init(){
	for(int i=0;i<n;i++){
		while(!que[i].empty()){
			que[i].pop_back();
		}
		que[i].push_back(TT(0,-1));
		str[i][0]=sum[i][0];
	}
}
void update(int k){
	int first=0,second=0,now;
	LL tmp;
	if(str[0][k]>str[1][k])first=1;
	else second=1;
	
	for(int i=2;i<n;i++){
		if(str[i][k]<=str[first][k]){
			second=first,first=i;
		}else{
			if(str[i][k]<str[second][k]){
				second=i;
			}
		}
	}

	for(int i=0;i<n;i++){
		now=first;
		if(i==now){
			now=second;
		}
		tmp=str[now][k]-sum[i][k]+kk;
		while(!que[i].empty() &&que[i].front().num+l<=k)que[i].pop_front();
		while(!que[i].empty() && que[i].back().val>=tmp)que[i].pop_back();
		que[i].push_back(TT(tmp,k));

	}
	
}
int main()
{
	int m,i,j;
	LL ans;
	while(~scanf("%d%d%d%d",&m,&n,&kk,&l)){
		for(i=0;i<n;i++){
			scanf("%I64d",&sum[i][0]);
			for(j=1;j<m;j++){
				scanf("%I64d",&sum[i][j]);
				sum[i][j]+=sum[i][j-1];
			}
		}

		
		if(n==1){
			printf("%I64d\n",sum[0][m-1]);
		}else{
			init();
	
			for(i=0;i<m;i++){
				for(j=0;j<n;j++){
					str[j][i]=que[j].front().val+sum[j][i];
				}
				update(i);
			}
			m--;
			ans=str[0][m];
			for(int i=1;i<n;i++){
				if(ans>str[i][m])ans=str[i][m];
			}
			printf("%I64d\n",ans);
		}
	}


	
	return 0;
}
/*
3 2 2 1
1 2 3
1 2 3
*/




