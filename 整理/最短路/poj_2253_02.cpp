#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
#define N 205
const double esp=1e-5;
double d[N][N];
int x[N],y[N],n;
bool s[N];
queue<int> que;

int main(){
	int i,j,t,cs=1;
	double l,r,m;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			d[i][i]=0;
			scanf("%d%d",&x[i],&y[i]);
			for(j=0;j<i;j++){
				d[i][j]=d[j][i]=sqrt(
					(x[i]-x[j])*(x[i]-x[j])
				+	(y[i]-y[j])*(y[i]-y[j])
				);
			}
		}
		l=0;
		r=d[0][1];
		while(r-l>esp){
			m=(r+l)/2;
			memset(s,0,sizeof(bool)*(n+1));
			s[0]=true;
			while(!que.empty())que.pop();
			que.push(0);
			while(!que.empty()){
				t=que.front();
				que.pop();
				for(i=0;i<n;i++){
					if(s[i])continue;
					if(d[t][i]>m)continue;
					s[i]=true;
					if(i==1)break;
					que.push(i);
				}
				if(s[1])break;
			}
			if(s[1]){
				r=m;
			}else{
				l=m;
			}
		}
		printf("Scenario #%dnFrog Distance = %.3fnn",cs++,m);
	}
}
