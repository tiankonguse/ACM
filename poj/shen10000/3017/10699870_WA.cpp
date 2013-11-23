#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<deque>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int N=1000010;
typedef double LL;
LL str0[N];
LL str1[N];
int next[N];
int myleft[N];
int n;
LL m; 
deque<int>que;
void init(){
	
	while(!que.empty())que.pop_back();

	LL sum=str0[n-1];
	int now=n-1,tmp;
	que.push_back(n-1);
	
	for(int i=n-2;i>=0;i--){
		
		sum+=str0[i];
		while(sum>m){
			myleft[now]=i;
			sum-=str0[now];now--;
		}
		
		tmp=que.back();
		while(str0[i]>=str0[tmp]){
		//	printf("%d > %d\n",i,tmp);
			next[tmp]=i;que.pop_back();	
			if(!que.empty())tmp=que.back();
			else break;		
		}
		que.push_back(i);
		
	}
	while(now>=0)myleft[now--]=-1;
	while(!que.empty()){
		tmp=que.back();que.pop_back();
		next[tmp]=-1;
	}
	
}


LL dfs(int r){
	int p=r;
	if(str1[r]>0)return str1[r];
	
	int now;
	LL ans1,ans0;

	int l=myleft[r];
//	printf("r=%d left -->l=%d  \n",r,l);
	if(l==-1){
		now=r;
		while(next[now]>0)now=next[now]; 
		str1[p]=str0[now];
	//	printf("r1=%d---->%.0f\n",p,str1[p]);
		return str1[r];
	}
	
	now=next[r];
//	printf("r=%d next -->now=%d  \n",r,now);
	if(now<0 || now<=l){ //r为当前区域最大值 
		str1[p]=str0[r]+dfs(l);
		//printf("r2=%d---->%.0f\n",p,str1[p]);
		return str1[p];
	}
	now=r;
	while(next[now]>l)now=next[now]; 
	ans0=str0[now]+dfs(l);
	
	now=next[r];
	while(now>l){
		ans1=str0[r]+dfs(now);
		if(ans0>ans1)ans0=ans1;
		r=now;now=next[r];
	} 
	str1[p]=ans0;
	//printf("r3=%d---->%.0f\n",p,str1[p]);
	return str1[p];
}


int main()
{
	bool yes;
	while(~scanf("%d%lf",&n,&m)){
		yes=false;
		for(int i=0;i<n;i++){
			scanf("%lf",&str0[i]);
			str1[i]=-126.0;
			if(str0[i]>m)yes=true;
		}
		if(yes){
			printf("-1\n");
		}else{
			init();

			dfs(n-1);

			printf("%.0f\n",str1[n-1]);			
		}
	}
	return 0;
}
/*
9 9
5 4 3 2 1 2 3 4 5


*/
