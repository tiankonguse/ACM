/*
#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<stdlib.h>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
const int N=(2<<24)+1;
const int M=(2<<24)+1;
char is[N]; 
int prm[M];
int getprm(){
	int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
	memset(is, 1, sizeof(is));
	
	prm[k++] = 2; is[0] = is[1] = 0;
	for (i = 4; i < N; i += 2) is[i] = 0;
	
	for(i=3;i<e;i+=2){
		if(is[i]){
			prm[k++]=i;
			for(int s=i+i,j=i*i;j<N;j+=s)is[j]=0;
		}
	}
	for (; i < N; i += 2)
		if (is[i])prm[k++] = i;
	return k; 
}
int main()
{
	int k=getprm();
	int ans,tmp,n;

	while(~scanf("%d",&n)){
		ans=0;
		for(int i=1;;i++){
			tmp=n-prm[i];
			if(tmp<prm[i])break;
			if(is[tmp])ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
