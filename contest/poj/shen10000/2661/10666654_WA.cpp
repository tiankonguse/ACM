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
double str[200];
int now=1;

int find(int n){
	double k=pow(2.0,(n-1960)/10+2);
	//printf("k=%lf\n",k);
	double sum=0;
	int i;
	for(i=1;;i++){
		sum+=log((double)i);
		if(sum>k)break;
		//printf("%d  %lf\n",i,sum);
	}
	return i-1;
}

int main()
{
	int n;
	str[1]=0;
	now=1;
	while(scanf("%d",&n),n){
		printf("%d\n",find(n));
	}
	return 0;
}
