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
#define maxn 6000100
using namespace std;
int q[maxn];
int res[maxn];
int main(){
  int n, m, k, p, t, l, h;
	while(~scanf("%d%d%d", &n, &k, &p)){
		l = h = m = 0;
		for(int i=1;i<=k;i++) q[h++] = i;
		while(l != h){
			t = q[l++]; //if(l % 100000 == 0) l = 0;
			m++; if(m % n == 0) res[m / n - 1] = t;
			for(int i=0;i<p;i++){
				t = q[l++]; //if(l % 100000 == 0) l = 0;
				q[h++] = t; //if(h % 100000 == 0) h = 0;
			}
		}
		m /= n;
		sort(res, res + m);
		for(int i=0;i<m;i++) printf("%d\n", res[i]);
	}
    return 0;
}
