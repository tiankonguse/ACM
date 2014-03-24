#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 110
using namespace std;
#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif
int main(){
	int x1,x2,y1,y2,i;
	LL ans;
	int a,b,tmp;
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(cin>>a>>b){
		int aa=a,bb=b;
		ans = a;
		while(1){
			if(a<b)break;
			tmp=a/b;
			ans+=tmp;
			a=tmp+a%b;
		}
		int yu;
		int h=yu=0;
		a=aa;b=bb;
        while(a >= 1){
            h += a;
            yu += a % b;
            a /= b;
            if(yu/b>=1){
                a += yu / b;
                yu -= a * b;
            }
        }
        if(ans!=h){
			printf("%d %d  %d    %d\n",aa,bb ,ans,h);
        }
	}
	return 0;
}
