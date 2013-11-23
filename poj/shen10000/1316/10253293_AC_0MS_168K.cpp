#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=10000;
bool map[N];

int fun(int p){
	int t=p;
	while(t){
		p+=t%10;
		t/=10;
	}
	return p;
}

int main()
{
memset(map,true,sizeof(map));
int k=0,son;
for(int i=1;i<N;i++){
	if(map[i]){
		printf("%d\n",i);
		son=fun(i);
		while(son<N){
			if(map[son]==false)break;
			map[son]=false;
			son=fun(son);
		}
	}
}
return 0;
}
