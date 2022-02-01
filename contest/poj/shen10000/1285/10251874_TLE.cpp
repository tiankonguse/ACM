#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int N=60;
int n, m,r; //输入n 个数，其中本质不同的有m 个
int map[N]; //记录每个位置填的数
int num[N]; //存放输入中本质不同的m 个数
int used[N];
__int64 str[N][N];

__int64 com(int a,int b){
	if(a==0){
		if(used[0]>=b)return 1;
		return 0;
	}
	
	if(str[a][b]!=0)return str[a][b];
	
	__int64 sum=0;
	int l=b>=used[a]?used[a]:b;

	for(int i=0;i<=l;i++)
		sum+=com(a-1,b-i);
		
	return str[a][b]=sum;
}


int main()
{
int n,k;


int j=1;
while(scanf("%d%d",&n,&k),n){
	memset(map,-1,sizeof(map));
	memset(used,0,sizeof(used));
	memset(str,0,sizeof(str));
	m=0;
	
	for(int i=0;i<55;i++)str[i][0]=1,str[i][1]=i+1;
	
	for(int i=0;i<n;i++){
		scanf("%d",&r);
		if(map[r]==-1){
			map[r]=m;
			used[m++]=1;
		}else{
			used[map[r]]++;
		}
	}

	printf("Case %d:\n",j++);
	while(k--){
		scanf("%d",&r);
		printf("%I64d\n",com(m-1,r));
	}
}
return 0;
}
