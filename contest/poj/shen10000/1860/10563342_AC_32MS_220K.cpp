#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct E{
	int from,to;
	double r,c;
E(int _from,int _to,double _r,double _c)
:from(_from),to(_to),r(_r),c(_c){}
};

int n;

vector< vector<E> > map;
queue<int> que;
vector<bool> inQue;
vector<double> dis;
vector<int> rank;

void init(){
	map.clear();
	dis.clear();
	inQue.clear();
	rank.clear();
	while(!que.empty())que.pop();
	map.resize(n+1);
	dis.resize(n+1,0);
	inQue.resize(n+1,false);
	rank.resize(n+1,0);
} 

void read(int m){
	double r_ab,c_ab,r_ba,c_ba;
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d%d%lf%lf%lf%lf",&a,&b,&r_ab,&c_ab,&r_ba,&c_ba);
		map[a].push_back(E(a,b,r_ab,c_ab));
		map[b].push_back(E(b,a,r_ba,c_ba));
	}
}

bool spfa(int s,double v){	
	
	que.push(s);inQue[s]=true;
	dis[s]=v;
	rank[s]=1;
	
	int a,l,to;
	double tmp;
	while(!que.empty()){
		a=que.front();que.pop();inQue[a]=false;
		l=map[a].size();
		for(int i=0;i<l;i++){
			to=map[a][i].to;
			tmp=(dis[a]-map[a][i].c)*map[a][i].r;
			if(dis[to]<tmp){
				dis[to]=tmp;
				if(to==s && tmp>v)return true;
				if(!inQue[to]){
					rank[to]++;
					if(rank[to]>=n){
						return true;
					}
					que.push(to);
					inQue[to]=true;
				}
			}
		}
	}	
return false;
}
int main(){
	int m,s;
	double v;

	while(~scanf("%d%d%d%lf",&n,&m,&s,&v)){
		init();
		read(m);
		if(spfa(s,v)){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
