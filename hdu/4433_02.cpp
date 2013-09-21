#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REP(i,a,n) for(int i = (a); i < (n); ++i)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>0?(a):(-(a)))
template<typename T>
void Swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}


int db[1000][1000];

void init() {
	int t;
	//转动一位情况下  从i转到j的最少步数
	REP(i, 0, 10) REP(j, 0, 10) {
		t = i - j;
		if(t < 0) t += 10;
		db[i][j] = MIN(t, 10 - t);
	}
	//转动两位情况下  从i转到j的最少步数
	REP(i, 00, 100) REP(j, 00, 100) {
		if(i < 10 && j < 10) continue;
		t = j / 10 - i / 10;
		if(t < 0) t += 10;
		db[i][j] = MIN(t, 10 - t) + db[(i % 10 + t) % 10][j % 10];
	}
	//转动三位情况下  从i转到j的最少步数
	REP(i, 0, 1000) REP(j, 0, 1000) {
		if(i < 100 && j < 100) continue;
		t = j / 100 - i / 100;
		if(t < 0) t += 10;
		int l = i % 100;
		db[i][j] = MIN(t, 10 - t) + db[((l / 10 + t) % 10) * 10 + (l % 10 + t) % 10][j % 100];
	}
}

char in[2][2000];
int len, dp[2][1000];

int solve() {
	int (*now) = dp[0], (*nxt) = dp[1];
	REP(i, 0, 1000) {
		now[i] = db[0][i];
	}
	int a = 0, b = 0, c = 0;
	REP(i, 0, len) {
		c = b / 100 * 100;
		a = (a * 10 + in[0][i]) % 1000;
		b = (b * 10 + in[1][i]) % 1000;
		REP(j, b / 100 * 100, b / 100 * 100 + 100) {
			nxt[j] = now[c] + db[in[0][i]][j];
			REP(l, 0, 100) {
				int t = now[c + l] + db[l * 10 + in[0][i]][j];
				if(t < nxt[j]) {
					nxt[j] = t;
				}
			}

		}
		Swap(now, nxt);
	}
	return now[b];
}

int main() {
	init();
	while(scanf("%s %s", in[0], in[1]) != EOF) {
		len = strlen(in[0]);
		REP(i, 0, len) {
			in[0][i] -= '0';
			in[1][i] -= '0';
		}
		printf("%d\n", solve());
	}
	return 0;
}
