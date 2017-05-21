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
typedef long long ll;
//int const maxn = 33, maxm = 10;
//int n, m;
//ll dp[maxn][1 << 18];
//inline int getM(int mask, int pos) { return (mask >> (pos << 1)) & 3; }
//inline void setM(int &mask, int pos, int val) { mask |= val << (pos << 1); }
//
//void dfs(int r, int mask, int now, int pos) {
  //if (pos == m) {
		//dp[r][now] += dp[r - 1][mask];
		//return;
	//}
	//int m1 = getM(mask, pos);
	//if (pos + 3 <= m) {
		//int m2 = getM(mask, pos + 1);
		//int m3 = getM(mask, pos + 2);
		//if (m1 == 0 && m2 == 0 && m3 == 0) {
			//dfs(r, mask, now, pos + 3);
		//}
	//}
	//if (m1 == 0) {
		//int tm = now;
		//setM(tm, pos, 2);
		//dfs(r, mask, tm, pos + 1);
	//}
	//else if (m1 == 1) {
		//dfs(r, mask, now, pos + 1);
	//}
	//else {
		//int tm = now;
		//setM(tm, pos, 1);
		//dfs(r, mask, tm, pos + 1);
	//}
//}
//ll cal(int n, int m) {
	//memset(dp, 0, sizeof dp);
	//dp[0][0] = 1;
	//int mx = 1 << (m + m);
	//for (int i = 1; i <= n; ++i) {
		//for (int j = 0; j < mx; ++j) {
			//if (dp[i - 1][j] > 0) {
				//dfs(i, j, 0, 0);
			//}
		//}
	//}
	//ll ret = dp[n][0];
	//return ret;
//}
ll ans[10][33] = {
{0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1},
{0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1},
{1,1,2,3,4,6,9,13,19,28,41,60,88,129,189,277,406,595,872,1278,1873,2745,4023,5896,8641,12664,18560,27201,39865,58425},
{0,0,3,0,0,13,0,0,57,0,0,249,0,0,1087,0,0,4745,0,0,20713,0,0,90417,0,0,394691,0,0,1722917},
{0,0,4,0,0,22,0,0,121,0,0,664,0,0,3643,0,0,19987,0,0,109657,0,0,601624,0,0,3300760,0,0,18109345},
{1,1,6,13,22,64,155,321,783,1888,4233,9912,23494,54177,126019,295681,687690,1600185,3738332,8712992,20293761,47337405,110368563,257206012,599684007,1398149988,3259051800,7597720649,17712981963,41291922001},
{0,0,9,0,0,155,0,0,2861,0,0,52817,0,0,972557,0,0,17892281,0,0,329097125,0,0,6052932495,0,0,111328274273,0,0,2047599783121},
{0,0,13,0,0,321,0,0,8133,0,0,204975,0,0,5158223,0,0,129777789,0,0,3265058453,0,0,82145028215,0,0,2066672862247,0,0,51995077201711},
{1,1,19,57,121,783,2861,8133,37160,143419,468816,1876855,7263468,25496863,97187247,372086645,1352780401,5071962134,19220628318,71025008365,265095817718,997839772024,3713274525679,13851695644227,51940567251136,193830054345968,723361116637203,2707160075336397,10112661751221423,37758603187152493}	
};
int main() {
	//freopen("e.in", "w", stdout);
	//for (int i = 1; i <= 9; ++i) {
		//printf("{");
		//for (int j = 1; j <= 30; ++j) {
			//n = j, m = i;
			//printf("%lld", cal(j,i));
			//if (j != 30) putchar(',');
		//}
		//puts("},");
	//}
	//return 0;
	int n, m;
	while (~scanf("%d%d", &m, &n)) {
		if (n == 0 && m == 0) break;
		printf("%lld\n", ans[m - 1][n - 1]);
	}
    return 0;
}
