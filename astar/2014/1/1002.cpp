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
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int N = 1111;
int str[N][N];
int in[2][N];
int sum[N];

int get(int u, int v){
	int tmp = abs(in[1][u] - in[1][v]);
	return abs(in[0][u] - in[0][v]) * 400 + min(tmp,360 - tmp) ;
}

int main(int argc, char* argv[]) {

	int t,n,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		in[0][0] = in[0][1] = 0;
		sum[0] = 0;
		for(i=1;i<=n;i++){
			scanf("%d%d",&in[0][i],&in[1][i]);
			sum[i] = sum[i-1] + get(i-1,i) + 10;
		}
		memset(str, -1, sizeof(str));
		str[0][0] = 0;
		str[1][0] = get(1,0) + 10;
		str[1][1] = str[1][0] + get(1,0);

		for(i=2;i<=n;i++){
			for(j=0;j<i-1;j++){
				str[i][j] = str[i-1][j] + get(i-1, i) + 10;
				if(j){
					str[i][i] = min(str[i][i], str[i][j] + get(i,j));
				}else{
					str[i][i] = str[i][j] + get(i,j) ;
				}
			}
			str[i][i-1] = str[i-1][0] + get(0,i)  + 10;
			for(j=1;j<i-1;j++){
				str[i][i-1] = min(str[i][i-1], str[i-1][j] + get(j,i) + 10);
			}
			str[i][i] = min(str[i][i], str[i][i-1] + get(i,i-1));
		}
		printf("%d\n",str[n][n]);


	}


    return 0;
}






