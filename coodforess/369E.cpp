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

const int N = 1010000;

struct Edge{
	int l,r;
}edge[N];
int n;

int node[N];
int sum[N];
int tmpNode[N];

int main() {
	int m,i,j,cnt,ans;
	int maxP,l,r;
	memset(node,0,sizeof(node));
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<n;i++){
			scanf("%d%d",&edge[i].l, &edge[i].r);
		}
		while(m--){
			scanf("%d",&cnt);
			maxP = 0;
			for(i=0;i<cnt;i++){
				scanf("%d",&tmpNode[i]);
				node[tmpNode[i]] = 1;
				maxP = max(maxP, tmpNode[i]);
			}
			sum[0] = 0;
			for(i=1;i<=maxP;i++){
				sum[i] = sum[i-1] + node[i];
			}

			ans = 0;
			for(i=0;i<n;i++){
				if(edge[i].l <= maxP){
					r = min(maxP, edge[i].r);
					l = edge[i].l;
					ans += sum[r] > sum[l-1];
				}
			}
			printf("%d\n",ans);
			for(i=0;i<cnt;i++){
				node[tmpNode[i]] = 0;
			}

		}
	}

    return 0;
}
