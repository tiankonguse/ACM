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
struct Test{
	int limit,money;
}str[555];
bool have[555];
bool cmp(Test a,Test  b){
	return a.money > b.money;
}

int main() 
{ 
	int i,n,ans,j;
	while(~scanf("%d",&n)){
		memset(have,true,sizeof(bool)*(n+3));
		for(i=1;i<=n;i++){
			scanf("%d",&str[i].limit);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&str[i].money);
		}
		sort(str+1,str+1+n,cmp);

		ans=0;
		for(i=1;i<=n;i++){
			for(j=str[i].limit;j;j--){
				if(have[j]){
					have[j]=false;break;
				}
			}
			if(j==0){
				for(j=n;j;j--){
					if(have[j]){
						have[j]=false;
						ans+=str[i].money;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}

  return 0; 
} 



