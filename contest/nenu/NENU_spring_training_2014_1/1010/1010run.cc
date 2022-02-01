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
char s[1000000+3];
int n,st,ans;
int main(){
	int i,j,k;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(gets(s+1)){
		n=strlen(s+1);
		st=1;
		for (; s[st]=='F'; st++);
		for (int i=st+1; i<=n; i++){
			if (s[i]=='F') ans=max(ans+1,i-st),st++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
