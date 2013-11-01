#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
__int64 str[10];
int n;
scanf("%d",&n);
while(n--){
	scanf("%I64d%I64d%I64d%I64d",&str[0],&str[1],&str[2],&str[3]);
	int d=str[3]-str[2];
	if(str[2]-str[1]==d){
		str[4]=str[3]+d;
	}else{
		str[4]=str[3]/str[2]*str[3];
	}
	printf("%I64d",str[0]);
	for(int i=1;i<5;i++){
		printf(" %I64d",str[i]);
	}
	printf("\n");
}
return 0;
}
