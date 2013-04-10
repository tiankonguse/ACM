#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
int ans;
int str0[1000][4];
int Case=0;

void add(int f,int t,int o){
	str0[ans][0]=f+1;
	str0[ans][1]=t+1;
	str0[ans][2]=o+1;
	ans++;
}

void dfs(int sum,int f,int t,int o,int lev){
	if(lev==0){
		if(sum>=5)dfs(sum-5,f+1,t,o,lev);
		dfs(sum,f,t,o,lev+1);
	}else if(lev==1){
		if(sum>=2)dfs(sum-2,f,t+1,o,lev);
		dfs(sum,f,t,o,lev+1);
	}else if(lev==2){
		dfs(0,f,t,o+sum,lev+1);
	}else{
		add(f,t,o);
	}
}
void print(){
	if(Case)puts("");
	printf("Case %d: count=%d\n",++Case,ans);
	for(int i=0;i<ans;i++){
		printf(" fen5:%d fen2:%d fen1:%d\n",str0[i][0],str0[i][1],str0[i][2]);
	}
}
int main()
{
	int n;
	while(cin>>n){
		n-=8;
		ans=0;
		dfs(n,0,0,0,0);
		print();
	}
	return 0;
}
