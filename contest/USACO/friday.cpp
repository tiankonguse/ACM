/*
ID: tiankonguse
PROG: friday
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

bool isLeap(int year){
	return (year%4 == 0 && year%100 != 0)  || (year % 400 == 0);
}

int ans[444][10];
//            1  2  3  4  5  6  7  8  9  10 11 12
int day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
void init(){
	int i, j,year;
	memset(ans,0,sizeof(ans));
	int now = 1;
	for(i = 0; i < 400;i++){
		year = 1900 + i;
		if(i > 0){
			for(j=0;j<7;j++){
				ans[i][j] = ans[i-1][j];
			}
		}
		for(j=0;j<12;j++){
			ans[i][(now+12)%7]++;
			now += day[j];
			if(j == 1 && isLeap(year)){
				now++;
			}
			now %= 7;
		}
	}
}
int main() {
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
    int n;

    init();
    while(~scanf("%d",&n)){
    	printf("%d",ans[n-1][6]);
    	for(int i=0;i<6;i++){
			printf(" %d",ans[n-1][i]);
    	}
    	puts("");
    }

    return 0;
}
