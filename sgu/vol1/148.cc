#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 15151;
typedef long long ll;

struct node {
	int v, p, id;
	node (int v, int p, int id) : v(v), p(p), id(id) { }
	node () { }
	friend bool operator < (node a, node b) {
		return a.v < b.v;
	}
} tmp;

priority_queue <node> q;
int a[maxn], b[maxn], c[maxn];
int s[maxn];

int main() {
	int n;	
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
		s[n] = 0;
		for (int i = n - 1; i >= 0; --i) s[i] = s[i + 1] + a[i];
		
		while (!q.empty()) q.pop();
		int ret = inf, rc = -1;
		int now = 0, add = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] <= b[i]) {
				now += c[i];
				add += a[i];
				while (!q.empty()) {
					tmp = q.top(); 
					if (tmp.v + add > 0) {
						q.pop();
						now -= tmp.p;
					}
					else break;
				}
				q.push(node(a[i] - b[i] - add, c[i], i));
			}
			else {
				add += a[i];
				while (!q.empty()) {
					tmp = q.top(); 
					if (tmp.v + add > 0) {
						q.pop();
						now -= tmp.p;
					}
					else break;
				}
			}
			if (now < ret) {
				ret = now;
				rc = i;
			}
		}
		now = 0;
		for (int i = rc; i < n; ++i) {
			now += a[i];
			if (now <= b[i]) {
				printf("%d\n", i + 1);
			}
		}
	}
	return 0;
}

