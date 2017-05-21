#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 4500 + 10
using namespace std;
int const mod = 1000000007;
int f[maxn];
int dp(int n, int m){
  if(n > m)	n = m;
	int i, j;
	for(i = 0; i <= m; ++i) f[i] = 1;
    for(j = 2; j <= n; ++j){
        for(i = j; i <= m; ++i){
            f[i] += f[i-j];
            if(f[i] >= mod) f[i] -= mod;
		}
	}
	return f[m];
}
int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        printf("%d\n", dp(n, m));
    }
    return 0;
}
