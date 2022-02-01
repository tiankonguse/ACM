
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
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int i,j,k;
	int a[50]={0,0,1,2};
	for(int i=4;i<=40;i++)
		a[i]=a[i-1]+a[i-2];
	int n,p;cin>>n;
	for(int j=1;j<=n&&cin>>p;j++)
		cout<<a[p]<<endl;
	return 0;
}
