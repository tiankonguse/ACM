#include<string>
#include<iostream>
using namespace std;
const int N=1010;
int str0[N];
int findmax(int *p,int n){
	int max=0;
	for(int i=1;i<=n;i++){
		if(p[max]<p[i])max=i;
	}
	return max;
}

void add(int max,int n,int* p){
	int sum=p[max];
	p[max]=0;
	int val=sum/(n-1);
	int mod=max%(n-1);
	for(int i=1;i<=mod;i++){
		if(i==max)continue;
		p[i]+=val+1;
	}
	for(int i=mod+1;i<=n;i++){
		if(i==max)continue;
		p[i]+=val;
	}
	
}

int main()
{
int n,t,max;
str0[0]=-1;
while(~scanf("%d%d",&n,&t)){
	for(int i=1;i<=n;i++){
		scanf("%d",&str0[i]);
	}
	while(t--){
		max=findmax(str0,n);
		printf("%d\n",max);
		add(max,n,str0);
	}
}
return 0;
}
