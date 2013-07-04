#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
//h(n-1)*(4*n-2)/(n+1)
char str[111][11111]; 
void restr(char *p){
	
	int l=0,r=strlen(p)-1;
	char c;
	while(l<r){
		c=p[l];
		p[l]=p[r];
		p[r]=c;
		l++,r--;
	}
}
void mult(int from,int to,int n){
	strcpy(str[to],str[from]); 
	int i=0;
	int tmp=0;
	restr(str[to]); 
	for(;str[to][i];i++){
		tmp+=(str[to][i]-'0')*n;
		str[to][i]=tmp%10+'0';
		tmp/=10; 
	} 
	while(tmp){
		str[to][i++]=tmp%10+'0';
		tmp/=10; 
	} 
	str[to][i]='\0'; 
	restr(str[to]); 
} 

void del_head_zero(int to){
	int first=0;
	while(str[to][first]=='0')first++;
	for(int i=0;str[to][i]=str[to][first];i++,first++); 
} 

void _div(int to,int n){
	int tmp=0; 
	for(int i=0;str[to][i];i++){
		tmp=tmp*10+str[to][i]-'0'; 
		str[to][i]=tmp/n+'0';
		tmp%=n;
	} 
	del_head_zero(to); 
} 

int main()
{
	str[1][0]='1';
	str[1][1]='\0';
	for(int i=2;i<101;i++){
		mult(i-1,i,(i<<2)-2);
		//printf("%d=%s\n",i,str[i]);
		_div(i,i+1); 
		//printf("%d=%s\n",i,str[i]); 
	} 
	int n;
	while(~scanf("%d",&n)){
		printf("%s\n",str[n]); 
	} 
	return 0;
}
