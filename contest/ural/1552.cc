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
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
int const N = 51, M = 27;
char s[N]; int S[N];
int f[N][4][M][M][M];
int g[N][4][M][M][M][6];
char O[N<<10];
int n, pos, w, c;
vector <PII> v;
PII p[4]; 

int const cd[4][3] = { { 1, 2, 3 }, { 0, 2, 3 }, { 0, 1, 3 }, { 0, 1, 2 } };
inline void upd(int c, int r, int s, int e, int step, int add) {
	int A[3], B[3];
	for (int i = 0, j = 0; i < 4; ++i) if (p[i].first != s) A[j++] = p[i].second;
	for (int i = 0, j = 0; i < 4; ++i) if (p[i].first != e) B[j++] = p[i].second;
	
	if (c < f[r+1][e][B[0]][B[1]][B[2]]) {
		f[r+1][e][B[0]][B[1]][B[2]] = c;
		g[r+1][e][B[0]][B[1]][B[2]][0] = s;
		for (int j = 1; j <= 3; ++j) g[r+1][e][B[0]][B[1]][B[2]][j] = A[j-1];
		g[r+1][e][B[0]][B[1]][B[2]][4] = step;
		g[r+1][e][B[0]][B[1]][B[2]][5] = add;
	}
}

int main() {
	n = strlen(gets(s)); REP(i, n) S[i + 1] = s[i] - 'a';
	memset(f, 0x3f, sizeof f); 
	f[0][1][M-1][M-1][M-1] = 'a'; 
	REP(i, n) REP(now, 4) REP(j, 27) REP(k, 27) REP(l, 27) if ((w = f[i][now][j][k][l]) != inf) {
		p[0] = MP(now, S[i]), p[1] = MP(cd[now][0], j), p[2] = MP(cd[now][1], k), p[3] = MP(cd[now][2], l);
		sort(p, p + 4);
		//stay
		c = S[i+1] - S[i]; 
		upd(w+abs(c), i, now, now, 0, i == 0 ? 'a' + c : c);
		//to(j)
		if (j == 26) c = 'a'+S[i+1]; else c = S[i+1]-j;
		upd(w+abs(c)+abs(now-cd[now][0]), i, now, cd[now][0], cd[now][0]-now, c);
		//to(k)
		if (k == 26) c = 'a'+S[i+1]; else c = S[i+1]-k;
		upd(w+abs(c)+abs(now-cd[now][1]), i, now, cd[now][1], cd[now][1]-now, c);
		//to(l)
		if (l == 26) c = 'a'+S[i+1]; else c = S[i+1]-l;
		upd(w+abs(c)+abs(now-cd[now][2]), i, now, cd[now][2], cd[now][2]-now, c);
	}
	int ret = inf, rR = n, rNOW, rJ, rK, rL;
	REP(now, 4) REP(j, 27) REP(k, 27) REP(l, 27) if (f[n][now][j][k][l] < ret) {
		ret = f[n][now][j][k][l];
		rNOW = now, rJ = j, rK = k, rL = l;
	}
	int top = 0, tNOW, tJ, tK, tL, tS, tA;
	while (rR != 0) {
		tNOW = g[rR][rNOW][rJ][rK][rL][0];
		tJ = g[rR][rNOW][rJ][rK][rL][1];
		tK = g[rR][rNOW][rJ][rK][rL][2];
		tL = g[rR][rNOW][rJ][rK][rL][3];
		tS = g[rR][rNOW][rJ][rK][rL][4];
		tA = g[rR][rNOW][rJ][rK][rL][5];
		O[top++] = '.';
		if (tA > 0) while (tA--) O[top++] = '+';
		else if (tA < 0) while (tA++) O[top++] = '-';
		if (tS > 0) while (tS--) O[top++] = '>';
		else if (tS < 0) while (tS++) O[top++] = '<';
		--rR, rNOW = tNOW, rJ = tJ, rK = tK, rL = tL;
	}
	for (int i = top - 1; ~i; --i) putchar(O[i]); puts("");
	
	return 0;
}

