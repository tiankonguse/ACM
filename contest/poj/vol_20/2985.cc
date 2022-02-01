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
#define maxn 200200
using namespace std;
struct BinaryIndexTree{
  int num[maxn];
	void init(){
		memset(num, 0, sizeof(num));
	}
	inline int lowbit(int x){
		return x & -x;
	}
	void update(int p, int c){
		while(p < maxn){
			num[p] += c;
			p += lowbit(p);
		}
	}
	int query(int p){
		int r = 0;
		while(p > 0){
			r += num[p];
			p -= lowbit(p);
		}
		return r;
	}
	int find_kth(int k){
		int now = 0;
		for(int i=20;i>=0;i--){
			now |= (1 << i);
			if(now >= maxn || num[now] >= k){
				now ^= (1 << i);
			}
			else k -= num[now];
		}
		return now + 1;
	}
}bit;
int parents[maxn];
int Find(int a){
	return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a, int b){
	if(parents[a] < parents[b]){
		parents[a] += parents[b];
		parents[b] = a;
	}
	else{
		parents[b] += parents[a];
		parents[a] = b;
	}
}

int main(){
	int n, m, s, c, a, b, ra, rb, ca, cb;
	while(~scanf("%d%d", &n, &m)){
		memset(parents, 0xff, sizeof(parents));
		bit.init();
		bit.update(1, n);
		s = n;
		for(int i=0;i<m;i++) {
			scanf("%d", &c);
			if(c == 0) {
				scanf("%d%d", &a, &b);
				ra = Find(a);
				rb = Find(b);
				ca = -parents[ra];
				cb = -parents[rb];
				if(ra != rb) {
					Union(ra, rb);
					bit.update(ca, -1);
					bit.update(cb, -1);
					bit.update(ca + cb, 1);
					s--;
				}	
			}
			else{
				scanf("%d", &a);
				printf("%d\n", bit.find_kth(s - a + 1));
			}
		}
	}
    return 0;
}
