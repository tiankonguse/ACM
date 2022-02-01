#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const int N=50010;
int minl[N][20], maxl[N][20], a[N],n,m;
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}

void S_table(){

	for (int i=1;i<=n;i++) minl[i][0] =maxl[i][0]=a[i];

	for(int j=1,tj=2;tj<=n;++j,tj<<=1)
		for(int i=1,ti=(tj>>1);i+tj-1<=n;++i){
			minl[i][j]=min(minl[i][j-1],minl[i+ti][j-1]);
			maxl[i][j]=max(maxl[i][j-1],maxl[i+ti][j-1]);
		}
}
int query(int x, int y,int op) 
{
	int k = int(log((y-x+1.0)/log(2.0)));
	if(op)return min(minl[x][k],minl[y-(1<<k)+1][k]);
	return max(maxl[x][k],maxl[y-(1<<k)+1][k]);
}


int main()
{
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		S_table();
		int a,b;
		while(m--){
			scanf("%d%d",&a,&b);
			printf("%d\n",query(a,b,0)-query(a,b,1));
		}
		
	}

return 0;
}
