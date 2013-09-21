#include <cstdio>
#include <cmath>
#include <cstring>
#define N 205
const double esp=1e-5;
double d[N][N];
int x[N],y[N],n;

double min(double x,double y){
	return x<y?x:y;
}

double max(double x,double y){
	return x>y?x:y;
}

int main(){
	int i,j,k,t,Case=0;
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
		for(k=0;k<n;k++){
			for(i=0;i<n;i++){
				if(i==k)continue;
				for(j=0;j<n;j++){
					if(i==j||k==j)continue;
					d[i][j]=
					min(
						d[i][j],
						max(
							d[i][k],
							d[k][j]
						)
					);
				}
			}
		}
		if(Case)puts("");
		printf("Scenario #%d\n",++Case);
		printf("Frog Distance = %.3f\n",d[0][1]);
	}
}
