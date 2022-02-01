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
#define dis(j,i) ((coord[i][0]-coord[j][0])*(coord[i][0]-coord[j][0])+(coord[i][1]-coord[j][1])*(coord[i][1]-coord[j][1]))

int main()
{
	int n,i,j,k,tmp,Case=0;

	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){
			scanf("%d%d",&coord[i][0],&coord[i][1]);
			for(int j=0;j<i;j++){
				str[i][j]=str[j][i]=dis(j,i);
			}
		}

			for(k=0;k<n;k++)
			for(i=0;i<n;i++){
				if(i==k)continue;
				for(j=0;j<n;j++){
					if(j==i || j==k)continue;
					
					if(str[i][k]>str[k][j])tmp=str[i][k];
					else tmp=str[k][j];
					
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
