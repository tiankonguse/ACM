#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int N=44;
int str[N][N];//³õÊ¼»¯Îª-1 
int fun(int m=32,int n=32){
	if(str[m][n]!=-1)return str[m][n];
	if(m==n || n==0)return str[m][n]=1;
	if(m<n)return str[m][n]=0;
	return str[m][n]=fun(m-1,n-1)+fun(m-1,n);	
}
bool ok(char *p){
	int i=0;
	while(p[i+1]){
		if(p[i]>=p[i+1])return false;
		i++; 
	} 
	return true; 
} 

int myfun(char l,char r,int ll){
	int ans=0;
	int _max=25-(l-'a'); 
	for(;l<r;){
		ans+=fun(_max,ll); 
		_max--; 
		l++; 
	}
	return ans; 
} 

int find(char *p){
	int ans=1; 
//	printf("---->\n"); 
	int l=strlen(p);
	for(int i=1;i<l;i++){
		ans+=fun(26,i); 
	} 
	//printf("%d---->\n",ans); 
	ans+=myfun('a',p[0],l-1); 
	for(int i=1;p[i];i++){
		ans+=myfun(p[i-1]+1,p[i],l-i-1); 
		//printf("ans=%d\n",ans); 
	} 
	return ans; 
} 

int main()
{
	memset(str,-1,sizeof(str)); 
	char s[14];
	while(~scanf("%s",s)){
		if(ok(s)){
			//	printf("---->\n"); 
			printf("%d\n",find(s)); 
		}else{
			puts("0"); 
		} 
	} 
	
	return 0;
}
