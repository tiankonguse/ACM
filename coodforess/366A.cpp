#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;



int main() {

	int maxCost,ansPos,ansCost,ansFirst,ansSecond;
	int fmc,fmj,smc,smj,tmp;

	scanf("%d",&maxCost);
	ansCost = 1000000;

	for(int i=1;i<=4;i++){
		scanf("%d%d%d%d",&fmc,&fmj,&smc,&smj);
		if(min(fmc,fmj) + min(smc,smj) <= ansCost){
			ansCost = min(fmc,fmj) + min(smc,smj);
			ansPos = i;
			ansFirst = min(fmc,fmj) ;
			ansSecond = maxCost - ansFirst;
		}
	}

	if(ansCost > maxCost){
		printf("-1\n");
	}else{
		printf("%d %d %d\n",ansPos, ansFirst,ansSecond);
	}





    return 0;
}
