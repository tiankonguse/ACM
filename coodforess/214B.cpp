#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int str[10],a,b,k;
void print(){
	bool yes=false;
	for(int i=9;i>0;i--){
		if(str[i])yes=true;
		while(str[i]--){printf("%d",i);}
	}
	if(yes)while(str[0]--)printf("0");
	else printf("0");
	printf("\n");	
}
int main()
{
	
	int n,tmp,sum;
	while(~scanf("%d",&n)){
		memset(str,0,sizeof(str));
		sum=a=b=0;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			str[tmp]++;
			if(tmp%3==1)a++;
			else if(tmp%3==2)b++;
			sum+=tmp;
		}
		
		if(str[0]){
			if(sum%3==0){
				print();
			}else if(sum%3==1){
				if(a){
					if(str[1])str[1]--;
					else if(str[4])str[4]--;
					else str[7]--;	
					print();				
				}else if(b>=2){
					k=2;
					while(k--){
						if(str[2])str[2]--;
						else if(str[5])str[5]--;
						else str[8]--;
					}
					print();
				}else{
					printf("-1\n");
				}
			}else{
				if(b){
					if(str[2])str[2]--;
					else if(str[5])str[5]--;
					else str[8]--;	
					print();				
				}else if(a>=2){
					k=2;
					while(k--){
						if(str[1])str[1]--;
						else if(str[4])str[4]--;
						else str[7]--;
					}
					print();
				}else{
					printf("-1\n");
				}	
			}

		}else{
			printf("-1\n");
		}
	}
	return 0;
}
