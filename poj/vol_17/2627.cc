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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 1111;
typedef long long ll;
struct point {
  double x, y;
} p[maxn];
int n;
int mark[maxn];
int Q[maxn];

int main() {
	double v, t;
	scanf("%lf %lf", &v, &t);
	scanf("%lf %lf %lf %lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y);
	n = 2;		
	while (~scanf("%lf %lf", &p[n].x, &p[n].y)) ++n;		
	t *= v * 60; t *= t;
	memset(mark, 0, sizeof mark);
	mark[0] = 1;
	int l = 0, h = 0;
	Q[h++] = 0;
	int ret = -1;
	while (l < h) {
		int now = Q[l++];
		if (now == 1) {
			ret = mark[now] - 2;
			break;
		}	
		for (int i = 1; i < n; ++i) {
			if (mark[i] > 0) continue;
			if ((p[i].x - p[now].x) * (p[i].x - p[now].x) + 
				(p[i].y - p[now].y) * (p[i].y - p[now].y) <= t) {
				mark[i] = mark[now] + 1;
				Q[h++] = i;
			}
		}
	}
	if (ret == -1) puts("No.");
	else printf("Yes, visiting %d other holes.\n", ret);
		
    return 0;
}
