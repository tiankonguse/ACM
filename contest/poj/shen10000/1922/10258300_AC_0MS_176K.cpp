#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
int n;
double len=4.5*3600;
double l;
int v,t;
while(scanf("%d",&n),n){
	double min=9999999;
	
	while(n--){
		scanf("%d%d",&v,&t);
		if(t>=0){
			l=t+len/v;
			if(l<min)min=l;
		}
	}
	printf("%d\n",(int)(min+0.999));
}

return 0;
}
