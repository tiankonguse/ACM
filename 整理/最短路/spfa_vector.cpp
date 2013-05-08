/*************************************************************************
    > File Name: spfa_vector.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/7 17:34:52
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef struct{
	int from,to,dis;
}E;
int N,M,X;
const int INF = 0x3fffffff;
vector< vector<E> > map,map2;
queue<int> que;
vector<bool> inQue;
vector<int> dis;
/*X为源点*/
void spfa(){
    int i,w;
    E e;
map.clear();
while(!que.empty())que.pop();
inQue.clear();
dis.clear();
map.resize(N+1);
inQue.resize(N+1,false);
dis.resize(N+1,INF);
map2.resize(N+1);//初始化map2
for(i=0;i<M;i++){
	scanf("%d%d%d",&e.from,&e.to,&e.dis);
	map[e.from].push_back(e);
}
que.push(X);
inQue[X]=true;
dis[X]=0;
while(!que.empty()){
	w=que.front();
	que.pop();
	inQue[w]=false;
	for(i=0;i<map[w].size();i++){
		if(dis[map[w][i].to]>dis[w]+map[w][i].dis){
			dis[map[w][i].to]=dis[w]+map[w][i].dis;
			if(!inQue[map[w][i].to]){
				que.push(map[w][i].to);
				inQue[map[w][i].to]=true;
			}
		}
	}
}
}

int main() {

    return 0;
}
