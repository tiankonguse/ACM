#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const int N=500100;
int minl[N][30], maxl[N][20], a[N],n;
int min(int x,int y){
	return a[x]<a[y]?x:y;
}
int max(int x,int y){
	return a[x]>a[y]?x:y;
}


void S_table(){

	for (int i=1;i<=n;i++) minl[i][0] =maxl[i][0]=i;

	for(int j=1,tj=2;tj<=n;++j,tj<<=1)
		for(int i=1,ti=(tj>>1);i+tj-1<=n;++i){
			minl[i][j]=min(minl[i][j-1],minl[i+ti][j-1]);
			maxl[i][j]=max(maxl[i][j-1],maxl[i+ti][j-1]);
		}
}
int query(int x, int y,int op) 
{
	int k=(int)(log((double)(y-x+1))/log(2.0));
	if(op==0)return min(minl[x][k],minl[y-(1<<k)+1][k]);
	else     return max(maxl[x][k],maxl[y-(1<<k)+1][k]);
}


int find(int x){
	int l=1,r=x-1,m,mink,maxk;
	while(l<r){
		m=(l+r)>>1;
		if(a[query(m,r,1)]<a[x])r=m-1;
		else l=m+1;
	}
	return query(l,x,0);
}

int main()
{

	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		S_table();
		int ans=0;
		for(int i=n,j=i;i>1;i=j-1){
			while(i>1 && a[i]<=a[i-1])i--;
			if(i==1)break;
			j=find(i);
			if(i-j>ans)ans=i-j;
		}
		if(ans<1)ans=-1;
		printf("%d\n",ans);
		
	}

return 0;
}
