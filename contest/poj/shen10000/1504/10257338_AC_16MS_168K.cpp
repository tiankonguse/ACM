#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[1000],str2[1000],str3[1000];

int main()
{
int n;
scanf("%d",&n);
while(n--){
	scanf("%s%s",str1,str2);
	int tmp=0;
	int i=0;
	while(str1[i] && str2[i]){
		tmp+=str1[i]-'0'+str2[i]-'0';
		str3[i++]=tmp%10+'0';
		tmp/=10;
	}
	if(str1[i]=='\0' && str2[i]!='\0'){
		while(str2[i]){
			tmp+=str2[i]-'0';
			str3[i++]=tmp%10+'0';
			tmp/=10;
		}
	}else if(str1[i]!='\0' && str2[i]=='\0'){
		while(str1[i]){
			tmp+=str1[i]-'0';
			str3[i++]=tmp%10+'0';
			tmp/=10;
		}
	}
	if(tmp)
		str3[i++]=tmp+'0';
	str3[i]='\0';
	while(str3[--i]=='0');
	str3[i+1]='\0';
	int j=0;
	while(str3[j]=='0')j++;
	printf("%s\n",str3+j);

	
}
return 0;
}
