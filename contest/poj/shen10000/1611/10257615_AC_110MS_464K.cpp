#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=501;
const int M=30010;
vector<int>group[N];
queue<int>que;
char map[M];
char lie[M];
void init(){
	for(int i=0;i<N;i++)
		group[i].clear();
	while(!que.empty())que.pop();
	memset(map,0,sizeof(map));
	memset(lie,0,sizeof(lie));
}
int main()
{
int n,m,k,tmp;
while(scanf("%d%d",&n,&m),n){
	init();
	for(int i=0;i<m;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&tmp);
			group[i].push_back(tmp);
		}
	}
	que.push(0);
	map[0]=1;
	int sum=1,now;
	while(!que.empty()){
		now=que.front();
		que.pop();
		for(int i=0;i<m;i++){
			if(lie[i])continue;
			
			if(find(group[i].begin(),group[i].end(),now)==group[i].end())continue;
			
			lie[i]=1;
			
			int l=group[i].size();
			
			for(int j=0;j<l;j++){
				
				tmp=group[i][j];
				if(map[tmp])continue;
				
				map[tmp]=1;
				que.push(tmp);
				sum++;
			}
		}
	}
	printf("%d\n",sum);	
}
return 0;
}
