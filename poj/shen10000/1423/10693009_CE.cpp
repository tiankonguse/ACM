#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const double e=2.7182818284590452354;
const double pi=atan2(0,-1);

int count_number_bit(int n){
	double sum=0;
	if(n<100000){
		for(int i=1;i<=n;i++)	
			sum+=log10(i*1.0);
	}else{
		sum=log10(sqrt(2*pi*n))+n*log10(n/e);
	}
	int ans=(int)sum;
	if(ans<=sum)ans++;
	return ans;
} 




int main()
{
int n,m;

scanf("%d",&n);
while(n--)
{
	scanf("%d",&m);
	printf("%d\n",count_number_bit(m));
}

return 0;
}
