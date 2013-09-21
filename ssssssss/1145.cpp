#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
char ans[500];
void restr(char *str,int len){
	
	int l=0,r=len-1;
	char c;
	while(l<r){
		c=str[l];
		str[l]=str[r];
		str[r]=c;
		l++,r--;
	}
}
void myfun(char *p1,int l1,char*p2,int l2){
	memset(ans,'0',sizeof(ans));
	p1[l1]='0';
	int tmp=0;
	for(int i=0;i<l2;i++){
		for(int j=0;j<=l1;j++){
			tmp+=ans[i+j]-'0'+(p1[j]-'0')*(p2[i]-'0');
			ans[i+j]=tmp%10+'0';
			tmp/=10;
		}
	}
	int k=l1+l2+1;
	while(ans[k]=='0' && k)k--;
	ans[k+1]='\0';
}
int main()
{
	char str1[222],str2[222];
	int l1,l2;
	while(~scanf("%s%s",str1,str2)){
		l1=strlen(str1);
		l2=strlen(str2);
		restr(str1,l1);
		restr(str2,l2);
		if(l1>=l2){
			myfun(str1,l1,str2,l2);
		}else{
			myfun(str2,l2,str1,l1);
		}
		restr(ans,strlen(ans));
		printf("%s\n",ans);
	}
	
	
	
	return 0;
}
