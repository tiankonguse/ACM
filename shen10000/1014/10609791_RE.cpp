#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int first[1110],second[1110];
int str[7]; 
int main()
{
	int sum=0,_max,_maxtmp; 
	int t=1; 
	while(1){
		sum=0;
		for(int i=1;i<=6;i++){
			scanf("%d",&str[i]);
			sum+=str[i]*i; 
		} 
		if(sum==0)break;
		 
		printf("Collection #%d:\n",t++);
		if(sum%2){printf("Can't be divided.\n\n");continue;}
		//printf("sum=%d\n",sum); 
		sum>>=1; 
		//printf("sum=%d\n",sum); 
		memset(second,0,sizeof(second));
		first[0]=1;_max=0;
		for(int i=1;i<=6;i++){
			
			if(str[i]==0)continue; 
			
			_maxtmp=_max;
			for(int j=0;j<=_max;j++){
				for(int k=0; k<=str[i]&& k*i+j<=sum;k++){
					second[k*i+j]+=first[j];
					if(k*i+j>_maxtmp && k*i+j<=sum)_maxtmp=k*i+j;
				}
				if(_max==sum && first[sum])break; 
			}
			
			_max=_maxtmp;
			if(_max==sum && first[sum])break; 
			for(int j=0;j<=_max;j++){
				first[j]=second[j];
				second[j]=0;
			}
		}

		if(_max==sum && first[sum]){ 
			printf("Can be divided.\n\n");
		}else{
			printf("Can't be divided.\n\n");
		} 
	} 
	return 0;
}
