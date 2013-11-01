#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//C(n, r) = C(n, n-r)=C(n-1, r) + C(n-1, r-1);
__int64 map[55][55];

int main()
{
int n,m,k;

memset(map,0,sizeof(map));
for(int i=0;i<54;i++)map[i][1]=i,map[i][0]=1;
for(int i=1;i<51;i++)
for(int j=1;j<=i;j++){
	if(i==j)map[i][j]=1;
	else map[i][j]=map[i-1][j]+map[i-1][j-1];
}
int j=1;
while(scanf("%d%d",&n,&m),n){
	for(int i=0;i<n;i++)scanf("%d",&k);
	printf("Case %d:\n",j++);
	while(m--){
		scanf("%d",&k);
		printf("%I64d\n",map[n][k]);
	}
}
return 0;
}
