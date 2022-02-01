#include<string>
#include<iostream>
using namespace std;
const int N=1010;
int str0[N];
int n;
int findmax(){
	int max=0;
	for(int i=1;i<n;i++)
		if(str0[max]<str0[i])max=i;
	return max;
}

void fixmax(int max){
	int val=str0[max]/(n-1);
	int mod=str0[max]%(n-1);
	for(int i=0;i<mod;i++){
		if(i==max)mod++;
		str0[i]+=1;
	}
	for(int i=0;i<n;i++){
		str0[i]+=val;
	}
	str0[max]=0;
}

int main()
{
int t,max;

while(~scanf("%d%d",&n,&t)){
	for(int i=0;i<n;i++){
		scanf("%d",&str0[i]);
	}
	while(t--){
		max=findmax();
		printf("%d\n",max+1);
		fixmax(max);
	}
}
return 0;
}
