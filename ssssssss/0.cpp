#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
const int N=10010;
int kth_element(int n,int* str,int k){
	int t,key;
	int l=0,r=n-1,i,j;
	while (l<r){
		for (key=str[((i=l-1)+(j=r+1))>>1];i<j;){
			for (j--;key<str[j];j--);
			for (i++;str[i]<key;i++);
			if (i<j) t=str[i],str[i]=str[j],str[j]=t;
		}
		if (k>j) l=j+1;
		else r=j;
	}
	return str[k];
}
int main()
{
	int str[N];
	int n,mid,sum;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%*d%d",&str[i]);
		}
		mid=kth_element(n,str,n>>1);
		sum=0;
		for(int i=0;i<n;i++){
			sum+=abs(mid-str[i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}
