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

char str[44][44];
int ans[44][44][44][44];
int top[44][44];
int main() {
	int i,j,n,m,q,a,b,c,d,minH;
	while(~scanf("%d%d%d",&n,&m,&q)){
		memset(top,0,sizeof(top));
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n;i++){
			scanf("%s",str[i]+1);
			for(j=1;j<=m;j++){
				if(str[i][j] == '0'){
					top[i][j] = top[i-1][j] + 1;
				}else{
					top[i][j] = 0;
				}
			}
		}
		for(a=1;a<=n;a++){
			for(b=1;b<=m;b++){
				for(c=a;c<=n;c++){
					for(d=b;d<=m;d++){
						ans[a][b][c][d] = ans[a][b][c-1][d] + ans[a][b][c][d-1]  - ans[a][b][c-1][d-1];
						minH = min(top[c][d],c-a+1);
						for(i=d;i>=b;i--){
							minH = min(top[c][i],minH);
							if(minH == 0){
								break;
							}else{
								ans[a][b][c][d] += minH;
							}
						}
					}
				}
			}
		}
//		printf("begin\n");
		while(q--){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			printf("%d\n",ans[a][b][c][d]);
		}
	}



    return 0;
}
