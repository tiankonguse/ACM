#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const int N=66000;
bool map[N];

bool ok(int p,int a){
	memset(map,true,sizeof(map));

	int k=0;
	int b=a;
	while(map[b]){
		k++;
		map[b]=false;
		__int64 c=b;
		
		b=(c*a)%p;
	}

	return k+1==p;
}

int main()
{
	int p;
	while(scanf("%d",&p)!=EOF){
		int k=0;
		for(int i=2;i<p;i++){
			if(ok(p,i))k++;
		}
		printf("%d\n",k);
	}

return 0;
}
