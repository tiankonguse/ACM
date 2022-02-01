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
const int N=100010;
struct TT{int mod,num,val;}str[N];
bool cmp(TT const a,TT const b){
	if(a.mod==b.mod)return a.num<b.num;
	return a.mod<b.mod;
}

int main()
{
	int c,n,sum,tmp;
	int begin,end;
	while(~scanf("%d",&n)){
		sum=0;
		begin=1;
		end=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&tmp);
			sum=(sum+tmp)%n;
			str[i].mod=sum;
			str[i].val=tmp;
			str[i].num=i;
			if(str[i].mod==0)end=i;
		}
		if(end==0){
			sort(str+1,str+1+n,cmp);
			for(int i=1;i<n;i++){
				//printf("%d  %d  %d\n",i,str[i].mod,str[i].num);
				if(str[i].mod==str[i+1].mod){
					begin=str[i].num+1;
					end=str[i+1].num;
					break;
				}
			}	
		}

		printf("%d\n",end-begin+1);
		for(int i=begin;i<=end;i++){
				printf("%d\n",str[i].val);
		}
		
	}
	return 0;
}
