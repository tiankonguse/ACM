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
int main()
{
	int n;
	while(~scanf("%d",&n)){
		if(n%12==0){
			printf("YES\n");
		}else if(n%4==0){
			printf("3\n");
		}else if(n%6==0){
			printf("4\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
