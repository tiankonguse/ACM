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
#define maxn 110
using namespace std;
int c[maxn], cnt;
int fun(int n){
  memset(c, 0, sizeof(c));
	cnt = 0;
	int s = 0;
	for(int i=2;i*i<=n;i++){
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
				c[cnt]++;
				s++;
			}
			cnt++;
		}
	}
	if(n != 1){
		s++;
		c[cnt++] = 1;
	}	
	return s;
}
int C[27][27];
void init(){
	for(int i=0;i<=26;i++) C[i][0] = 1;
	for(int i=1;i<=26;i++){
		for(int j=1;j<=i;j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
}
int main(){
	int x, a, b, t;
	init();
	while(~scanf("%d", &x)){
		a = fun(x);
		b = 1;
		t = a;
		for(int i=0;i<cnt;i++){
			b *= C[t][c[i]];
			t -= c[i];
		}
		printf("%d %d\n", a, b);
	}
    return 0;
}
