#include<stdio.h>
int main(){
	int len;
	__int64 n;
	char str[100];
	scanf("%d",&len);
	while(~scanf("%d%s%I64d",&len,str,&n)){
		for(int i=len-1;i>=0;i--){
			if(n&1){
				if(str[i]^'p')n++;
				str[i]='1';
			}
			else{
				str[i]='0';
			}
			n>>=1;
		}
		printf("%s\n",n?"Impossible":str);
		
	}
	return 0;	
}
