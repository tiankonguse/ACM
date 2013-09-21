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
char ans[222];
int only;
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
void myfun(char* p1,int l1,char *p2,int l2){
	p1[l1]='0';
	for(int i=l2;i<=l1;i++)p2[i]='0';
	int tmp=0;
	for(int i=0;i<=l1;i++){
		tmp+=p1[i]-'0'+p2[i]-'0';
		ans[i]='0'+tmp%10;
		tmp/=10;
		if(tmp)only++;
	}
	if(ans[l1]=='0')ans[l1]='\0';
	else ans[l1+1]='\0';
	
}
int main()
{
	char str1[222],str2[222];
	int l1,l2;
	while(~scanf("%s%s",str1,str2)){
		if(str1[0]=='0' && str1[1]=='\0' && str2[0]=='0' && str2[1]=='\0')break;
		l1=strlen(str1);
		l2=strlen(str2);
		restr(str1,l1);
		restr(str2,l2);
		only=0;
		if(l1>=l2){
			myfun(str1,l1,str2,l2);
		}else{
			myfun(str2,l2,str1,l1);
		}
		if(only==0){
			puts("No carry operation.");
		}else if(only==1){
			puts("1 carry operation.");
		}else{
			printf("%d carry operations.\n",only);
		}

	}
	return 0;
}
