#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct E{
	int to,pri;
	E(int _to,int _pri):to(_to),pri(_pri){};
};

int n,m;
vector< vector<E> > map;
queue<int> que;
vector<bool> inQue;
vector<int> dis;
vector<int>lev;

void init(){
	lev.clear();lev.resize(n+1);
	map.clear();map.resize(n+1);
	while(!que.empty())que.pop();
} 
void read(){
	int p,l,x,t,v;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&p,&l,&x);
		lev[i]=l;
		map[i].push_back(E(0,p));
		for(int j=0;j<x;j++){
			scanf("%d%d",&t,&v);
			map[i].push_back(E(t,v));
		}
	}
} 
int spfa(int s,int v,int l){
	
	inQue.clear();inQue.resize(n+1,true);
	dis.clear();dis.resize(n+1,99999999);
	
	inQue[s]=false;dis[1]=v;que.push(s);

	int a,size,to; 
	
	while(!que.empty()){
		a=que.front();que.pop();inQue[a]=true;
		size=map[a].size(); 
		for(int i=0;i<size;i++){
			to=map[a][i].to;
			if(lev[to]>lev[s]+l)continue;
			if(lev[to]<lev[s]+l-m)continue;
			if(dis[to]>dis[a]+map[a][i].pri){
				dis[to]=dis[a]+map[a][i].pri;
				if(inQue[to]){
					inQue[to]=false;
					que.push(to);
				}
			}
		}
	}	
return dis[0]; 
} 
int main(){
	while(~scanf("%d%d",&m,&n)){
		init(); 
		read(); 
		int ans=99999999;
		lev[0]=lev[1];
		for(int i=0;i<=m;i++){
			ans=min(ans,spfa(1,0,i));
		}
		printf("%d\n",ans);

	}
	return 0;
}
