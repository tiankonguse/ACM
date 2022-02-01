#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
__int64 map[200];

int main()
{
	
map[0]=0;
for(int i=1;i<141;i++){
	map[i]=i*i+map[i-1];
	//printf("%I64d\n",map[i]);
}
int n;
while(~scanf("%d",&n)){
	int m=(int)((sqrt(n*8.0)-1)/2);
	
	printf("%d %d\n",n,(n-m*(m+1)/2)*(m+1)+map[m]);
}
return 0;
}
