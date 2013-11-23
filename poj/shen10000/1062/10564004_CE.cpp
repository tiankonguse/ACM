#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct E{
	int to,d;
	E(int _to,int _d){
		to=_to;
		d=_d;
	};
};

int n,m;
vector< vector <E> > map;
queue<int> que;
vector<bool> inQue;
vector<int> dis;
vector<int> lv;

int abs(int x){
	return x>0?x:-x;
}

int main(){
	int i,j,p,l,x,t,v;
	int ans;
	while(~scanf("%d%d",&m,&n)){
		map.clear();
		while(!que.empty())que.pop();
		lv.clear();
		map.resize(n+1);
		lv.resize(n+1);
		for(i=0;i<n;i++){
			scanf("%d%d%d",&p,&l,&x);
			lv[i+1]=l;
			map[i+1].push_back(E(0,p));
			for(j=0;j<x;j++){
				scanf("%d%d",&t,&v);
				map[i+1].push_back(E(t,v));
			}
		}
		lv[0]=lv[1];
		ans=99999999;
		for(j=0;j<=m;j++){
			inQue.clear();
			inQue.resize(n+1,false);
			inQue[1]=true;
			dis.clear();
			dis.resize(n+1,99999999);
			dis[1]=0;
			que.push(1);
			while(!que.empty()){
				x=que.front();
				que.pop();
				inQue[x]=false;
				for(i=0;i<map[x].size();i++){
					if(lv[map[x][i].to]>lv[1]+j)continue;
					if(lv[map[x][i].to]<lv[1]+j-m)continue;
					if(dis[map[x][i].to]>dis[x]+map[x][i].d){
						dis[map[x][i].to]=dis[x]+map[x][i].d;
						if(!inQue[map[x][i].to]){
							inQue[map[x][i].to]=true;
							que.push(map[x][i].to);
						}
					}
				}
			}
		//	printf("%d ~ %d %dn",lv[1]+j-m,lv[1]+j,dis[0]);
			if(ans>dis[0])ans=dis[0];
		}
		printf("%d\n",ans);
	}
	return 0;
}
