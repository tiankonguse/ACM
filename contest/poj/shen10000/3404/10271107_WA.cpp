#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int str[100];
bool cmp(const int&A,const int&B){
     return A<B?true:false;
}
int main()
{
int n,sum,min,tmp1,tmp2;
while(~scanf("%d",&n)){

	for(int i=1;i<=n;i++){
		scanf("%d",&str[i]);
	}
	sort(&str[1],str+n,cmp);
	sum=0;
	while(1){
		if(n>=4){
			tmp1=(str[2]<<1)+str[1]+str[n];
			tmp2=(str[1]<<1)+str[n-1]+str[n];
			sum+=(tmp1>tmp2?tmp2:tmp1);
			n-=2;
		}else if(n==3){
			sum+=(str[1]+str[2]+str[3]);
			break;
		}else if(n==2){
			sum+=str[2];
			break;
		}else{
			sum+=str[1];
			break;
		}
	}
	printf("%d\n",sum);
}
return 0;
}
