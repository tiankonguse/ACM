#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int ab[4][3] = {
	17, 35, 22,
	26, 31,  4,
	 8, 27, 13,
	 0,  9, 18
};
int bb[4][3] = {
	16, 34, 23,
	25, 32,  5,
	 7, 29, 14,
	 2, 11, 20
};
int eb[6][2] = {
	28,  6,
	30, 15,
	33, 24,
	 3, 10,
	12, 19,
	21,  1
};
int fb[4][3] = {
	 2,  5,  7,
	11, 14, 16,
	20, 23, 25
};
int rl[4][3] = {
	12, 30, 24,
	21, 33,  6,
	 3, 28, 15,
	 1, 10, 19
};
int rr[4][3] = {
	15, 33, 19,
	24, 28,  1,	
	 6, 30, 10,
	 3, 12, 21
};

int c[40], fc[4];
vector<string> step;

void swap(int x, int y, int z) {
	swap(c[x], c[y]);
	swap(c[x], c[z]);
}

void rotate(char t, int v, char d, bool pb = true) {
	swap(ab[v][0], ab[v][1], ab[v][2]);
	if (t == 'B') {
		swap(bb[v][0], bb[v][1], bb[v][2]);
		swap(rl[v][0], rl[v][1], rl[v][2]);
		swap(rr[v][0], rr[v][1], rr[v][2]);
	}
	if (d == 'W') rotate(t, v, 'C', false);
	if (!pb) return ;
	char str[10];
	sprintf(str, "%c%d%c", t, v+1, d);
	step.push_back(str);
}

bool check_angle(int v) {
	for (int i = 0; i < 3; ++i) {
		if (c[ab[v][i]] != c[bb[v][i]]) return false;
	}
	return true;
}

bool check_edge_left(int v) {
	v = (v + 2) % 3 + 3;
	return c[eb[v][1]] == fc[v] && c[eb[v][0]] == fc[3];
}

bool check_edge_right(int v) {
	return c[eb[v+3][0]] == fc[v] && c[eb[v+3][1]] == fc[3];
}

bool check_edge_upper(int v) {
	return c[eb[v+3][0]] == fc[v] && c[eb[v+3][1]] == fc[(v+1)%3];
}

bool check_base_lower(int v) {
	return c[bb[v][1]] == fc[3];
}

bool check_base_upper() {
	for (int i = 0; i < 3; ++i) {
		if (c[bb[3][i]] != fc[i]) return false;
	}
	return true;
}

bool gao() {
	int color_cnt[4] = {};
	for (int i = 0; i < 36; ++i) ++color_cnt[--c[i]];
	for (int i = 0; i < 4; ++i) {
		if (color_cnt[i] != 9) return false;
	}
	// Small rotation
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3 && !check_angle(i); ++j) {
			rotate('S', i, 'C');
		}
		if (!check_angle(i)) return false;
	}
	// Big rotation
	//// gao the base blocks of 4th face
	int f4c = 15; // 0b1111
	for (int i = 0; i < 3; ++i) {
		int ci = 0;
		for (int j = 0; j < 3; ++j) {
			ci |= 1 << c[bb[i][j]];
		}
		if (__builtin_popcount(ci) != 3) return false;
		f4c &= ci;
	}
	if (__builtin_popcount(f4c) != 1) return false;
	for (int i = 1; i <= 4; ++i) {
		if (f4c & 1 << i) {
			fc[3] = i;
			break;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3 && !check_base_lower(i); ++j) {
			rotate('B', i, 'C');
		}
		if (!check_base_lower(i)) return false;
	}
	//// gao the edge blocks of 4th face
	for (int i = 0; i < 3; ++i) {
		if (c[fb[i][1]] != c[fb[i][2]]) return false;
		fc[i] = c[fb[i][1]];
		if (c[eb[i][0]] == fc[3] && c[eb[i][1]] == fc[i]) continue;
		for (int j = 0; j < 3; ++j) {
			if (c[eb[j][0]] == fc[3] && c[eb[j][1]] == fc[i]) {
				rotate('B', (j+1)%3, 'C');
				rotate('B', 3, 'C');
				rotate('B', (j+1)%3, 'W');
				break;
			} else if (c[eb[j][1]] == fc[3] && c[eb[j][0]] == fc[i]) {
				rotate('B', (j+2)%3, 'W');
				rotate('B', 3, 'W');
				rotate('B', (j+2)%3, 'C');
				break;
			}
		}
		for (int j = 0; j < 3 && !check_edge_left(i); ++j) {
			rotate('B', 3, 'C');
		}
		if (check_edge_left(i)) {
			rotate('B', (i+2)%3, 'W');
			rotate('B', 3, 'C');
			rotate('B', (i+2)%3, 'C');
			continue;
		}
		for (int j = 0; j < 3 && !check_edge_right(i); ++j) {
			rotate('B', 3, 'C');
		}
		if (check_edge_right(i)) {
			rotate('B', (i+1)%3, 'C');
			rotate('B', 3, 'W');
			rotate('B', (i+1)%3, 'W');
			continue;
		}
		return false;
	}
	// for now, lowest level is done!
	//// gao the upper 3 edge blocks
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3 && !check_edge_upper(i); ++j) {
			rotate('B', 3, 'C');
		}
		if (check_edge_upper(i)) {
			int j = (i + 1) % 3;
			if (!check_edge_upper(j)) {
				rotate('B', j, 'C');
				rotate('B', 3, 'W');
				rotate('B', i, 'C');
				rotate('B', 3, 'C');
				rotate('B', i, 'W');
				rotate('B', 3, 'C');
				rotate('B', j, 'W');
				rotate('B', 3, 'W');
			}
			break;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (!check_edge_upper(i)) return false;
	}
	//// check upper base blocks
	for (int i = 0; i < 3 && !check_base_upper(); ++i) {
		rotate('B', 2, 'C');
		rotate('B', 3, 'C');
		rotate('B', 2, 'W');
		rotate('B', 3, 'C');
		rotate('B', 2, 'C');
		rotate('B', 3, 'C');
		rotate('B', 2, 'W');
		rotate('B', 3, 'C');
	}
	if (!check_base_upper()) return false;
	for (int i = 0; i < 36; ++i) {
		if (c[i] != fc[i / 9]) return false;
	}
	return true;
}

int main() {
	freopen("pyraminx.in", "r", stdin);
	freopen("pyraminx.out","w", stdout);
	for (int i = 0; i < 36; ++i) scanf("%d", c + i);
	if (gao()) {
		for (int i = 0; i < step.size(); ++i) {
			puts(step[i].c_str());
		}
	} else {
		puts("Impossible");
	}
}