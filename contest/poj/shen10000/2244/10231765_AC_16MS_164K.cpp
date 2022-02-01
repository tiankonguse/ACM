#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fun(int n,int k){
	int s=0;
	for (int i=2; i<=n; i++)  s=(s+k)%i;
	return s;
}
int main()
{
	int n,k,m,s;
	while(scanf("%d",&n),n--){
		for(int k=1;;k++){
			if(!fun(n,k)){printf("%d\n",k);break;}
		}
	}
return 0;
}
