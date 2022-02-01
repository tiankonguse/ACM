#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const int N=65546;
int phi[N+1];

void euler(){
    int i,j;
    for(i=1;i<=N;i++) phi[i]=i;
    for(i=2;i<=N;i+=2) phi[i]/=2;
    for(i=3;i<=N;i+=2)
       if(phi[i]==i)
          for(j=i;j<=N;j+=i)
             phi[j]=phi[j]/i*(i-1);
}

int main()
{
	euler();
	int p;
	while(scanf("%d",&p)!=EOF){
		printf("%d\n",phi[p-1]);
	}

return 0;
}
