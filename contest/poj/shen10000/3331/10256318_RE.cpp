#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str[100];
int bignumber_factorial(int n){
	memset(str,0,sizeof(str));
	str[0]=1;
	int ncarry,ndigits=1;
	int tmp;
	for(int i=2;i<=n;++i){
		ncarry=0;
		for(int j=1;j<=ndigits;++j){
			tmp=str[j-1]*i+ncarry;
			str[j-1]=tmp%10;
			ncarry=tmp/10;
		}
		while(ncarry){
			str[++ndigits-1]=ncarry%10;
			ncarry/=10;
		}
	}
	return ndigits;
}
int main()
{
int n,m;
scanf("%d",&n);
while(~scanf("%d%d",&n,&m)){
	n=bignumber_factorial(n);
	int sum=0;
	for(int i=0;i<n;i++){
		if(str[i]==m)sum++;
	}
	printf("%d\n",sum);
}
return 0;
}
