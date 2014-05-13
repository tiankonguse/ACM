#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

const int N = 111;

struct T{
	int x,y;
	double v;
}str[N],base[N];
int n,m;

int dis(T&a, T&b){
	return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double getPosn(int p){
	T& now = str[p];
	int ans = dis(now, base[0]);
	for(int i=1;i<m;i++){
		ans = min(ans, dis(now, base[i]));
	}
	return sqrt(ans/now.v);
}

double getPosm(int p){
	T& now = base[p];
	double ans = dis(now, str[0])/str[0].v;
	for(int i=1;i<m;i++){
		ans = min(ans, dis(now, str[i])/str[i].v);
	}
	return sqrt(ans);
}

int main(int argc, char* argv[]) {
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d%d%lf",&str[i].x, &str[i].y, &str[i].v);
			str[i].v = str[i].v*str[i].v;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&base[i].x, &base[i].y);
		}
		double ans = 0;
		for(int i=0;i<n;i++){
			ans = max(ans, getPosn(i));;
		}
		for(int i=0;i<m;i++){
			ans = max(ans, getPosm(i));;
		}
		printf("%.18f\n",ans);


	}
    return 0;
}






