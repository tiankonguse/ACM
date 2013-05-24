#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<math.h>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef __int64 LL;
const int Max=100000;
int a,b,k;
struct Num{int count,prim[16];}str[Max+10];
LL elursum[Max+10];
LL elur[Max+10];
LL ans;
void elurfun(){
	
	for(int i=0;i<=Max;i++){
		str[i].count=0;
		elursum[i]=elur[i]=0;
	}
	elursum[1]=elur[1]=1;
	
	for(int i=2;i<=Max;i++){
		if(!elur[i]){
			for(int j=i;j<=Max;j+=i){
				if(!elur[j])elur[j]=j;
				elur[j]=elur[j]/i*(i-1);
				str[j].prim[str[j].count++]=i;
			}
		}
		elursum[i]=elursum[i-1]+elur[i];
	}
	
}
LL _myrongchi(int index,int a,int n){
	if(index==str[n].count)return a;
	LL t=_myrongchi(index+1,a,n);
	return t-t/str[n].prim[index];
	
	
}
LL myrongchi(int index,int a,int n){
	LL r=0,t;
	for(int i=index;i<str[n].count;i++){
		t=a/str[n].prim[i];
		r+=t-myrongchi(i+1,t,n);
	}
	return r;	
}
int main()
{
	int t,n;
	elurfun();
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%*d%d%*d%d%d",&a,&b,&k);
		if(k==0){printf("Case %d: 0\n",i);continue;}
		a/=k;
		b/=k;
		if(a>b)swap(a,b);
		ans=elursum[a];
		for(int j=a+1;j<=b;j++){
			ans+=a-myrongchi(0,a,j);
		}
		printf("Case %d: %I64d\n",i,ans);
	}
	return 0;
}
