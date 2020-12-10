lld Mod;

struct Matrix_t {
#define N 3
	int d[N][N];
	Matrix_t() {
		memset(d, 0, sizeof(d));
	}

	Matrix_t operator * (const Matrix_t &oth) {
		Matrix_t ret;
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					ret.d[i][j] += (lld)(d[i][k]) * d[k][j] % Mod;
					if (ret.d[i][j] >= Mod) {
						ret.d[i][j] -= Mod;
					}
				}
			}
		}
		return ret;
	}
#undef N
};
