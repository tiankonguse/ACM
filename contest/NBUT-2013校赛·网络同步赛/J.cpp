#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
// 1 5 2 3 6 4 7 3 0 0
#define MAXN 123456

int n,m;
int org[MAXN];
int num[40][MAXN];//divied tree
int sortedOn[MAXN];// the i th sorted element is on sortedOn[i] of the original array
int	orgOn[MAXN];//the i th original element is on orgOn[i] of the sorted array
int mvLfCnt[40][MAXN];//move to left count

bool cmp(int a,int b){
	return org[a]<org[b];
}

void build(int l,int r,int level){
//	printf("l = %d , r = %d , level = %d \n",l,r,level);
	if(l>=r)return;
	int i,j,m=(l+r)>>1,mvL=0,mvR=0;
	for(i=l;i<=r;i++){
		mvLfCnt[level][i]=mvL;
		if(num[level][i]<=m){
			num[level+1][l+mvL]=num[level][i];
			mvL++;
		}else{
			num[level+1][m+mvR+1]=num[level][i];
			mvR++;
		}
	}
	build(l,m,level+1);
	build(m+1,r,level+1);
}

int query(int from,int to,int k,int level,int l,int r){
//	printf("from = %d , to = %d , k = %d , level = %d , l = %d , r = %d\n",from,to,k,level,l,r);
	if(from==to)return num[level][from];
	int m=(l+r)>>1;
	int total=to-from+1;
	int mvL=mvLfCnt[level][to]-mvLfCnt[level][from];
	if(num[level][to]<=m)mvL++;//fix bug, while the line above cannot tell the number on [to] is moving left;
	int mvR=total-mvL;
	int beforeFromMvL=mvLfCnt[level][from];
	int beforeFromMvR=from-l-beforeFromMvL;
	if(k<=mvL){
		return query(l+beforeFromMvL,l+beforeFromMvL+mvL-1,k,level+1,l,m);
	}else{
		return query(m+1+beforeFromMvR,m+beforeFromMvR+mvR,k-mvL,level+1,m+1,r);
	}
}

int main(){
	int i,j,from,to,k,sortedPos;
	int ts,cs;
//	scanf("%d",&ts);
	for(cs=1;~scanf("%d%d",&n,&m);cs++){
	//	scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%d",&org[i]);
			sortedOn[i]=i;
		}
		sort(sortedOn,sortedOn+n,cmp);
		for(i=0;i<n;i++){
			orgOn[sortedOn[i]]=i;
			num[0][sortedOn[i]]=i;
		//	printf("%d ",sortedOn[i]);
		}
		//puts("");
		build(0,n-1,0);
/*		for(i=0;i<=3;i++){
			for(j=0;j<n;j++){
				printf("%d ",num[i][j]);
			}
			puts("");
		}
		puts("");
		for(i=0;i<=3;i++){
			for(j=0;j<n;j++){
				printf("%d ",mvLfCnt[i][j]);
			}
			puts("");
		}*/
		for(i=0;i<m;i++){
			scanf("%d%d%d",&from,&to,&k);
			from--,to--;
			sortedPos=query(from,to,k,0,0,n-1);
		//	printf("sortedPos = %d\n",sortedPos);
			printf("%d\n",org[sortedOn[sortedPos]]);
		}
	}
	return 0;
}

