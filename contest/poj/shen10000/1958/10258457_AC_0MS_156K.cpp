#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
int han4[20];
int han3[20];
han3[0]=0;
han4[1]=1;
int min;
for(int i=1;i<13;i++)han3[i]=han3[i-1]<<1|1;

for(int i=2;i<13;i++){
	han4[i]=han3[i];
	for(int j=1;j<i;j++){
		min=(han4[j]<<1)+han3[i-j];
		if(min<han4[i])han4[i]=min;
	}
}
for(int i=1;i<13;i++)
printf("%d\n",han4[i]);

return 0;
}
