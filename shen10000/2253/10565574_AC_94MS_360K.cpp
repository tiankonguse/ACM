#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int N=222;
int coord[N][2];
int str[N][N];

int dis(int p1,int p2){
	int x=coord[p1][0]-coord[p2][0];
	int y=coord[p1][1]-coord[p2][1];
	return x*x+y*y;
}

int main()
{
	int n;
	int Case=0;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d%d",&coord[i][0],&coord[i][1]);
			for(int j=0;j<i;j++){
				str[i][j]=str[j][i]=dis(j,i);
			}
		}
			int tmp;
			for(int k=0;k<n;k++)
			for(int i=0;i<n;i++){
				if(i==k)continue;
				for(int j=0;j<n;j++){
					if(j==i || j==k)continue;
					tmp=max(str[i][k],str[k][j]);
					if(str[i][j]>tmp){
						str[i][j]=tmp;
					}
				}
			}
		
		if(Case)puts("");
		printf("Scenario #%d\n",++Case);
		printf("Frog Distance = %.3f\n",sqrt(str[0][1]*1.0));
	}
	return 0;
}
