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

//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int a,b;

	while(scanf("%d%d",&a,&b)!=EOF){
		int c = abs(a)%10;
		int d = abs(b)%10;

		if(a<0){
			a+=c;
			a-=d;
		}else{
			a-=c;
			a+=d;
		}

		if(b<0){
			b+=d;
			b-=c;
		}else{
			b-=d;
			b+=c;
		}

		printf("%d\n",a+b);
	}

	return 0;
}
