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
using namespace std;
typedef long long LL;

bool isLog(LL n){
	while(n){
		if(n == 1){
			return true;
		}else if(n&1 ==1){
			return false;
		}else{
			n>>= 1;
		}
	}

}

LL getLev(LL n){
	LL lev = -1;
	while(n){
		lev++;
		n>>=1;
	}
	return lev;
}

int main(int argc, char* argv[]) {
	LL n;
//	freopen("2048.in","r",stdin);
//	freopen("2048.out","w",stdout);
	while(~scanf("%lld",&n)){
		if(isLog(n)){
			printf("%lld\n",n/2+getLev(n/2));
		}else{
			printf("-1\n");
		}
	}
    return 0;
}






