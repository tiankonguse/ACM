#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool map[1111];
int str[120];

int main()
{
int n;
while(scanf("%d",&str[0]),str[0]+1){
	n=1;
	memset(map,false,sizeof(map));
	while(scanf("%d",&str[n]),str[n]){
		map[str[n++]]=true;
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(map[str[i]*2])sum++;
	}
	printf("%d\n",sum);
}
return 0;
}
