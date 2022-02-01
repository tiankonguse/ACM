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
#define maxn 10010
#define maxq 1000100
using namespace std;
int cnt[maxq];
int main(){
  int n, q, a, x, res;
	while(~scanf("%d", &n)){
		res = 0;
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<n;i++){
			scanf("%d%d%d", &q, &a, &x);
			if(a == 1){
				res += cnt[q] * 10;
				res += 20;
				if(x == 1) res += 20;
				cnt[q]++;
			}
			else res += 10;
		}
		printf("%d\n", res);
	}
    return 0;
}
