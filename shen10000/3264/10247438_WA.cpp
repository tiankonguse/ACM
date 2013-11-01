
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const int N=500100;
int minl[N][30], maxl[N][20], a[N],n;
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
void S_table1(){
	int l=int(log((n*1.0)/log(2.0)));

	for (int i=1;i<=n;i++) minl[i][0] =maxl[i][0]=a[i];

	for(int j=n;j>0;j--){
		for(int i=1;j+(1<<i)-1<=n;i++){
			minl[j][i]=min(minl[j][i-1],minl[j+(1<<(i-1))][i-1]);
			maxl[j][i]=max(maxl[j][i-1],maxl[j+(1<<(i-1))][i-1]);
		}
	}
}
int rmq(int x, int y,int op) 
{
	int k = int(log((y-x+1.0)/log(2.0)));
	if(op==0)return min(minl[x][k],minl[y-(1<<k)+1][k]);
	else     return max(maxl[x][k],maxl[y-(1<<k)+1][k]);
}


int main()
{
	int m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		S_table1();
		int a1,b;
		while(m--){
			scanf("%d%d",&a1,&b);
			printf("%d\n",rmq(a1,b,1)-rmq(a1,b,0));
		}
		
	}

return 0;
}
