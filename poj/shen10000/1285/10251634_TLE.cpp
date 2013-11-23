#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int N=60;
int n, m,r; //输入n 个数，其中本质不同的有m 个
int map[N]; //记录每个位置填的数
int used[N];//标记m 个数可以使用的次数
int num[N]; //存放输入中本质不同的m 个数
__int64 unrepeat_combination(int l, int p){
	if(l==r)return 1;
	__int64 sum=0;
	for (int i=p; i<m; i++) //循环依旧从p 开始，枚举剩下的本质不同的数
	if (used[i] > 0){//若还可以用, 则可用次数减
		used[i]--;  //在l 位置放上该数
		sum+=unrepeat_combination(l+1, i); //填下一个位置
		used[i]++; //可用次数恢复
	}
	return sum;
}
int main()
{
int n,k;


int j=1;
while(scanf("%d%d",&n,&k),n){
	memset(map,-1,sizeof(map));
	m=0;
	for(int i=0;i<n;i++){
		scanf("%d",&r);
		if(map[r]==-1){
			num[m]=r;
			used[m++]=1;
		}else{
			used[map[r]]++;
		}
	}
	printf("Case %d:\n",j++);
	while(k--){
		scanf("%d",&r);
		printf("%I64d\n",unrepeat_combination(0,0));
	}
}
return 0;
}
