/*
ID: tiankonguse
PROG: ride
LANG: C++
*/
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
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int MOD=47;

int main() {
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    char str1[111],str2[111];
    int sum1,sum2,i;
    while(~scanf("%s%s",str1,str2)){
		sum1=sum2=1;
		for(i=0;str1[i];i++)sum1=(sum1*(str1[i]-'A'+1))%MOD;
		for(i=0;str2[i];i++)sum2=(sum2*(str2[i]-'A'+1))%MOD;
		printf("%s\n",sum1==sum2?"GO":"STAY");
	}
    return 0;
}

