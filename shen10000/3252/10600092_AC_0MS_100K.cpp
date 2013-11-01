#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int str0[33]; 
int str1[33]; 
const int N=44;
int str[N][N];//初始化为-1 
int fun(int m=32,int n=32){
	if(str[m][n]!=-1)return str[m][n];
	if(m==n || n==0)return str[m][n]=1;
	if(m<n)return str[m][n]=0;
	return str[m][n]=fun(m-1,n-1)+fun(m-1,n);	
}
void init(){
	memset(str,-1,sizeof(str));
	memset(str1,0,sizeof(str1));
	str1[0]=1; 
	for(int i=1;i<32;i++){
		for(int j=(i+1)>>1;j<=i;j++){
			str1[i]+=fun(i,j); 
		}
	} 
} 
int totwo(int a){
	int i=0;
	while(a){
		str0[i++]=a&1;
		a>>=1; 
	} 
	return i; 
} 

int find(int a){
	int l=totwo(a); 
	int ans=0; 
	for(int i=0;i<l-1;i++){
		ans+=str1[i]; 
	} 
//	printf("l=%d a=%d ans=%d\n",l,a,ans); 
	if(l<=1)return a; 
	int k=1; 
	int _min=l/2+1,j; 
	for(int i=l-2;i>=0;i--){
		if(str0[i]){
			j=_min-k; 
			if(j<0)j=0; 
			for(;j<=i;j++){
				ans+=fun(i,j); 
			} 
			k++; 
		} 
	} 
	if(k>=_min)ans++; 
	return ans; 
} 

int main()
{
	int a,b,c;
	init(); 
	//printf("%d\n",fun(0,0)); 
	while(~scanf("%d%d",&a,&b)){ 
		c= find(b)-find(a-1);
		printf("%d\n",b-a+1-c); 
	} 
	return 0;
}
