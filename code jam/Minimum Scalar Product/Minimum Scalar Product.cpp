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
__int64 str1[1000],str2[1000];
int n;
char input[2][100]={"A-small-practice.in","A-large-practice.in"};
char output[2][100]={"A-small-practice.out","A-large-practice.out"};
int main()
{
	freopen(input[1],"r",stdin);
    freopen(output[1],"w",stdout);
	int t;
	__int64 ans;
	scanf("%d",&t);
	for(int j=1;j<=t;j++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%I64d",&str1[i]);
		}
		
		for(int i=0;i<n;i++){
			scanf("%I64d",&str2[i]);
		}
		sort(str1,str1+n,less<__int64>());
		sort(str2,str2+n,greater<__int64>());
		ans=0;
		for(int i=0;i<n;i++){
			ans+=str1[i]*str2[i];
		}
		printf("Case #%d: %I64d\n",j,ans);
	}
	
	return 0;
}
