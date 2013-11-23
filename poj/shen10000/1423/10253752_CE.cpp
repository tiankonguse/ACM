#include<iostream>
#include<math.h>

const double e=2.7182818284590452354;
const double pi=atan2(0,-1);

__int64 count_number_bit(__int64 n){
	double sum=0;
	if(n<100000){
		for(int i=1;i<=n;i++)	
			sum+=log10(i);
	}else{
		sum=log10(sqrt(2*pi*n))+n*log10(n/e);
	}
	__int64 ans=(__int64)sum;
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

//getchar();getchar();
return 0;
}
