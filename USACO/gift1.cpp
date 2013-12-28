/*
ID: tiankonguse
PROG: gift1
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

map<string,int>m;
char str[20][100];
char giver[100],recive[100];

int main() {
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
    int i, j, np, sum, n, ave;
    while(~scanf("%d",&np)){
    	m.clear();
    	for(i=0;i<np;i++){
			scanf("%s",str[i]);
			m[str[i]] = 0;
    	}
    	while(~scanf("%s",giver)){
			scanf("%d%d",&sum, &n);
			if(sum == 0 || n == 0){
				while(n--){
					scanf("%s",recive);
				}
			}else{
				ave = sum / n;
				sum = ave * n;
				m[giver] -= sum;
				while(n--){
					scanf("%s",recive);
					m[recive] += ave;
				}
			}
    	}
    	for(i=0;i<np;i++){
			printf("%s %d\n",str[i], m[str[i]]);
    	}
    }

    return 0;
}
