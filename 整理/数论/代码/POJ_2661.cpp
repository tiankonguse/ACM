#include<stdio.h>
#include<math.h>


int find(int n){
	double k=pow(2.0,(n-1960)/10+2);
	//printf("k=%lf\n",k);
	printf("%lf\n",log(3));
	double sum=0;
	int i;
	for(i=1;;i++){
		sum+=log((double)i)/log((double)2);
		if(sum>k)break;
		//printf("%d  %lf\n",i,sum);
	}
	return i-1;
}

int main()
{
	int n;
	while(scanf("%d",&n),n){
		printf("%d\n",find(n));
	}
	return 0;
}
