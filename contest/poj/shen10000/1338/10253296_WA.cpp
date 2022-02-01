#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=2100;
int str[N];
bool map[N];
int main()
{

memset(map,false,sizeof(map));
map[1]=true;
for(int i=2;i<N;i+=2)map[i]=true;
for(int i=3;i<N;i+=3)map[i]=true;
for(int i=5;i<N;i+=5)map[i]=true;
int k=1;
for(int i=1;i<N;i++){
	if(map[i])str[k++]=i;
}

while(scanf("%d",&k),k){
	printf("%d\n",str[k]);
}
return 0;
}
