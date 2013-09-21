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

int findmin(int t){
	int ans=2,tmp;
	while(t){
		tmp=t%10;
		t/=10;
		if(tmp>=ans)ans=tmp+1;
	}
	return ans;
}
int toten(int t,int k){
	int ans=0,tmp=1;
	while(t){
		ans+=(t%10)*tmp;
		t/=10;
		tmp*=k;
	}
	return ans;
}

int main()
{
	int a,b,c,l,aa,bb,cc,ans;
	scanf("%d",&a);
	while(~scanf("%d%d%d",&a,&b,&c)){
		l=max(2,findmin(a));
		l=max(l,findmin(b));
		l=max(l,findmin(c));
		ans=0;
		for(int i=l;i<=16;i++){
			aa=toten(a,i);
			bb=toten(b,i);
			cc=toten(c,i);
			if(aa*bb==cc){
				ans=i;break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
