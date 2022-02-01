#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

int main(){
	int i,j,k;
	freopen("in.txt","r",stdin);
	freopen("in.txt","w",stdout);
	for(i=1;i<=1000;i++){
		int len=rand()%500000;
		if(len==0)len++;
		while(len--){
			int tmp  = rand()%2;
			if(tmp==0)printf("M");
			else printf("F");
		}
		puts("");
	}
	return 0;
}
